package;

import IBeatCapable;
import flixel.FlxG;
import flixel.system.FlxSound;
/**
 * ...
 * @author DustMan
 */
typedef MusicData =
{
	var song:FlxSound;
	var bpm:Int;
	var path:String;
}

class MusicHandler
{
	// Constants
	private static inline var SIXTEENTH:Float = 4.0;
	private static inline var TRIPLET_QUARTER:Float = 3.0;
	private static inline var EIGHTH:Float = 2.0;
	private static inline var TRIPLET_EIGHTH:Float = 1.5;
	private static inline var QUARTER:Float = 1.0;
	
	private var _beatCapableObjects:Array<IBeatCapable> = null;
	private var _songs:Map<String, MusicData> = null;
	private var _songIdMap:Map<Int, String> = null;
	private var _currentSongId:Int = 0;
	
	private var _music:FlxSound = null;
	private var _musicBPM:Float = 0.0;
	private var _musicLength:Float = 0.0;
	private var _beatDelay:Float = 0.0;
	private var _beatDelta:Float = 0.0;
	private var _beatAcceptance:Float = 0.0;
	private var _beatInterval:Float = 0.0;
	private var _beatSubdivision:Float = QUARTER;
	private var _beatCounter:Int = 1;
	private var _beatDone:Bool = false;
	
	private var _enteredBeatAcceptanceWindow:Bool = false;
	private var _exitedBeatAcceptanceWindow:Bool = false;
	
	public function new() 
	{
		_beatCapableObjects = [];
		_songs = new Map<String, MusicData>();
		_songIdMap = new Map<Int, String>();
		_currentSongId = 0;
		_beatSubdivision = QUARTER;
		
		var song1:FlxSound = FlxG.sound.load("assets/sounds/classic.ogg", 1, true);
		var song2:FlxSound = FlxG.sound.load("assets/sounds/racing.ogg", 1, true);
		var song3:FlxSound = FlxG.sound.load("assets/sounds/ballroomcoy.ogg", 1, true);
		var song4:FlxSound = FlxG.sound.load("assets/sounds/gamebeat.ogg", 1, true);
		var song5:FlxSound = FlxG.sound.load("assets/sounds/smooth.ogg", 1, true);
		
		_songs.set("classic", { song:song1, bpm:140, path:"assets/sounds/classic.ogg" } );
		_songs.set("racing", { song:song2, bpm:200, path:"assets/sounds/racing.ogg" } );
		_songs.set("ballroomcoy", { song:song3, bpm:100, path:"assets/sounds/ballroomcoy.ogg" } );
		_songs.set("gamebeat", { song:song4, bpm:140, path:"assets/sounds/gamebeat.ogg" } );
		_songs.set("smooth", { song:song5, bpm:100, path:"assets/sounds/smooth.ogg" } );
		
		_songIdMap.set(1, "classic");
		_songIdMap.set(2, "racing");
		_songIdMap.set(3, "ballroomcoy");
		_songIdMap.set(4, "gamebeat");
		_songIdMap.set(5, "smooth" );
		// racing
		//_musicBPM = 200;
		// classic and gamebeat
		//_musicBPM = 140;
		// smooth and ballroomcoy

	}
	
	private function setBeatSubdivision(subdivision:Float):Void
	{
		_beatSubdivision = subdivision;
	}
	
	private function setupAndPlaySong(songName:String):Void
	{
		var sd:MusicData = _songs[songName];
		
		_musicBPM = sd.bpm;
		_musicLength = sd.song.getLength();
		trace("Length: " + _musicLength);

		// Determines how the beat is subdivided. See 'Subdivision' enum above.
		_beatSubdivision = QUARTER;

		// The beat interval is the number of milliseconds that pass between beats in a song. Multiply by 1000 because the sound API can provide
		// us the time a song has been playing in milliseconds. Using the ol' chemistry conversion techniques:
		// (x beats / 1 minute) * (1 minute / 60 seconds) = ((x/60) beats / second) = (1 second / (x/60) beats) = (60 seconds / x beats)
		//
		// So the time interval (in seconds) between beats is the amount of seconds in a minute divided by the number of beats per minute,
		// which makes sense since 60 bpm means 1 second betwen beats, 120 bpm is .5 seconds between beats. Multiply by 1000 to get the milliseconds.
		_beatInterval = (60 / _musicBPM) * 1000;

		// The beat delta is the window of time that we can consider "on" the beat. In theory it should be just a single moment in time,
		// but in reality it has to be lenient due to possible fluctuations in the framerate. If the framerate dropped too low, and the "on beat"
		// was just a single moment per beat, then we would most likely drop beats.
		_beatDelta = 75;//; _beatInterval / 10;

		// The beat acceptance is the windows of time we allow for action to be "on" the beat. To be used for evaluating user input.
		_beatAcceptance = (_beatDelta * 5);

		// The beat delay is an offset to the actual beat, to take into account lagtime due to external factors. Should make this variable rather
		// that hardcoded
		_beatDelay = 28.0;

		trace(_beatInterval);
		
		for (object in _beatCapableObjects) {
			object.onBeatDataUpdate({ beatInterval: _beatInterval });
		}
		_songs[songName].song.play();
	}
	
	private function stopCurrentSong():Void
	{
		if (_currentSongId != 0) {
			_songs[_songIdMap[_currentSongId]].song.stop();
		}
	}
	
	public function getBeatInterval():Float
	{
		return _beatInterval;
	}
	
	public function addBeatCapableObject(object:IBeatCapable):Void
	{
		object.onBeatDataUpdate({ beatInterval: _beatInterval });
		_beatCapableObjects.push(object);
	}
	
	public function addSong(name:String, bpm:Int, path:String):Void
	{
		//_songs.set(name, { bpm: bpm, path: path } );
	}
	
	public function cycleSong():Void
	{
		stopCurrentSong();
		++_currentSongId;
		if (_currentSongId > 5) {
			_currentSongId = 1;
		}
		setupAndPlaySong(_songIdMap[_currentSongId]);
	}
	
	/* Put this in the games main loop! */
	public function update():Void
	{
		if (_currentSongId == 0) {
			return;
		}
		var song:FlxSound = _songs[_songIdMap[_currentSongId]].song;
		
		// The 'time' property gives us the position we're at within a song in milliseconds.
		// Use the interval we calculated initially to determine if we're on the beat or not.
		var currentBeatTimingValue:Float = (song.time) % (_beatInterval / _beatSubdivision);
		// For updating graphics to the beat
		if (currentBeatTimingValue < _beatDelta) {
			// Ensure that the callback is execute only once per beat
			if (!_beatDone) {
				_beatDone = true;
				for (object in _beatCapableObjects) {
					object.onBeat();
				}
			}
		} else {
			_beatDone = false;
			for (object in _beatCapableObjects) {
				object.offBeat();
			}
		}
		
		// For evaluating press precision
		if (currentBeatTimingValue < _beatAcceptance) {
			_exitedBeatAcceptanceWindow = false;
			if (!_enteredBeatAcceptanceWindow) {
				_enteredBeatAcceptanceWindow = true;	
				for (object in _beatCapableObjects) {
					object.onEnterBeatAcceptanceWindow();
				}
			}	
		} else {
			_enteredBeatAcceptanceWindow = false;
			if (!_exitedBeatAcceptanceWindow) {
				_exitedBeatAcceptanceWindow = true;
				for (object in _beatCapableObjects) {
					object.onExitBeatAcceptanceWindow();
				}
			}
		}
	}
	
}