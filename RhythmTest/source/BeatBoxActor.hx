package;
import IBeatCapable;
import flixel.util.FlxTimer;

/**
 * ...
 * @author DustMan
 */
class BeatBoxActor extends Actor implements IBeatCapable implements ITimeable
{	
	private var _colorToggle:Int = 0;
	
	public function new(X:Float=0, Y:Float=0, activelyControllable:Bool=false) 
	{
		super(X, Y, activelyControllable);
		this.makeGraphic(100, 100, 0xFFFFFFFF); // width, height, color (AARRGGBB hexadecimal)
	}
	
	/* INTERFACE IBeatCapable */
	
	override public function onBeat():Void 
	{
		super.onBeat();
		if (_colorToggle == 0) {
			_colorToggle = 1;
			this.color = 0xFFAAAAAA;
		} else {
			_colorToggle = 0;
			this.color = 0xFFFFFFFF;
		}
	}
	
	/* INTERFACE ITimeable */
	override public function onTimer(timer:FlxTimer):Void
	{
		super.onTimer(timer);
	}
}