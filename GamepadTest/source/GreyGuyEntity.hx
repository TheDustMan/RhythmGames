package;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import IBeatCapable;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.graphics.frames.FlxFrame;

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
	private var _spriteAnimationMap:Map<Int, String>;
	private var _currentAnimation:Int;
	private var _beatDone:Bool;
	
	public function new(activelyControllable:Bool=false) 
	{
		super(activelyControllable);
		
		//var text1 = FlxAtlasFrames.fromTexturePackerJson("assets/images/greyguy.png", "assets/images/greyguy.json");
		_spriteAnimationMap = new Map<Int, String>();
		
		spriteGroup = new FlxGroup();
		_greyGuy = new FlxSprite(250, 50);
		
		_greyGuy.frames = FlxAtlasFrames.fromTexturePackerJson("assets/images/greyguy.png", "assets/images/greyguy.json");
		_greyGuy.animation.addByPrefix("bob", "greyguy_bob_", 30, false);
		_greyGuy.animation.addByPrefix("crouch", "greyguy_crouch_", 30, false);
		_greyGuy.animation.addByPrefix("stand", "greyguy_stand_", 30, false);
		_greyGuy.animation.addByIndices("still", "greyguy_bob_", [0], ".png", 30, false);
		
		//_greyGuy.loadGraphic("assets/images/greyguy_bob.png", true, 139, 258);
		//_greyGuy.animation.add("still", [0]);
		//_greyGuy.animation.add("bob", [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 60, false);
		spriteGroup.add(_greyGuy);
		
		_spriteAnimationMap.set(0, "still");
		_spriteAnimationMap.set(1, "bob");
		_spriteAnimationMap.set(2, "crouch");
		_spriteAnimationMap.set(3, "stand");
		_currentAnimation = 1;
		_beatDone = false;
	}
	
	/* INTERFACE IBeatCapable */
	
	public function onBeat():Void 
	{
		if (!_beatDone) {
			_beatDone = true;
			++_currentAnimation;
			if (_currentAnimation > 3) {
				_currentAnimation = 1;
			}
			_greyGuy.animation.play(_spriteAnimationMap[_currentAnimation], false);
		}
	}
	
	public function offBeat():Void 
	{
		_beatDone = false;
	}
	
	public function onEnterBeatAcceptanceWindow():Void 
	{
		
	}
	
	public function onExitBeatAcceptanceWindow():Void 
	{
		
	}
	
}