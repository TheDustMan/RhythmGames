/**
 * A timer class similar to the FlxTimer class, except relies on the
 * elapsed music time rather than elapsed time between frames.
 */
class RhythmTimer
{
	/**
	 * The maximum lifetime of this timer
	 */
	private var _duration:Float;
	
	/**
	 * Tracks the amount of time the timer has been running.
	 */
	private var _currentTime:Float = 0.0;
	
	/**
	 * An array containing the input timings required for this timer
	 */
	private var _inputTimings:Array<Float>;
	
	/**
	 * Stores amount of inputs detected so far during the execution window
	 * of this timer.
	 */
	private var _inputCount:Int = 0;
	
	/**
	 * Whether or not this timer is active. Once active, it will run until the duration
	 * is complete, then will get removed from the manager automatically.
	 */
	public var isActive(default, null):Bool = false;
	
	/**
	 * Represents whether or not this timer is finished running. When finished
	 * it should be removed from the manager.
	 */
	public var isFinished(default, null):Bool = false;
	
	/**
	 * Stores the beatInterval of the currently playing song.
	 */
	public var beatInterval:Float = 0;
	
	/**
	 * Private constructor because we only want these created by the manager
	 */
	@:allow(RhythmTimerManager)
	private function new(beatInterval:Float)
	{
		this.beatInterval = beatInterval;
	}
	
	/** 
	 * @param duration The lifetime of the timer, in beats
	 * @param inputTimings An array filled with the timings for this input timer (all timings are relative to the starting time of the timer)
	 */
	public function start(beats:Float, inputTimings:Array<Float>):Void
	{
		_duration = beats * beatInterval;
		_inputTimings = inputTimings;
		isActive = true;
		trace("timer is active with duration [ " + _duration + " and timings [ " + _inputTimings + "!");
	}
	
	public function updateTimer(elapsed:Float):Void
	{
		if (isActive) {
			_currentTime += elapsed;
			if (_currentTime > _duration) {
				trace("tiemr is finished!");
				isFinished = true;
				isActive = false;
			}
		}
	}
	
	public function onJustPressedA():Void
	{
		trace("RhytmTimer pressed A!");
		if (isActive) {
			if (_inputCount < _inputTimings.length) {
				trace("Input #" + _inputCount + " was expected at " + _inputTimings[_inputCount]);
				trace("Press A at " + _currentTime);
				// put logic here to check for input precision and appropriate reactions
				++_inputCount;
			}
			if (_currentTime > _duration) {
				isFinished = true;
				isActive = false;
			}
		} else {
			trace("timer isn't active yet!");
		}
	}
}
