package;

import de.polygonal.ds.ArrayedQueue;
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
import flixel.tweens.FlxEase;
import flixel.tweens.FlxEase.EaseFunction;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxTween.TweenOptions;
import Globals;

import flixel.addons.nape.FlxNapeSprite;
import flixel.addons.nape.FlxNapeSpace;

import IMusicUpdateable;

class PlayState extends FlxState
{
	private var _controllableChar:FlxSprite;
	private var _inputHandler:InputHandler;
	private var _xboxController:XBoxControllerEntity;
	private var _greyGuyActor:GreyGuyActor;
	private var _greyGuyActor2:GreyGuyActor;
	private var _beatboxActor:BeatBoxActor;
	private var _musicHandler:MusicHandler;
	private var _beatScheduler:BeatScheduler;
	private var _beattweenManager:BeatTweenActionManager;
	private var _rhythmTimerManager:RhythmTimerManager;
	
	private var napeObjects:Array<FlxNapeSprite>;
	
	private var _traceActionCounter:Int = 0;
	
	override public function create():Void 
	{
		_beattweenManager = new BeatTweenActionManager();
		_beatScheduler = new BeatScheduler();
		_inputHandler = new InputHandler();
		_rhythmTimerManager = new RhythmTimerManager();
		_controllableChar = new FlxSprite(0, 0, new BitmapData(10, 10, false, 0x000000));
		
		
		FlxG.mouse.visible = false;
		FlxG.cameras.bgColor = FlxColor.WHITE;
		
		_xboxController = new XBoxControllerEntity(true);
		add(_xboxController.spriteGroup);
		_inputHandler.addControllableEntity("xbox_controller", _xboxController);
		_musicHandler = new MusicHandler();
		_musicHandler.addBeatCapableObject(_xboxController);

		_greyGuyActor = new GreyGuyActor(0, 0, true);
		_greyGuyActor2 = new GreyGuyActor(200, 0, true);
		_beatboxActor = new BeatBoxActor(200, 200, true);
		add(_greyGuyActor);
		add(_greyGuyActor2);
		add(_beatboxActor);
		_inputHandler.addControllableEntity("greyguy", _greyGuyActor);
		_inputHandler.addControllableEntity("timermanager", _rhythmTimerManager);
		_musicHandler.addBeatCapableObject(_greyGuyActor);
		_musicHandler.addBeatCapableObject(_greyGuyActor2);
		_musicHandler.addBeatCapableObject(_beatScheduler);
		_musicHandler.addBeatCapableObject(_beattweenManager);
		_musicHandler.addBeatCapableObject(_beatboxActor);
		_musicHandler.addMusicUpdateableObject(_rhythmTimerManager);
		_musicHandler.addBeatUpdateableObject(_rhythmTimerManager);
		_musicHandler.addBeatUpdateableObject(_greyGuyActor);
		_musicHandler.addBeatUpdateableObject(_greyGuyActor2);
		_musicHandler.addBeatUpdateableObject(_beatScheduler);
		_musicHandler.addBeatUpdateableObject(_beattweenManager);
		
		// Tween testing
		//var easeInfo:EaseInfo
		
		// Nape Setup
		FlxNapeSpace.init();
		FlxNapeSpace.createWalls(0.0, 0.0, FlxG.width, FlxG.height);
		createBricks();
		//testPolygonal();
	}

	private function myCallback(Tween:FlxTween):Void
	{
		trace("onUpdate");
		Tween.duration = (_musicHandler.getBeatInterval() / 1000.0);
	}

	private function testPolygonal():Void
	{
		var arrayQ = new ArrayedQueue<Action>();
		trace("Enqueue one element");
		arrayQ.enqueue(new Action(0));
		trace("Size is now: " + arrayQ.size);
		
		trace("Queue with initial capacity of 10");
		var arrayQ2 = new ArrayedQueue<Action>(10);
		trace("queue2 has size of " + arrayQ2.size);
		arrayQ2.enqueue(null);
		trace("after enqueueing null size is now: " + arrayQ2.size);
		arrayQ2.set(2, null);
		trace("after enqueueing null at index 2, size is now" + arrayQ2.size);
		var action = arrayQ2.dequeue();
		trace("Action is " + action);
		trace("After dequeue, size is now " + arrayQ2.size);
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
		_musicHandler.update(elapsed);
		if (FlxG.mouse.justPressed) {
		
			if (FlxNapeSpace.space.gravity.y == 0) {
				FlxNapeSpace.space.gravity.setxy(0, 500);
			}
			_beatScheduler.addAction(new TraceAction(_traceActionCounter + ": now", 0));
			_beatScheduler.addAction(new TraceAction(_traceActionCounter + ": offset 1", 1));
			_beatScheduler.addAction(new TraceAction(_traceActionCounter + ": offset 2", 2));
			_beatScheduler.addAction(new TraceAction(_traceActionCounter + ": offset 3", 3));
			_beatScheduler.addAction(new TraceAction(_traceActionCounter + ": offset 4", 4));
			_beatScheduler.addAction(new TraceAction(_traceActionCounter + ": offset 5", 5));
			_beatScheduler.addAction(new TraceAction(_traceActionCounter + ": offset 7", 7));
			_beatScheduler.addAction(new TraceAction(_traceActionCounter + ": offset 10", 10));
			_beatScheduler.addAction(new TraceAction(_traceActionCounter + ": offset 15", 15));
			++_traceActionCounter;
		}
		if (FlxG.mouse.justPressedRight) {
			_beatScheduler.addActionGroup(_greyGuyActor.getActionGroupByName("tween"));
		}
		if (FlxG.keys.justPressed.LEFT) {
			_beatScheduler.addActionGroup(_greyGuyActor.getActionGroupByName("eight"));
		}
		if (FlxG.keys.justPressed.RIGHT) {
			_musicHandler.cycleSong();
		}
		if (FlxG.keys.justPressed.UP) {
			_beatScheduler.addActionGroup(_greyGuyActor.getActionGroupByName("up_down"));
		}
		if (FlxG.keys.justPressed.DOWN) {
			_beatScheduler.addActionGroup(_greyGuyActor2.getActionGroupByName("up_down"));
		}
		if (FlxG.keys.justPressed.S) {
			var rhythmInputAction = new RhythmInputAction(_rhythmTimerManager.createTimer(), 0);
			_beatScheduler.addAction(rhythmInputAction);
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
