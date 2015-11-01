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

	override public function create():Void 
	{
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
		
		_LB = createSprite(71, LB_Y, "assets/images/LB.png", 0.8);
		_RB = createSprite(367, RB_Y, "assets/images/RB.png", 0.8);
		
		_controllerBg = createSprite(0, 0, "assets/images/xbox360_gamepad.png", 1);
		
		_leftTrigger = createSprite(LEFT_TRIGGER_POS.x, LEFT_TRIGGER_POS.y, "assets/images/LB.png");
		_rightTrigger = createSprite(RIGHT_TRIGGER_POS.x, RIGHT_TRIGGER_POS.y, "assets/images/RB.png");
		
		_leftStick = createSprite(LEFT_STICK_POS.x, LEFT_STICK_POS.y, "assets/images/Stick.png");
		_rightStick = createSprite(RIGHT_STICK_POS.x, RIGHT_STICK_POS.y, "assets/images/Stick.png");
		
		_dPad = new FlxSprite(144, 126);
		_dPad.loadGraphic("assets/images/DPad.png", true, 87, 87);
		_dPad.alpha = ALPHA_OFF;
		add(_dPad);
		
		_xButton = createSprite(357, 70, "assets/images/X.png");
		_yButton = createSprite(395, 34, "assets/images/Y.png");
		_aButton = createSprite(395, 109, "assets/images/A.png");
		_bButton = createSprite(433, 70, "assets/images/B.png");
		
		_backButton = createSprite(199, 79, "assets/images/Back.png");
		_startButton = createSprite(306, 79, "assets/images/Start.png");
		_startButton = createSprite(306, 79, "assets/images/Start.png");
		
		_hitText = new FlxText(60, 100, 100, "HIT!", 20);
		_missText = new FlxText(120, 100, 100, "MISS!", 20);
		_hitText.color = 0x00FF00;
		_missText.color = 0xFF0000;
		_hitText.visible = false;
		_missText.visible = false;
		add(_hitText);
		add(_missText);
		
		_startButton.alpha = ALPHA_OFF;
		_backButton.alpha = ALPHA_OFF;
	}

	private function createSprite(X:Float, Y:Float, Graphic:String, Alpha:Float = -1):FlxSprite
	{
		if (Alpha == -1)
		{
			Alpha = ALPHA_OFF;
		}
		
		var button:FlxSprite = new FlxSprite(X, Y, Graphic);
		button.alpha = Alpha;
		add(button);
		
		return button;
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
		} /*
		else if (!_currentBeatLock) {
			_aButton.alpha = ALPHA_OFF;
			if (_onBeat) {
				_hitText.visible = false;
				_missText.visible = true;
			} else {
				_hitText.visible = false;
				_missText.visible = false;
			}
		}
		*/
		
		if (_gamePad.pressed(GamepadIDs.B))
			_bButton.alpha = ALPHA_ON;
		else
			_bButton.alpha = ALPHA_OFF;
		
		if (_gamePad.pressed(GamepadIDs.X))
			_xButton.alpha = ALPHA_ON;
		else
			_xButton.alpha = ALPHA_OFF;
		
		if (_gamePad.pressed(GamepadIDs.Y))
			_yButton.alpha = ALPHA_ON;
		else
			_yButton.alpha = ALPHA_OFF;
		
		if (_gamePad.pressed(GamepadIDs.START))
			_startButton.alpha = ALPHA_ON;
		else
			_startButton.alpha = ALPHA_OFF;
		
		if (_gamePad.pressed(GamepadIDs.SELECT))
			_backButton.alpha = ALPHA_ON;
		else
			_backButton.alpha = ALPHA_OFF;
		
		if (_gamePad.pressed(GamepadIDs.LB))
			_LB.y = LB_Y + 5;
		else
			_LB.y = LB_Y;
		
		if (_gamePad.pressed(GamepadIDs.RB))
			_RB.y = RB_Y + 5;
		else
			_RB.y = RB_Y;
		
		updateAxis(GamepadIDs.LEFT_ANALOGUE_X, GamepadIDs.LEFT_ANALOGUE_Y, _leftStick, LEFT_STICK_POS);
		updateAxis(GamepadIDs.RIGHT_ANALOGUE_X, GamepadIDs.RIGHT_ANALOGUE_Y, _rightStick, RIGHT_STICK_POS);
		updateAxis(GamepadIDs.RIGHT_ANALOGUE_X, GamepadIDs.RIGHT_ANALOGUE_Y, _rightStick, RIGHT_STICK_POS);
		updateAxis(GamepadIDs.RIGHT_ANALOGUE_X, GamepadIDs.RIGHT_ANALOGUE_Y, _rightStick, RIGHT_STICK_POS);
		updateTrigger(GamepadIDs.RIGHT_TRIGGER, _rightTrigger, RIGHT_TRIGGER_POS);
		updateTrigger(GamepadIDs.LEFT_TRIGGER, _leftTrigger, LEFT_TRIGGER_POS);
		
		updateDpad();
		
		updateBeat();
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
	
	private function updateTrigger(tID:Int, triggerSprite:FlxSprite, triggerPosition:FlxPoint):Void
	{
		var tAxisValue = _gamePad.getAxis(tID);
		if (tAxisValue > -1) {
			var newYPosition = triggerPosition.y + ((tAxisValue + 1) / 2) * TRIGGER_MOVEMENT_RANGE;
			triggerSprite.y = newYPosition;
		}
	}
	
	private function updateAxis(xID:Int, yID:Int, stickSprite:FlxSprite, stickPosition:FlxPoint):Void
	{
		var xAxisValue = _gamePad.getXAxis(xID);
		var yAxisValue = _gamePad.getYAxis(yID);
		var angle:Float;
		
		if ((xAxisValue != 0) || (yAxisValue != 0))
		{
			angle = Math.atan2(yAxisValue, xAxisValue);
			stickSprite.x = stickPosition.x + (Math.abs(xAxisValue) * STICK_MOVEMENT_RANGE) * Math.cos(angle);
			stickSprite.y = stickPosition.y + (Math.abs(yAxisValue) * STICK_MOVEMENT_RANGE) * Math.sin(angle);
			stickSprite.alpha = ALPHA_ON;
		}
		else
		{
			stickSprite.x = stickPosition.x;
			stickSprite.y = stickPosition.y;
			stickSprite.alpha = ALPHA_OFF;
		}
	}
	
	private function updateDpad():Void
	{
		var dpadLeft = _gamePad.dpadLeft;//_gamePad.pressed(XboxButtonID.DPAD_LEFT);
		var dpadRight = _gamePad.dpadRight;//_gamePad.pressed(XboxButtonID.DPAD_RIGHT);
		var dpadUp = _gamePad.dpadUp;//_gamePad.pressed(XboxButtonID.DPAD_UP);
		var dpadDown = _gamePad.dpadDown;//_gamePad.pressed(XboxButtonID.DPAD_DOWN);
		var newIndex:Int = 0;
		var newAlpha:Float = ALPHA_OFF;
		
		if (dpadLeft || dpadRight || dpadUp || dpadDown)
		{
			newAlpha = ALPHA_ON;
			
			if (dpadRight && dpadUp)
				newIndex = 5;
			else if (dpadRight && dpadDown)
				newIndex = 6;
			else if (dpadLeft && dpadDown)
				newIndex = 7;
			else if (dpadLeft && dpadUp)
				newIndex = 8;
			else if (dpadUp)
				newIndex = 1;
			else if (dpadRight)
				newIndex = 2;
			else if (dpadDown)
				newIndex = 3;
			else if (dpadLeft)
				newIndex = 4;
		}
		
		_dPad.animation.frameIndex = newIndex;
		_dPad.alpha = newAlpha;
	}
}
