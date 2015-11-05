package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.util.FlxColor;
import flixel.util.FlxPoint;
import flixel.input.gamepad.FlxGamepad;
import flixel.input.gamepad.XboxButtonID;
import flixel.input.gamepad.OUYAButtonID;
import flixel.system.FlxSound;
import openfl.display.BitmapData;
import openfl.media.Sound;
import flixel.text.FlxText;
import Globals;

class PlayState extends FlxState
{
	private var _controllableChar:FlxSprite;
	private var _inputHandler:InputHandler;
	private var _xboxController:XBoxControllerEntity;
	private var _musicHandler:MusicHandler;

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
	}
	
	override public function update():Void 
	{
		super.update();
		
		_inputHandler.functionUpdateWithInput();
		_musicHandler.update();
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
