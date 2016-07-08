package;
import de.polygonal.ds.ArrayList;
import flixel.tweens.FlxTween.TweenOptions;
import LinearMotionTweenAction;
import IBeatCapable;
import IBeatUpdateable;
/**
 * ...
 * @author DustMan
 */
class BeatTweenActionManager implements IBeatCapable implements IBeatUpdateable
{
	private var _tweenActions:ArrayList<TweenAction>;
	
	public var beatState(default, null):IBeatState;
	public var beatData(default, null):BeatData;
	
	public function new() 
	{
		_tweenActions = new ArrayList<TweenAction>();
	}
	
	/* INTERFACE IBeatCapable */
	/*
	public  function createLinearMotionTweenAction(actor:Actor,
												   tweenOptions:TweenOptions,
												   linearMotionData:LinearMotionData,
											       beatDuration:Float,
											       beatOffset:Int = 0):LinearMotionTweenAction
	{
		var duration = (_beatInterval / 1000.0) * beatDuration;
		return new LinearMotionTweenAction(actor, tweenOptions, linearMotionData, duration, beatOffset);
	}
	*/
	
	public var _beatLock:Bool;
	
	public function onBeat():Void 
	{
		
	}
	
	public function offBeat():Void 
	{
		
	}
	
	public function onEnterBeatAcceptanceWindow():Void 
	{
		
	}
	
	public function onExitBeatAcceptanceWindow():Void 
	{
		
	}
	
	/* INTERFACE IBeatCapable */
	
	public function onBeatUpdate(beatData:BeatData):Void
	{
		this.beatData = beatData;
	}
	
}