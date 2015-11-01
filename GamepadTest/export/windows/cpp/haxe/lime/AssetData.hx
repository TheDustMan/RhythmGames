package lime;


import lime.utils.Assets;


class AssetData {

	private static var initialized:Bool = false;
	
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var path = new #if haxe3 Map <String, #else Hash <#end String> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();	
	
	public static function initialize():Void {
		
		if (!initialized) {
			
			path.set ("assets/images/A.png", "assets/images/A.png");
			type.set ("assets/images/A.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/B.png", "assets/images/B.png");
			type.set ("assets/images/B.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/Back.png", "assets/images/Back.png");
			type.set ("assets/images/Back.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/DPad.png", "assets/images/DPad.png");
			type.set ("assets/images/DPad.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/hit.png", "assets/images/hit.png");
			type.set ("assets/images/hit.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/LB.png", "assets/images/LB.png");
			type.set ("assets/images/LB.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/miss.png", "assets/images/miss.png");
			type.set ("assets/images/miss.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/RB.png", "assets/images/RB.png");
			type.set ("assets/images/RB.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/Start.png", "assets/images/Start.png");
			type.set ("assets/images/Start.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/Stick.png", "assets/images/Stick.png");
			type.set ("assets/images/Stick.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/X.png", "assets/images/X.png");
			type.set ("assets/images/X.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/xbox360_gamepad.png", "assets/images/xbox360_gamepad.png");
			type.set ("assets/images/xbox360_gamepad.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/Y.png", "assets/images/Y.png");
			type.set ("assets/images/Y.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/sounds/classic.ogg", "assets/sounds/classic.ogg");
			type.set ("assets/sounds/classic.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("assets/sounds/gamebeat.ogg", "assets/sounds/gamebeat.ogg");
			type.set ("assets/sounds/gamebeat.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
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
