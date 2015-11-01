package lime;


import lime.utils.Assets;


class AssetData {

	private static var initialized:Bool = false;
	
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var path = new #if haxe3 Map <String, #else Hash <#end String> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();	
	
	public static function initialize():Void {
		
		if (!initialized) {
			
			path.set ("assets/A.png", "assets/A.png");
			type.set ("assets/A.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/B.png", "assets/B.png");
			type.set ("assets/B.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/Back.png", "assets/Back.png");
			type.set ("assets/Back.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/DPad.png", "assets/DPad.png");
			type.set ("assets/DPad.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/LB.png", "assets/LB.png");
			type.set ("assets/LB.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/RB.png", "assets/RB.png");
			type.set ("assets/RB.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/Start.png", "assets/Start.png");
			type.set ("assets/Start.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/Stick.png", "assets/Stick.png");
			type.set ("assets/Stick.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/X.png", "assets/X.png");
			type.set ("assets/X.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/xbox360_gamepad.png", "assets/xbox360_gamepad.png");
			type.set ("assets/xbox360_gamepad.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/Y.png", "assets/Y.png");
			type.set ("assets/Y.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/sounds/beep.ogg", "assets/sounds/beep.ogg");
			type.set ("assets/sounds/beep.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("assets/sounds/flixel.ogg", "assets/sounds/flixel.ogg");
			type.set ("assets/sounds/flixel.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("assets/fonts/nokiafc22.ttf", "assets/fonts/nokiafc22.ttf");
			type.set ("assets/fonts/nokiafc22.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/arial.ttf", "assets/fonts/arial.ttf");
			type.set ("assets/fonts/arial.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			
			
			initialized = true;
			
		} //!initialized
		
	} //initialize
	
	
} //AssetData
