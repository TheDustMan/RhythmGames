package;
import IBeatCapable;

/**
 * ...
 * @author DustMan
 */
enum ActorState
{
	IDLE;
	ACTING;
	WAITING_FOR_INPUT;
}
	
class Actor extends ControllableEntity implements IBeatCapable
{
	/* Begin INTERFACE IBeatCapable */
	public var beatState(default, null):IBeatState;
	private var _beatLock:Bool = false;
	/* End INTERFACE IBeatCapable */
	
	private var _actions:Array<Action>;
	private var _actionGroupMap:Map< String, ActionGroup >;
	private var _actionGroupIterators:Array<ActionGroupIterator>;
	private var _currentActionGroup:ActionGroup;
	
	private var _spriteAnimationMap:Map<Int, String>;
	private var _currentAnimation:Int;
	
	private var _state:ActorState = IDLE;
	
	public function new(X:Float = 0, Y:Float = 0, activelyControllable:Bool=false) 
	{
		super(X, Y, activelyControllable);
		_actionGroupMap = new Map < String, ActionGroup >();
		_currentActionGroup = null;
		_actionGroupIterators = new Array<ActionGroupIterator>();
		
		_spriteAnimationMap = new Map<Int, String>();
	}
	
	public function setState(state:ActorState)
	{
		_state = state;
	}
	
	public function createTestActionGroup():Void
	{
		//var actionGroup = new ActionGroup();
		//actionGroup.addAction(
	}
	
	public function playAnimationByName(name:String):Void
	{
		this.animation.play(name);
	}
	
	public function addAction(action:Action):Void
	{
		_actions.push(action);
	}
	
	public function addActionGroup(name:String, group:ActionGroup):Void
	{
		_actionGroupMap.set(name, group);
	}
	
	public function getActionGroupByName(name:String):ActionGroup
	{
		return _actionGroupMap[name];
	}
	
	public function startActionGroup(name:String):Void
	{
		_actionGroupIterators.push(new ActionGroupIterator(_actionGroupMap[name]));
	}
	
	/* INTERFACE IBeatCapable */
	
	public function onBeat():Void 
	{
		// Actors shouldn't be scheduling their own actions, that's the job
		// of the BeatScheduler
		/*
		for (actionGroupIterator in _actionGroupIterators) {
			if (actionGroupIterator.hasHext()) {
				actionGroupIterator.next().doAction();
			}
		}*/
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
}