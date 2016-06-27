package;

/**
 * @author DustMan
 */

enum IBeatState {
	IN_WINDOW;
	OUT_WINDOW;
}

typedef BeatData =
{
	var beatInterval:Float;
}

interface IBeatCapable 
{
	public var beatState(default, null):IBeatState;
	private var _beatLock:Bool = false;
	public var beatData(default, null):BeatData;
	
	public function onBeat():Void;
	public function offBeat():Void;
	public function onEnterBeatAcceptanceWindow():Void;
	public function onExitBeatAcceptanceWindow():Void;
	public function onBeatDataUpdate(beatData:BeatData):Void;
}