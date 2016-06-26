package;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import IBeatCapable;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.graphics.frames.FlxFrame;
import Actor;
/**
 * ...
 * @author DustMan
 */
class GreyGuyActor extends Actor
{
	private var _greyGuy:FlxSprite;
	
	public function new(X:Float = 0, Y:Float = 0, activelyControllable:Bool=false) 
	{
		super(X, Y, activelyControllable);
		
		//var text1 = FlxAtlasFrames.fromTexturePackerJson("assets/images/greyguy.png", "assets/images/greyguy.json");
		_spriteAnimationMap = new Map<Int, String>();
		
		this.frames = FlxAtlasFrames.fromTexturePackerJson("assets/images/greyguy.png", "assets/images/greyguy.json");
		this.animation.addByPrefix("bob", "greyguy_bob_", 30, false);
		this.animation.addByPrefix("crouch", "greyguy_crouch_", 30, false);
		this.animation.addByPrefix("stand", "greyguy_stand_", 30, false);
		this.animation.addByIndices("still", "greyguy_bob_", [0], ".png", 30, false);
		
		//_greyGuy.loadGraphic("assets/images/greyguy_bob.png", true, 139, 258);
		//_greyGuy.animation.add("still", [0]);
		//_greyGuy.animation.add("bob", [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 60, false);
		
		_spriteAnimationMap.set(0, "still");
		_spriteAnimationMap.set(1, "bob");
		_spriteAnimationMap.set(2, "crouch");
		_spriteAnimationMap.set(3, "stand");
		_currentAnimation = 1;
		
		var actionGroup = new ActionGroup();
		actionGroup.addAction(new ActorStateTransitionAction(this, ACTING, 0));
		actionGroup.addAction(new GreyGuyCrouchAction(this, 0));
		actionGroup.addAction(new GreyGuyStandAction(this, 3));
		actionGroup.addAction(new ActorStateTransitionAction(this, WAITING_FOR_INPUT, 0));
		actionGroup.addAction(new GreyGuyCrouchAction(this, 5));
		actionGroup.addAction(new GreyGuyStandAction(this, 7));
		actionGroup.addAction(new GreyGuyCrouchAction(this, 8));
		actionGroup.addAction(new GreyGuyStandAction(this, 10));
		actionGroup.addAction(new GreyGuyCrouchAction(this, 12));
		actionGroup.addAction(new GreyGuyStandAction(this, 15));
		actionGroup.addAction(new ActorStateTransitionAction(this, IDLE, 15));
		this.addActionGroup("up_down", actionGroup);
	}
		
	/* INTERFACE IBeatCapable */
	
	override public function onBeat():Void 
	{
		/*
		super.onBeat();
		++_currentAnimation;
		if (_currentAnimation > 3) {
			_currentAnimation = 1;
		}
		*/
		if (_state == IDLE) {
			this.animation.play(_spriteAnimationMap[_currentAnimation], false);
		}
	}
	
	override public function offBeat():Void 
	{
		super.offBeat();
	}
	
	override public function onEnterBeatAcceptanceWindow():Void 
	{
		super.onEnterBeatAcceptanceWindow();
	}
	
	override public function onExitBeatAcceptanceWindow():Void 
	{
		super.onExitBeatAcceptanceWindow();
	}
}