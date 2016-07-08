package;
import flixel.util.FlxTimer;

/**
 * ...
 * @author DustMan
 */
typedef TimerData =
{
	var duration:Float;
	var loops:Int;
}
class TimedAction extends ActorAction
{
	private var _timerData:TimerData;
	
	public function new(actor:Actor, timerData:TimerData, beatOffset:Int=0) 
	{
		super(actor, beatOffset);
		_timerData = timerData;
	}

	override public function doAction():Void
	{
		var duration = (actor.beatData.beatInterval * _timerData.duration) / 1000.0;
		new FlxTimer().start(duration, actor.onTimer, _timerData.loops);
	}
}