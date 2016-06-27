package;

/**
 * @author DustMan
 */
interface IControllable 
{
	public var isActivelyControllable:Bool;
	
	public function onJustPressedMouseLeft():Void;
	public function onPressedMouseLeft():Void;
	public function onReleaseMouseLeft():Void;
	public function onJustReleasedMouseLeft():Void;
	
	public function onPressA():Void;
	public function onJustPressedA():Void;
	public function onPressB():Void;
	public function onPressX():Void;
	public function onPressY():Void;
	public function onPressBack():Void;
	public function onPressStart():Void;
	public function onPressLB():Void;
	public function onPressRB():Void;
	public function onLeftTrigger(axisValue:Float):Void;
	public function onRightTrigger(axisValue:Float):Void;
	public function onLeftAnalogue(xAxisValue:Float, yAxisValue:Float):Void;
	public function onRightAnalogue(xAxisValue:Float, yAxisValue:Float):Void;
	public function onDpad(dpadLeft:Bool, dpadRight:Bool, dpadUp:Bool, dpadDown:Bool):Void;
	
	public function onReleaseA():Void;
	public function onJustReleasedA():Void;
	public function onReleaseB():Void;
	public function onReleaseX():Void;
	public function onReleaseY():Void;
	public function onReleaseBack():Void;
	public function onReleaseStart():Void;
	public function onReleaseLB():Void;
	public function onReleaseRB():Void;

}