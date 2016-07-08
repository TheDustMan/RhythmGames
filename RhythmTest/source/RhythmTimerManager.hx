import flixel.util.FlxArrayUtil;
import IMusicUpdateable;
import IBeatUpdateable;
import IControllable;

/**
 * A simple manager for tracking and updating rhythm timer objects.
 */
class RhythmTimerManager extends ControllableEntity implements IMusicUpdateable implements IBeatUpdateable
{
	/* IBeatUpdateable variables */
	public var beatData(default, null):BeatData;
	
	private var _timers:Array<RhythmTimer> = [];
	/**
	 * Instantiates a new timer manager.
	 */
	public function new()
	{
		super(0, 0, true);
	}
	
	/**
	 * Creates a RhythmTimer object and adds it to an internal list of timers
	 * that are updated by the elapsed music time
	 * @return
	 */
	public function createTimer():RhythmTimer
	{
		var timer = new RhythmTimer(beatData.beatInterval);
		this.add(timer);
		trace("Timers has " + _timers.length + " elements");
		return timer;
	}

	/**
	 * Implementation of IMusicUpdateable's onMusicUpdate method:
	 * Called by MusicHandler's update method with how much song time has elapsed since last frame.
	 * Cycles through timers and calls update() on each one.
	 */
	public function onMusicUpdate(elapsed:Float):Void
	{
		for (timer in _timers)
		{
			if (timer.isActive) {
				timer.updateTimer(elapsed);
			} else if (timer.isFinished) {
				this.remove(timer);
			}
		}
	}
	
	/**
	 * Implementation of IBeatUpdateable's onBeatUpdate method:
	 * Called by MusicHandler's update method whenever the song changes. beatData
	 * parameter contains beat data about the currently playing song, such as the beatInterval.
	 */
	public function onBeatUpdate(beatData:BeatData):Void
	{
		this.beatData = beatData;
		for (timer in _timers)
		{
			timer.beatInterval = this.beatData.beatInterval;
		}
	}
	
	/**
	 * Add a new timer to the timer manager.
	 * Called when RhythmTimer is started.
	 * 
	 * @param	Timer	The FlxTimer you want to add to the manager.
	 */
	public function add(Timer:RhythmTimer):Void
	{
		_timers.push(Timer);
	}
	
	/**
	 * Remove a timer from the timer manager.
	 * Called automatically by RhythmTimer's stop() function.
	 * 
	 * @param	Timer	The MusicTimer you want to remove from the manager.
	 * @param	ReturnInPool Whether to reset and put Timer into internal _pool.
	 */
	public function remove(Timer:RhythmTimer):Void
	{
		trace("Timer is being removed");
		FlxArrayUtil.fastSplice(_timers, Timer);
	}
	
	/**
	 * Removes all the timers from the timer manager.
	 */
	public inline function clear():Void
	{
		FlxArrayUtil.clearArray(_timers);
	}
	
	override public function onJustPressedA():Void
	{
		trace("RhytmTimerManager pressed A!");
		trace("Timers has " + _timers.length + " elements");
		for (timer in _timers)
		{
			timer.onJustPressedA();
		}
	}
}