package;

/**
 * ...
 * @author DustMan
 */
class TraceAction extends Action
{
	private var _message:String;
	
	public function new(message:String, beatOffset:Int=0) 
	{
		super(beatOffset);
		_message = message;
	}
	
	override public function doAction():Void
	{
		trace(_message);
	}
	
}