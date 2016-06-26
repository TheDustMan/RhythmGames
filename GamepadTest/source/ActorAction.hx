package;

/**
 * ...
 * @author DustMan
 */
class ActorAction extends Action
{
	public var actor(default, null):Actor;
	
	public function new(actor:Actor, beatOffset:Int=0) 
	{
		super(beatOffset);
		this.actor = actor;
	}
	
}