package;

import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.math.FlxPoint;
import flixel.text.FlxText;
import Globals;

import IBeatCapable;

/**
 * ...
 * @author DustMan
 */
 
class XBoxControllerEntity extends ControllableEntity implements IBeatCapable
{
	public var beatState:IBeatState = OUT_WINDOW;
	private var _beatLock:Bool = false;
	public var beatData(default, null):BeatData;
	
	public var spriteGroup(default, null):FlxGroup;

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
	
	private var _hitText:FlxText;
	private var _missText:FlxText;
	
	public function new(activelyControllable:Bool = false)
	{
		super(activelyControllable);
		
		spriteGroup = new FlxGroup();
		
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
		spriteGroup.add(_dPad);
		
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
		spriteGroup.add(_hitText);
		spriteGroup.add(_missText);
		
		_startButton.alpha = ALPHA_OFF;
		_backButton.alpha = ALPHA_OFF;
		
		beatState = OUT_WINDOW;
		_beatLock = false;
	}
	
	private function createSprite(X:Float, Y:Float, Graphic:String, Alpha:Float = -1):FlxSprite
	{
		if (Alpha == -1)
		{
			Alpha = ALPHA_OFF;
		}
		
		var button:FlxSprite = new FlxSprite(X, Y, Graphic);
		button.alpha = Alpha;
		spriteGroup.add(button);
		
		return button;
	}
	
	public function onEnterBeatAcceptanceWindow():Void
	{
		beatState = IN_WINDOW;
		_missText.visible = false;
	}
	
	public function onExitBeatAcceptanceWindow():Void
	{
		beatState = OUT_WINDOW;
		_hitText.visible = false;
	}
	
	public function onBeat():Void
	{
		_controllerBg.y = 5.0;
	}
	
	public function offBeat():Void
	{
		_controllerBg.y = 0.0;
	}
	
	public function onBeatDataUpdate(beatData:BeatData):Void
	{
		this.beatData = beatData;
	}
	
	override public function onPressA():Void
	{
		_aButton.alpha = ALPHA_ON;
	}
	
	override public function onJustPressedA():Void
	{
		if (beatState == IN_WINDOW) {
			_hitText.visible = true;
			_missText.visible = false;
		} else {
			_hitText.visible = false;
			_missText.visible = true;
		}
	}
	
	override public function onReleaseA():Void
	{
		_aButton.alpha = ALPHA_OFF;
	}
	
	override public function onJustReleasedA():Void
	{
		
	}
	
	override public function onPressB():Void
	{
		_bButton.alpha = ALPHA_ON;
	}
	
	override public function onReleaseB():Void
	{
		_bButton.alpha = ALPHA_OFF;
	}
	
	override public function onPressX():Void
	{
		_xButton.alpha = ALPHA_ON;
	}
	
	override public function onReleaseX():Void
	{
		_xButton.alpha = ALPHA_OFF;
	}
	
	override public function onPressY():Void
	{
		_yButton.alpha = ALPHA_ON;
	}
	
	override public function onReleaseY():Void
	{
		_yButton.alpha = ALPHA_OFF;
	}
	
	override public function onPressBack():Void
	{
		_backButton.alpha = ALPHA_ON;
	}
	
	override public function onReleaseBack():Void
	{
		_backButton.alpha = ALPHA_OFF;
	}
	
	override public function onPressStart():Void
	{
		_startButton.alpha = ALPHA_ON;
	}
	
	override public function onReleaseStart():Void
	{
		_startButton.alpha = ALPHA_OFF;
	}
	
	override public function onPressLB():Void
	{
		_LB.y = LB_Y + 5;
	}
	
	override public function onReleaseLB():Void
	{
		_LB.y = LB_Y;
	}
	
	override public function onPressRB():Void
	{
		_RB.y = RB_Y + 5;
	}
	
	override public function onReleaseRB():Void
	{
		_RB.y = RB_Y;
	}
	
	override public function onLeftTrigger(axisValue:Float):Void
	{		
		if (axisValue > -1) {
			var newYPosition = LEFT_TRIGGER_POS.y + ((axisValue + 1) / 2) * TRIGGER_MOVEMENT_RANGE;
			_leftTrigger.y = newYPosition;
		}
	}
	
	override public function onRightTrigger(axisValue:Float):Void
	{		
		if (axisValue > -1) {
			var newYPosition = RIGHT_TRIGGER_POS.y + ((axisValue + 1) / 2) * TRIGGER_MOVEMENT_RANGE;
			_rightTrigger.y = newYPosition;
		}
	}
	
	override public function onLeftAnalogue(xAxisValue:Float, yAxisValue:Float):Void
	{
		updateAnalogue(_leftStick, LEFT_STICK_POS, xAxisValue, yAxisValue);
	}
	
	override public function onRightAnalogue(xAxisValue:Float, yAxisValue:Float):Void
	{
		updateAnalogue(_rightStick, RIGHT_STICK_POS, xAxisValue, yAxisValue);
	}
	
	private function updateAnalogue(analogueSprite:FlxSprite, spritePosition:FlxPoint, xAxisValue:Float, yAxisValue:Float):Void
	{
		var angle:Float;
		
		if ((xAxisValue != 0) || (yAxisValue != 0))
		{
			angle = Math.atan2(yAxisValue, xAxisValue);
			analogueSprite.x = spritePosition.x + (Math.abs(xAxisValue) * STICK_MOVEMENT_RANGE) * Math.cos(angle);
			analogueSprite.y = spritePosition.y + (Math.abs(yAxisValue) * STICK_MOVEMENT_RANGE) * Math.sin(angle);
			analogueSprite.alpha = ALPHA_ON;
		}
		else
		{
			analogueSprite.x = spritePosition.x;
			analogueSprite.y = spritePosition.y;
			analogueSprite.alpha = ALPHA_OFF;
		}
	}
	
	override public function onDpad(dpadLeft:Bool, dpadRight:Bool, dpadUp:Bool, dpadDown:Bool):Void
	{
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