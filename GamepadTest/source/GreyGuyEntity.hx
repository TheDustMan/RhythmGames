package;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import IBeatCapable;

/**
 * ...
 * @author DustMan
 */
class GreyGuyEntity extends ControllableEntity implements IBeatCapable
{
	/* Begin INTERFACE IBeatCapable */
	public var beatState(default, null):IBeatState;
	private var _beatLock:Bool = false;
	/* End INTERFACE IBeatCapable */
	
	public var spriteGroup(default, null):FlxGroup;
	private var _greyGuy:FlxSprite;
	
	public function new(activelyControllable:Bool=false) 
	{
		super(activelyControllable);
		
		spriteGroup = new FlxGroup();
		_greyGuy = new FlxSprite(250, 50);
		_greyGuy.loadGraphic("assets/images/greyguy_bob.png", true, 139, 258);
		_greyGuy.animation.add("still", [0]);
		_greyGuy.animation.add("bob", [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 60, false);
		spriteGroup.add(_greyGuy);
	}
	
	/* INTERFACE IBeatCapable */
	
	public function onBeat():Void 
	{
		_greyGuy.animation.play("bob", false);
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