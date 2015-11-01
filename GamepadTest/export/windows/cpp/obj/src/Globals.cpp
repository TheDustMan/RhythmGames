#include <hxcpp.h>

#ifndef INCLUDED_Globals
#include <Globals.h>
#endif

Void Globals_obj::__construct()
{
HX_STACK_FRAME("Globals","new",0x7f13d682,"Globals.new","Globals.hx",14,0x4ea1ef2e)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//Globals_obj::~Globals_obj() { }

Dynamic Globals_obj::__CreateEmpty() { return  new Globals_obj; }
hx::ObjectPtr< Globals_obj > Globals_obj::__new()
{  hx::ObjectPtr< Globals_obj > _result_ = new Globals_obj();
	_result_->__construct();
	return _result_;}

Dynamic Globals_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Globals_obj > _result_ = new Globals_obj();
	_result_->__construct();
	return _result_;}

int Globals_obj::gameWidth;

int Globals_obj::gameHeight;


Globals_obj::Globals_obj()
{
}

bool Globals_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"gameWidth") ) { outValue = gameWidth; return true;  }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gameHeight") ) { outValue = gameHeight; return true;  }
	}
	return false;
}

bool Globals_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"gameWidth") ) { gameWidth=ioValue.Cast< int >(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gameHeight") ) { gameHeight=ioValue.Cast< int >(); return true; }
	}
	return false;
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsInt,(void *) &Globals_obj::gameWidth,HX_HCSTRING("gameWidth","\xb4","\xa4","\x7d","\xff")},
	{hx::fsInt,(void *) &Globals_obj::gameHeight,HX_HCSTRING("gameHeight","\x79","\xf1","\xc1","\x44")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Globals_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Globals_obj::gameWidth,"gameWidth");
	HX_MARK_MEMBER_NAME(Globals_obj::gameHeight,"gameHeight");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Globals_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Globals_obj::gameWidth,"gameWidth");
	HX_VISIT_MEMBER_NAME(Globals_obj::gameHeight,"gameHeight");
};

#endif

hx::Class Globals_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("gameWidth","\xb4","\xa4","\x7d","\xff"),
	HX_HCSTRING("gameHeight","\x79","\xf1","\xc1","\x44"),
	::String(null()) };

void Globals_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("Globals","\x90","\x2d","\x8a","\xe1");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Globals_obj::__GetStatic;
	__mClass->mSetStaticField = &Globals_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = hx::TCanCast< Globals_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = sStaticStorageInfo;
#endif
	hx::RegisterClass(__mClass->mName, __mClass);
}

void Globals_obj::__boot()
{
	gameWidth= (int)526;
	gameHeight= (int)376;
}

