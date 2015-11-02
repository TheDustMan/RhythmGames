package;

import flixel.input.gamepad.FlxGamepad;
/**
 * ...
 * @author DustMan
 */
class InputHandler
{
	private var _controllableEntities:Map<String, IControllable>;
	
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
	
	public function functionUpdateWithInput(gamePad:FlxGamepad):Void
	{
		
		
		for (controllable in _controllableEntities) {
			if (controllable.isActivelyControllable) {
				if (gamePad.pressed(GamepadIDs.A)) {
					controllable.onPressA();
				} else {
					controllable.onReleaseA();
				}
				if (gamePad.pressed(GamepadIDs.B)) {
					controllable.onPressB();
				} else {
					controllable.onReleaseB();
				}
				if (gamePad.pressed(GamepadIDs.X)) {
					controllable.onPressX();
				} else {
					controllable.onReleaseX();
				}
				if (gamePad.pressed(GamepadIDs.Y)) {
					controllable.onPressY();
				} else {
					controllable.onReleaseY();
				}
				if (gamePad.pressed(GamepadIDs.LB)) {
					controllable.onPressLB();
				} else {
					controllable.onReleaseLB();
				}
				if (gamePad.pressed(GamepadIDs.RB)) {
					controllable.onPressRB();
				} else {
					controllable.onReleaseRB();
				}
				
				if (gamePad.pressed(GamepadIDs.SELECT)) {
					controllable.onPressBack();
				} else {
					controllable.onReleaseBack();
				}
				if (gamePad.pressed(GamepadIDs.START)) {
					controllable.onPressStart();
				} else {
					controllable.onReleaseStart();
				}
				
				controllable.onLeftTrigger(gamePad.getAxis(GamepadIDs.LEFT_TRIGGER));
				controllable.onRightTrigger(gamePad.getAxis(GamepadIDs.RIGHT_TRIGGER));
				
				controllable.onLeftAnalogue(gamePad.getXAxis(GamepadIDs.LEFT_ANALOGUE_X), gamePad.getYAxis(GamepadIDs.LEFT_ANALOGUE_Y));
				controllable.onRightAnalogue(gamePad.getXAxis(GamepadIDs.RIGHT_ANALOGUE_X), gamePad.getYAxis(GamepadIDs.RIGHT_ANALOGUE_Y));
				
				controllable.onDpad(gamePad.dpadLeft, gamePad.dpadRight, gamePad.dpadUp, gamePad.dpadDown);
				
			}
		}
		
	}
	
	
}