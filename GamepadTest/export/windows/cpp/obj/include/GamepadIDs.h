#ifndef INCLUDED_GamepadIDs
#define INCLUDED_GamepadIDs

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(GamepadIDs)


class HXCPP_CLASS_ATTRIBUTES  GamepadIDs_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GamepadIDs_obj OBJ_;
		GamepadIDs_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false,const char *inName="GamepadIDs")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< GamepadIDs_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GamepadIDs_obj();

		HX_DO_RTTI_ALL;
		static void __register();
		::String __ToString() const { return HX_HCSTRING("GamepadIDs","\x57","\x1e","\xba","\xe8"); }

		static void __boot();
		static int A;
		static int B;
		static int X;
		static int Y;
		static int LB;
		static int RB;
		static int START;
		static int SELECT;
		static int LEFT_ANALOGUE;
		static int RIGHT_ANALOGUE;
		static int LEFT_ANALOGUE_X;
		static int LEFT_ANALOGUE_Y;
		static int RIGHT_ANALOGUE_X;
		static int RIGHT_ANALOGUE_Y;
		static int LEFT_TRIGGER;
		static int RIGHT_TRIGGER;
};


#endif /* INCLUDED_GamepadIDs */ 
