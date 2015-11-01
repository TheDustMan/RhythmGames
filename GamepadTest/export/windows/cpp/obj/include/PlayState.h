#ifndef INCLUDED_PlayState
#define INCLUDED_PlayState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
HX_DECLARE_CLASS0(PlayState)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS3(flixel,input,gamepad,FlxGamepad)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxPooled)
HX_DECLARE_CLASS2(flixel,_system,FlxSound)
HX_DECLARE_CLASS2(flixel,text,FlxText)
HX_DECLARE_CLASS2(flixel,util,FlxPoint)


class HXCPP_CLASS_ATTRIBUTES  PlayState_obj : public ::flixel::FlxState_obj{
	public:
		typedef ::flixel::FlxState_obj super;
		typedef PlayState_obj OBJ_;
		PlayState_obj();
		Void __construct(Dynamic MaxSize);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="PlayState")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< PlayState_obj > __new(Dynamic MaxSize);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PlayState_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_HCSTRING("PlayState","\x5d","\x83","\xc2","\x46"); }

		static void __boot();
		static Float STICK_MOVEMENT_RANGE;
		static Float TRIGGER_MOVEMENT_RANGE;
		static Float ALPHA_OFF;
		static Float ALPHA_ON;
		static Float LB_Y;
		static Float RB_Y;
		static ::flixel::util::FlxPoint LEFT_STICK_POS;
		static ::flixel::util::FlxPoint RIGHT_STICK_POS;
		static ::flixel::util::FlxPoint LEFT_TRIGGER_POS;
		static ::flixel::util::FlxPoint RIGHT_TRIGGER_POS;
		::flixel::FlxSprite _controllerBg;
		::flixel::FlxSprite _leftStick;
		::flixel::FlxSprite _rightStick;
		::flixel::FlxSprite _dPad;
		::flixel::FlxSprite _leftTrigger;
		::flixel::FlxSprite _rightTrigger;
		::flixel::FlxSprite _xButton;
		::flixel::FlxSprite _yButton;
		::flixel::FlxSprite _aButton;
		::flixel::FlxSprite _bButton;
		::flixel::FlxSprite _backButton;
		::flixel::FlxSprite _startButton;
		::flixel::FlxSprite _LB;
		::flixel::FlxSprite _RB;
		::flixel::input::gamepad::FlxGamepad _gamePad;
		::flixel::text::FlxText _hitText;
		::flixel::text::FlxText _missText;
		::flixel::_system::FlxSound _music;
		Float _musicBPM;
		Float _musicLength;
		Float _beatDelay;
		Float _beatDelta;
		Float _beatAcceptance;
		Float _beatInterval;
		bool _onBeat;
		bool _currentBeatLock;
		virtual Void create( );

		virtual ::flixel::FlxSprite createSprite( Float X,Float Y,::String Graphic,hx::Null< Float >  Alpha);
		Dynamic createSprite_dyn();

		virtual Void update( );

		virtual Void updateBeat( );
		Dynamic updateBeat_dyn();

		virtual Void updateTrigger( int tID,::flixel::FlxSprite triggerSprite,::flixel::util::FlxPoint triggerPosition);
		Dynamic updateTrigger_dyn();

		virtual Void updateAxis( int xID,int yID,::flixel::FlxSprite stickSprite,::flixel::util::FlxPoint stickPosition);
		Dynamic updateAxis_dyn();

		virtual Void updateDpad( );
		Dynamic updateDpad_dyn();

};


#endif /* INCLUDED_PlayState */ 
