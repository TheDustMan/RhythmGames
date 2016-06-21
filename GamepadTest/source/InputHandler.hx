package;

import flixel.input.gamepad.FlxGamepad;
import flixel.input.gamepad.FlxGamepadInputID;
import flixel.FlxG;
/**
 * ...
 * @author DustMan
 */
class InputHandler
{
	private var _controllableEntities:Map<String, IControllable>;
	private var _gamePad:FlxGamepad;
	
	public function new() 
	{
		_controllableEntities = new Map();
	}
	
	public function addControllableEntity(name:String, controllableEntity:IControllable, isActivelyControllable:Bool = false):Void
	{
		_controllableEntities.set(name, controllableEntity);
	}
	
	public function removeControllableEntity(name:String):Void
	{
		_controllableEntities.remove(name);
	}
	
	public function functionUpdateWithInput():Void
	{
		_gamePad = FlxG.gamepads.lastActive;
		
		if (_gamePad == null) {
			return;
		}
		
		#if !FLX_NO_DEBUG
		FlxG.watch.addQuick("pressed ID", _gamePad.firstPressedID());
		FlxG.watch.addQuick("released ID", _gamePad.firstPressedID());
		FlxG.watch.addQuick("justPressed ID", _gamePad.firstPressedID());
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
		
		for (controllable in _controllableEntities) {
			if (controllable.isActivelyControllable) {
				if (_gamePad.pressed.A) {
					controllable.onPressA();
				} else {
					controllable.onReleaseA();
				}
				if (_gamePad.pressed.B) {
					controllable.onPressB();
				} else {
					controllable.onReleaseB();
				}
				if (_gamePad.pressed.X) {
					controllable.onPressX();
				} else {
					controllable.onReleaseX();
				}
				if (_gamePad.pressed.Y) {
					controllable.onPressY();
				} else {
					controllable.onReleaseY();
				}
				if (_gamePad.pressed.LEFT_SHOULDER) {
					controllable.onPressLB();
				} else {
					controllable.onReleaseLB();
				}
				if (_gamePad.pressed.RIGHT_SHOULDER) {
					controllable.onPressRB();
				} else {
					controllable.onReleaseRB();
				}
				
				if (_gamePad.pressed.BACK) {
					controllable.onPressBack();
				} else {
					controllable.onReleaseBack();
				}
				if (_gamePad.pressed.START) {
					controllable.onPressStart();
				} else {
					controllable.onReleaseStart();
				}
				/*
				controllable.onLeftTrigger(_gamePad.getAxis(FlxGamepadInputID.LEFT_TRIGGER));
				controllable.onRightTrigger(_gamePad.getAxis(FlxGamepadInputID.RIGHT_TRIGGER));
				
				controllable.onLeftAnalogue(_gamePad.getXAxis(FlxGamepadInputID.LEFT_ANALOGUE_X), _gamePad.getYAxis(FlxGamepadInputID.LEFT_ANALOGUE_Y));
				controllable.onRightAnalogue(_gamePad.getXAxis(FlxGamepadInputID.RIGHT_ANALOGUE_X), _gamePad.getYAxis(FlxGamepadInputID.RIGHT_ANALOGUE_Y));
				
				controllable.onDpad(_gamePad.getXAxis(FlxGamepadInputID.DPAD_LEFT), _gamePad.getXAxis(FlxGamepadInputID.DPAD_RIGHT), _gamePad.getYAxis(FlxGamepadInputID.DPAD_UP), _gamePad.getYAxis(FlxGamepadInputID.DPAD_DOWN));
				*/
			}
		}
		
	}
	
	
}