package;
import flixel.tweens.FlxTween;

/**
 * ...
 * @author DustMan
 */
class TweenAction extends Action
{
	private var _tween:FlxTween;
	
	public function new(actor:Actor, tween:FlxTween) 
	{
		super(actor);
		_tween = tween;
	}
	
	override public function doAction():Void
	{
		var t:FlxTween = new FlxTween({
		_tween.start();
	}
}