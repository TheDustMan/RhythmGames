package;

/**
 * @author DustMan
 */

typedef BeatData =
{
	var beatInterval:Float;
}
interface IBeatUpdateable 
{
	public var beatData(default, null):BeatData;
	
	public function onBeatUpdate(beatData:BeatData):Void;
}