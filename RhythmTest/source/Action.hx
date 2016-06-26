package;

/**
 * ...
 * @author DustMan
 */
class Action
{
	// Properties
	public var beatOffset(default, null):Int;
	
	public function new(beatOffset:Int = 0) 
	{
		this.beatOffset = beatOffset;
	}
	
	public function doAction():Void
	{
	}
}