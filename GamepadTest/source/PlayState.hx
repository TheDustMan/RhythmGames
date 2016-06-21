package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.util.FlxColor;
import flixel.math.FlxPoint;
import flixel.input.gamepad.FlxGamepad;
import flixel.system.FlxSound;
import openfl.display.BitmapData;
import openfl.media.Sound;
import flixel.text.FlxText;
import Globals;

import flixel.addons.nape.FlxNapeSprite;
import flixel.addons.nape.FlxNapeSpace;

class PlayState extends FlxState
{
	private var _controllableChar:FlxSprite;
	private var _inputHandler:InputHandler;
	private var _xboxController:XBoxControllerEntity;
	private var _greyGuyEntity:GreyGuyEntity;
	private var _musicHandler:MusicHandler;
	
	private var napeObjects:Array<FlxNapeSprite>;
	
	override public function create():Void 
	{
		_inputHandler = new InputHandler();
		_controllableChar = new FlxSprite(0, 0, new BitmapData(10, 10, false, 0x000000));
		
		
		FlxG.mouse.visible = false;
		FlxG.cameras.bgColor = FlxColor.WHITE;
		
		_xboxController = new XBoxControllerEntity(true);
		add(_xboxController.spriteGroup);
		_inputHandler.addControllableEntity("xbox_controller", _xboxController);
		_musicHandler = new MusicHandler();
		_musicHandler.addBeatCapableObject(_xboxController);

		_greyGuyEntity = new GreyGuyEntity(true);
		add(_greyGuyEntity.spriteGroup);
		_inputHandler.addControllableEntity("greyguy", _greyGuyEntity);
		_musicHandler.addBeatCapableObject(_greyGuyEntity);
		
		// Nape Setup
		FlxNapeSpace.init();
		FlxNapeSpace.createWalls(0.0, 0.0, FlxG.width, FlxG.height);
		createBricks();
	}
	
	private function createBricks() 
	{
		napeObjects = new Array<FlxNapeSprite>();
		var brick:FlxNapeSprite;
		
		var brickHeight:Int = Std.int(10); // magic number!
		var brickWidth:Int = brickHeight * 2;

		brick = new FlxNapeSprite();
		brick.makeGraphic(brickWidth, brickHeight, 0x0);
		brick.createRectangularBody();
		brick.loadGraphic("assets/images/napeObject.png");
		brick.antialiasing = true;
		brick.scale.x = brickWidth / 80;
		brick.scale.y = brickHeight / 40;
		brick.flipX = FlxG.random.bool(); // add some variety
		brick.flipY = FlxG.random.bool(); // add some variety.
		brick.setBodyMaterial(.5, .5, .5, 2);
		brick.body.position.y = FlxG.height / 2;
		brick.body.position.x = FlxG.width / 2; 
		add(brick);
		napeObjects.push(brick);
	}
	
	override public function update(elapsed:Float):Void 
	{	
		super.update(elapsed);
		
		_inputHandler.functionUpdateWithInput();
		_musicHandler.update();
		if (FlxG.mouse.justPressed) {
			_musicHandler.cycleSong();
			if (FlxNapeSpace.space.gravity.y == 0) {
				FlxNapeSpace.space.gravity.setxy(0, 500);
			}
		}
		/*
		var justReleasedID:Int = _gamePad.firstJustReleasedButtonID();
		var justPressedID:Int =  _gamePad.firstJustPressedButtonID();
		if (justPressedID != -1) {
			trace("Just Pressed: " + justPressedID);
		}
		if (justReleasedID != -1) {
			trace("Just Released: " + justReleasedID);
		}
		
		if (_gamePad.justPressed(GamepadIDs.A)) {
			_aButton.alpha = ALPHA_ON;
			
			if (_onBeat) {
				_hitText.visible = true;
				_missText.visible = false;
				_currentBeatLock = true;
			} else {
				_hitText.visible = false;
				_missText.visible = true;
			}
		} else {
			_aButton.alpha = ALPHA_OFF;
		}
		
		updateBeat();
		*/
	}
}
