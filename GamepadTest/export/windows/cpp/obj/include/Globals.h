#ifndef INCLUDED_Globals
#define INCLUDED_Globals

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Globals)


class HXCPP_CLASS_ATTRIBUTES  Globals_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Globals_obj OBJ_;
		Globals_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false,const char *inName="Globals")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< Globals_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Globals_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		static void __register();
		::String __ToString() const { return HX_HCSTRING("Globals","\x90","\x2d","\x8a","\xe1"); }

		static void __boot();
		static int gameWidth;
		static int gameHeight;
};


#endif /* INCLUDED_Globals */ 
