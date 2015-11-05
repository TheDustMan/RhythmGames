package;

/**
 * @author DustMan
 */

enum IBeatState {
	IN_WINDOW;
	OUT_WINDOW;
}

interface IBeatCapable 
{
	public var beatState(default, null):IBeatState;
	private var _beatLock:Bool = false;
	
	public function onBeat():Void;
	public function offBeat():Void;
	public function onEnterBeatAcceptanceWindow():Void;
	public function onExitBeatAcceptanceWindow():Void;
}