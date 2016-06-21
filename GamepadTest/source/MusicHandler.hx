package;

import flixel.FlxG;
import flixel.system.FlxSound;
/**
 * ...
 * @author DustMan
 */
typedef SongData =
{
	var song:FlxSound;
	var bpm:Int;
	var path:String;
}

class MusicHandler
{
	private var _beatCapableObjects:Array<IBeatCapable>;
	private var _songs:Map<String, SongData>;
	private var _songIdMap:Map<Int, String>;
	private var _currentSongId:Int;
	
	private var _music:FlxSound;
	private var _musicBPM:Float;
	private var _musicLength:Float;
	private var _beatDelay:Float;
	private var _beatDelta:Float;
	private var _beatAcceptance:Float;
	private var _beatInterval:Float;
	private var _beatSubdivisions:Float;
	private var _beatCounter:Int = 1;
	
	private var _enteredBeatAcceptanceWindow:Bool = false;
	private var _exitedBeatAcceptanceWindow:Bool = false;
	
	public function new() 
	{
		_beatCapableObjects = [];
		_songs = new Map<String, SongData>();
		_songIdMap = new Map<Int, String>();
		_currentSongId = 0;
		
		var song1:FlxSound = FlxG.sound.load("assets/sounds/classic.ogg", 1, true);
		var song2:FlxSound = FlxG.sound.load("assets/sounds/gamebeat.ogg", 1, true);
		var song3:FlxSound = FlxG.sound.load("assets/sounds/racing.ogg", 1, true);
		var song4:FlxSound = FlxG.sound.load("assets/sounds/ballroomcoy.ogg", 1, true);
		var song5:FlxSound = FlxG.sound.load("assets/sounds/smooth.ogg", 1, true);
		
		_songs.set("classic", { song:song1, bpm:140, path:"assets/sounds/classic.ogg" } );
		_songs.set("gamebeat", { song:song2, bpm:140, path:"assets/sounds/gamebeat.ogg" } );
		_songs.set("racing", { song:song3, bpm:200, path:"assets/sounds/racing.ogg" } );
		_songs.set("ballroomcoy", { song:song4, bpm:100, path:"assets/sounds/ballroomcoy.ogg" } );
		_songs.set("smooth", { song:song5, bpm:100, path:"assets/sounds/smooth.ogg" } );
		
		_songIdMap.set(1, "classic");
		_songIdMap.set(2, "gamebeat");
		_songIdMap.set(3, "racing");
		_songIdMap.set(4, "ballroomcoy");
		_songIdMap.set(5, "smooth" );
		// racing
		//_musicBPM = 200;
		// classic and gamebeat
		//_musicBPM = 140;
		// smooth and ballroomcoy

	}
	
	private function setupAndPlaySong(songName:String):Void
	{
		var sd:SongData = _songs[songName];
		
		_musicBPM = sd.bpm;
		_musicLength = sd.song.getLength();
		trace("Length: " + _musicLength);
		_beatSubdivisions = 4.0;
		_beatInterval = (60 / _musicBPM) * 1000;
		_beatDelta = _beatInterval / 10;
		_beatAcceptance = (_beatDelta * 5);
		_beatDelay = 28.0;
		trace(_beatInterval);
		_songs[songName].song.play();
	}
	
	private function stopCurrentSong():Void
	{
		if (_currentSongId != 0) {
			_songs[_songIdMap[_currentSongId]].song.stop();
		}
	}
	
	public function addBeatCapableObject(object:IBeatCapable):Void
	{
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
		var currentBeatTimingValue:Float = (song.time + _beatDelay) % (_beatInterval);
		// For updating graphics to the beat
		if (currentBeatTimingValue < _beatDelta) {
			for (object in _beatCapableObjects) {
				object.onBeat();
			}
		} else {
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