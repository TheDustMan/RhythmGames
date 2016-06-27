package;

import de.polygonal.ds.ArrayedQueue;
import de.polygonal.ds.ArrayList;
import IBeatCapable;
/**
 * ...
 * @author DustMan
 */
class BeatScheduler implements IBeatCapable
{	
	/* Begin INTERFACE IBeatCapable */
	public var beatState(default, null):IBeatState;
	public var beatData(default, null):BeatData;
	/* End INTERFACE IBeatCapable */
	
	private var _actionQueue:ArrayedQueue<ArrayList<Action>>;
	
	public function new() 
	{
		_actionQueue = new ArrayedQueue<ArrayList<Action>>();
	}
	
	public function addActionGroup(actionGroup:ActionGroup):Void
	{
		var acIt = new ActionGroupIterator(actionGroup);
		while (acIt.hasHext()) {
			addAction(acIt.next());
		}
	}
	
	public function addAction(action:Action):Void
	{
		/* To add an action:
		  (1) Read the offset at which this action should be inserted
		  (2) If the offset is greater than zero insert a no-op for the number of beats between the offset and 0
		*/
		var offset = action.beatOffset;
		if (_actionQueue.isEmpty()) {
			while (offset > 0) {
				_actionQueue.enqueue(null);
				--offset;
			}
			var actionList = new ArrayList<Action>();
			actionList.pushBack(action);
			_actionQueue.enqueue(actionList);
		} else if (offset < _actionQueue.size) {
			var currentActionListForBeat = _actionQueue.get(offset);
			if (currentActionListForBeat == null) {
				var actionList = new ArrayList<Action>();
				actionList.pushBack(action);
				_actionQueue.set(offset, actionList); 
			} else {
				currentActionListForBeat.pushBack(action);
			}
		} else { // offset is greater than the size of the actionQueue
			// enqueue missing actions so that the actual action can be put in the queue
			for (i in 0...(offset - _actionQueue.size)) {
				_actionQueue.enqueue(null);
			}
			var actionList = new ArrayList<Action>();
			actionList.pushBack(action);
			_actionQueue.enqueue(actionList);
		}
	}
	
	/* INTERFACE IBeatCapable */
	
	
	public var _beatLock:Bool;
	
	public function onBeat():Void 
	{
		// Do one dequeue per beat, and run any actions stored on that beat
		if (!_actionQueue.isEmpty()) {
			var actionsList = _actionQueue.dequeue();
			if (actionsList != null) {
				for (action in actionsList) {
					action.doAction();
				}
			}
		}
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
	
	public function onBeatDataUpdate(beatData:BeatData):Void
	{
		this.beatData = beatData;
	}
	
}