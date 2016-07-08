package;

import IControllable;

/**
 * ...
 * @author DustMan
 */
class RhythmInputAction extends Action
{
	private var _timer:RhythmTimer;
	public function new(rhythmTimer:RhythmTimer, beatOffset:Int=0) 
	
	{
		super(beatOffset);
		_timer = rhythmTimer;
	}

	override public function doAction():Void
	{
		trace("started rhythm timer!");
		_timer.start(5, [1000, 2000, 3000, 4000]);
	}
}