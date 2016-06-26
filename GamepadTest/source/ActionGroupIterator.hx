package;

/**
 * ...
 * @author DustMan
 */
class ActionGroupIterator
{
	private var _actionGroup:ActionGroup;
	private var _currentActionIndex:Int;
	
	public function new(actionGroup:ActionGroup) 
	{
		_actionGroup = actionGroup;
		_currentActionIndex = 0;
	}
	
	public function hasHext():Bool
	{
		return _currentActionIndex < _actionGroup.count();
	}
	
	public function next():Action
	{
		return _actionGroup.getAction(_currentActionIndex++);
	}
	
}