package;

/**
 * ...
 * @author DustMan
 */
class ActionGroup
{
	private var _actions:Array<Action>;
	private var _inputActions:Array<Action>;
	
	public function new() 
	{
		_actions = new Array<Action>();
	}
	
	public function addAction(action:Action):Void
	{
		_actions.push(action);
	}
	
	public function addInputAction(action:Action):Void
	{
		_inputActions.push(action);
	}
	
	public function count():Int
	{
		return _actions.length;
	}
	
	public function getAction(actionIndex):Action
	{
		return _actions[actionIndex];
	}
}