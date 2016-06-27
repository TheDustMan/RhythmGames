package;
import flixel.tweens.FlxTween;

typedef LinearMotionData =
{
	var startX:Float;
	var startY:Float;
	var endX:Float;
	var endY:Float;
}
/**
 * ...
 * @author DustMan
 */
class LinearMotionTweenAction extends TweenAction
{
	private var _lmd:LinearMotionData;
	
	public function new(actor:Actor, tweenOptions:TweenOptions, linearMotionData:LinearMotionData, duration:Float, beatOffset:Int = 0) 
	{
		super(actor, tweenOptions, duration, beatOffset);
		_lmd = linearMotionData;
	}
	
	override public function doAction():Void
	{
		var duration = (actor.beatData.beatInterval * _duration) / 1000.0;
		FlxTween.linearMotion(actor, _lmd.startX, _lmd.startY, _lmd.endX, _lmd.endY, duration, true, _tweenOptions);
	}
}