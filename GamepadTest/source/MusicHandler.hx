package;

import flixel.FlxG;
import flixel.system.FlxSound;
/**
 * ...
 * @author DustMan
 */
class MusicHandler
{
	private var _beatCapableObjects:Array<IBeatCapable>;
	private var _songs:Map<String, { bpm: Int, path: String }>;
	
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
		_songs = new Map();
		
		//_music = FlxG.sound.load("assets/sounds/classic.ogg", 1, true, false, true);
		_music = FlxG.sound.load("assets/sounds/gamebeat.ogg", 1, true, false, true);
		//_music = FlxG.sound.load("assets/sounds/racing.ogg", 1, true, false, true);
		//_music = FlxG.sound.load("assets/sounds/ballroomcoy.ogg", 1, true, false, true);
		//_music = FlxG.sound.load("assets/sounds/smooth.ogg", 1, true, false, true);
		_musicBPM = 140;
		_musicLength = _music.getLength();
		trace("Length: " + _musicLength);
		_beatSubdivisions = 4.0;
		_beatInterval = (60 / _musicBPM) * 1000;
		_beatDelta = _beatInterval / 10;
		_beatAcceptance = (_beatDelta * 5);
		_beatDelay = 28.0;
		trace(_beatInterval);
	}
	
	public function addBeatCapableObject(object:IBeatCapable):Void
	{
		_beatCapableObjects.push(object);
	}
	
	public function addSong(name:String, bpm:Int, path:String):Void
	{
		_songs.set(name, { bpm: bpm, path: path } );
	}
	
	/* Put this in the games main loop! */
	public function update():Void
	{
		var currentBeatTimingValue:Float = (_music.time + _beatDelay) % (_beatInterval);
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