package;
import flixel.tweens.FlxTween;

/**
 * ...
 * @author DustMan
 */
class TweenAction extends ActorAction
{
	private var _tweenOptions:TweenOptions;
	private var _duration:Float;
	
	public function new(actor:Actor, tweenOptions:TweenOptions, duration:Float, beatOffset:Int=0) 
	{
		super(actor, beatOffset);
		_tweenOptions = tweenOptions;
		_duration = duration;
	}
	
	override public function doAction():Void
	{
		
	}
}