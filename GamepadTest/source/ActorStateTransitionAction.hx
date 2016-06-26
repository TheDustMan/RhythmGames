package;
import Actor;
/**
 * ...
 * @author DustMan
 */
class ActorStateTransitionAction extends ActorAction
{
	private var _state:ActorState;
	
	public function new(actor:Actor, state:ActorState, beatOffset:Int=0) 
	{
		super(actor, beatOffset);
		_state = state;
	}
	
	override public function doAction()
	{
		actor.setState(_state);
	}
}