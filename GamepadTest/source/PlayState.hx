package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.util.FlxColor;
import flixel.util.FlxPoint;
import flixel.input.gamepad.FlxGamepad;
import flixel.input.gamepad.XboxButtonID;
import flixel.input.gamepad.OUYAButtonID;
import flixel.system.FlxSound;
import openfl.display.BitmapData;
import openfl.media.Sound;
import flixel.text.FlxText;
import Globals;

class PlayState extends FlxState
{
	private static inline var STICK_MOVEMENT_RANGE:Float = 10;
	private static inline var TRIGGER_MOVEMENT_RANGE:Float = 10;
	
	private static inline var ALPHA_OFF:Float = 0.5;
	private static inline var ALPHA_ON:Float = 1;
	
	private static inline var LB_Y:Float = 2;
	private static inline var RB_Y:Float = 2;
	
	private static var LEFT_STICK_POS:FlxPoint = FlxPoint.get(80, 48);
	private static var RIGHT_STICK_POS:FlxPoint = FlxPoint.get(304, 136);
	private static var LEFT_TRIGGER_POS:FlxPoint = FlxPoint.get(71, 15);
	private static var RIGHT_TRIGGER_POS:FlxPoint = FlxPoint.get(367, 15);
	
	private var _controllerBg:FlxSprite;
	private var _leftStick:FlxSprite;
	private var _rightStick:FlxSprite;
	private var _dPad:FlxSprite;
	private var _leftTrigger:FlxSprite;
	private var _rightTrigger:FlxSprite;
	
	private var _xButton:FlxSprite;
	private var _yButton:FlxSprite;
	private var _aButton:FlxSprite;
	private var _bButton:FlxSprite;
	
	private var _backButton:FlxSprite;
	private var _startButton:FlxSprite;
	
	private var _LB:FlxSprite;
	private var _RB:FlxSprite;
	private var _gamePad:FlxGamepad;
	
	private var _hitText:FlxText;
	private var _missText:FlxText;
	
	private var _music:FlxSound;
	private var _musicBPM:Float;
	private var _musicLength:Float;
	private var _beatDelay:Float;
	private var _beatDelta:Float;
	private var _beatAcceptance:Float;
	private var _beatInterval:Float;
	private var _onBeat:Bool = false;
	private var _currentBeatLock:Bool = false;
	
	private var _controllableChar:FlxSprite;
	private var _inputHandler:InputHandler;
	private var _xboxController:XBoxControllerEntity;

	override public function create():Void 
	{
		_inputHandler = new InputHandler();
		_controllableChar = new FlxSprite(0, 0, new BitmapData(10, 10, false, 0x000000));
		_music = FlxG.sound.load("assets/sounds/classic.ogg", 1, true, false, true);
		_musicBPM = 140;
		_musicLength = _music._sound.length;
		trace("Length: " + _musicLength);
		_beatInterval = (60 / 140) * 1000;
		_beatDelta = _beatInterval / 10;
		_beatAcceptance = _beatDelta * 5;
		_beatDelay = 28.0;
		_onBeat = false;
		_currentBeatLock = false;
		trace(_beatInterval);
		
		
		FlxG.mouse.visible = false;
		FlxG.cameras.bgColor = FlxColor.WHITE;
		
		_xboxController = new XBoxControllerEntity(true);
		add(_xboxController.spriteGroup);
		_inputHandler.addControllableEntity("xbox_controller", _xboxController);
		
		/*
		_hitText = new FlxText(60, 100, 100, "HIT!", 20);
		_missText = new FlxText(120, 100, 100, "MISS!", 20);
		_hitText.color = 0x00FF00;
		_missText.color = 0xFF0000;
		_hitText.visible = false;
		_missText.visible = false;
		add(_hitText);
		add(_missText);
		*/
	}
	
	override public function update():Void 
	{
		super.update();
		
		_gamePad = FlxG.gamepads.lastActive;
		
		if (_gamePad == null) {
			return;
		}
		
		#if !FLX_NO_DEBUG
		FlxG.watch.addQuick("pressed ID", _gamePad.firstPressedButtonID());
		FlxG.watch.addQuick("released ID", _gamePad.firstJustReleasedButtonID());
		FlxG.watch.addQuick("justPressed ID", _gamePad.firstJustPressedButtonID());
		FlxG.watch.addQuick("HAT", _gamePad.hat);
		
		FlxG.watch.addQuick("axiz0x", _gamePad.getXAxis(0));
		FlxG.watch.addQuick("axiz0y", _gamePad.getYAxis(0));
		FlxG.watch.addQuick("axiz1x", _gamePad.getXAxis(1));
		FlxG.watch.addQuick("axiz1y", _gamePad.getYAxis(1));
		FlxG.watch.addQuick("axiz2x", _gamePad.getXAxis(2));
		FlxG.watch.addQuick("axiz2y", _gamePad.getYAxis(2));
		FlxG.watch.addQuick("axiz3x", _gamePad.getXAxis(3));
		FlxG.watch.addQuick("axiz3y", _gamePad.getYAxis(3));
		FlxG.watch.addQuick("axiz4x", _gamePad.getXAxis(4));
		FlxG.watch.addQuick("axiz4y", _gamePad.getYAxis(4));
		FlxG.watch.addQuick("axiz5x", _gamePad.getXAxis(5));
		FlxG.watch.addQuick("axiz5y", _gamePad.getYAxis(5));
		FlxG.watch.addQuick("axiz6x", _gamePad.getXAxis(6));
		FlxG.watch.addQuick("axiz6y", _gamePad.getYAxis(6));
		#end
		
		_inputHandler.functionUpdateWithInput(_gamePad);
		/*
		var justReleasedID:Int = _gamePad.firstJustReleasedButtonID();
		var justPressedID:Int =  _gamePad.firstJustPressedButtonID();
		if (justPressedID != -1) {
			trace("Just Pressed: " + justPressedID);
		}
		if (justReleasedID != -1) {
			trace("Just Released: " + justReleasedID);
		}
		
		if (_gamePad.justPressed(GamepadIDs.A)) {
			_aButton.alpha = ALPHA_ON;
			
			if (_onBeat) {
				_hitText.visible = true;
				_missText.visible = false;
				_currentBeatLock = true;
			} else {
				_hitText.visible = false;
				_missText.visible = true;
			}
		} else {
			_aButton.alpha = ALPHA_OFF;
		}
		
		updateBeat();
		*/
	}
	
	private function updateBeat():Void
	{
		var currentBeatTimingValue:Float = (_music.time + _beatDelay) % _beatInterval;
		// For updating graphics to the beat
		if (currentBeatTimingValue < _beatDelta) {
			_controllerBg.y = 5.0;
		} else {
			_controllerBg.y = 0;
		}
		
		// For evaluating press precision
		if (currentBeatTimingValue < _beatAcceptance) {
			if (!_onBeat) {
				_hitText.visible = false;
				_missText.visible = false;
				_currentBeatLock = false;
			}
			_onBeat = true;
		} else {
			_onBeat = false;
			if (!_currentBeatLock) {
				// User missed the beat
				_hitText.visible = false;
				_missText.visible = true;
			}
		}
	}
	
}
