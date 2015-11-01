#include <hxcpp.h>

#ifndef INCLUDED_GamepadIDs
#include <GamepadIDs.h>
#endif

Void GamepadIDs_obj::__construct()
{
	return null();
}

//GamepadIDs_obj::~GamepadIDs_obj() { }

Dynamic GamepadIDs_obj::__CreateEmpty() { return  new GamepadIDs_obj; }
hx::ObjectPtr< GamepadIDs_obj > GamepadIDs_obj::__new()
{  hx::ObjectPtr< GamepadIDs_obj > _result_ = new GamepadIDs_obj();
	_result_->__construct();
	return _result_;}

Dynamic GamepadIDs_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GamepadIDs_obj > _result_ = new GamepadIDs_obj();
	_result_->__construct();
	return _result_;}

int GamepadIDs_obj::A;

int GamepadIDs_obj::B;

int GamepadIDs_obj::X;

int GamepadIDs_obj::Y;

int GamepadIDs_obj::LB;

int GamepadIDs_obj::RB;

int GamepadIDs_obj::START;

int GamepadIDs_obj::SELECT;

int GamepadIDs_obj::LEFT_ANALOGUE;

int GamepadIDs_obj::RIGHT_ANALOGUE;

int GamepadIDs_obj::LEFT_ANALOGUE_X;

int GamepadIDs_obj::LEFT_ANALOGUE_Y;

int GamepadIDs_obj::RIGHT_ANALOGUE_X;

int GamepadIDs_obj::RIGHT_ANALOGUE_Y;

int GamepadIDs_obj::LEFT_TRIGGER;

int GamepadIDs_obj::RIGHT_TRIGGER;


GamepadIDs_obj::GamepadIDs_obj()
{
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsInt,(void *) &GamepadIDs_obj::A,HX_HCSTRING("A","\x41","\x00","\x00","\x00")},
	{hx::fsInt,(void *) &GamepadIDs_obj::B,HX_HCSTRING("B","\x42","\x00","\x00","\x00")},
	{hx::fsInt,(void *) &GamepadIDs_obj::X,HX_HCSTRING("X","\x58","\x00","\x00","\x00")},
	{hx::fsInt,(void *) &GamepadIDs_obj::Y,HX_HCSTRING("Y","\x59","\x00","\x00","\x00")},
	{hx::fsInt,(void *) &GamepadIDs_obj::LB,HX_HCSTRING("LB","\x76","\x42","\x00","\x00")},
	{hx::fsInt,(void *) &GamepadIDs_obj::RB,HX_HCSTRING("RB","\xb0","\x47","\x00","\x00")},
	{hx::fsInt,(void *) &GamepadIDs_obj::START,HX_HCSTRING("START","\x42","\xac","\xf9","\x01")},
	{hx::fsInt,(void *) &GamepadIDs_obj::SELECT,HX_HCSTRING("SELECT","\xfc","\xc6","\xb5","\x1c")},
	{hx::fsInt,(void *) &GamepadIDs_obj::LEFT_ANALOGUE,HX_HCSTRING("LEFT_ANALOGUE","\xf8","\x26","\x02","\x30")},
	{hx::fsInt,(void *) &GamepadIDs_obj::RIGHT_ANALOGUE,HX_HCSTRING("RIGHT_ANALOGUE","\xa3","\x14","\x81","\x3f")},
	{hx::fsInt,(void *) &GamepadIDs_obj::LEFT_ANALOGUE_X,HX_HCSTRING("LEFT_ANALOGUE_X","\x11","\x28","\x14","\xd2")},
	{hx::fsInt,(void *) &GamepadIDs_obj::LEFT_ANALOGUE_Y,HX_HCSTRING("LEFT_ANALOGUE_Y","\x12","\x28","\x14","\xd2")},
	{hx::fsInt,(void *) &GamepadIDs_obj::RIGHT_ANALOGUE_X,HX_HCSTRING("RIGHT_ANALOGUE_X","\x7c","\x16","\x6a","\xf1")},
	{hx::fsInt,(void *) &GamepadIDs_obj::RIGHT_ANALOGUE_Y,HX_HCSTRING("RIGHT_ANALOGUE_Y","\x7d","\x16","\x6a","\xf1")},
	{hx::fsInt,(void *) &GamepadIDs_obj::LEFT_TRIGGER,HX_HCSTRING("LEFT_TRIGGER","\xa0","\x31","\xc6","\xeb")},
	{hx::fsInt,(void *) &GamepadIDs_obj::RIGHT_TRIGGER,HX_HCSTRING("RIGHT_TRIGGER","\x55","\xe2","\x81","\x00")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::A,"A");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::B,"B");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::X,"X");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::Y,"Y");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::LB,"LB");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::RB,"RB");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::START,"START");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::SELECT,"SELECT");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::LEFT_ANALOGUE,"LEFT_ANALOGUE");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::RIGHT_ANALOGUE,"RIGHT_ANALOGUE");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::LEFT_ANALOGUE_X,"LEFT_ANALOGUE_X");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::LEFT_ANALOGUE_Y,"LEFT_ANALOGUE_Y");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::RIGHT_ANALOGUE_X,"RIGHT_ANALOGUE_X");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::RIGHT_ANALOGUE_Y,"RIGHT_ANALOGUE_Y");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::LEFT_TRIGGER,"LEFT_TRIGGER");
	HX_MARK_MEMBER_NAME(GamepadIDs_obj::RIGHT_TRIGGER,"RIGHT_TRIGGER");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::A,"A");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::B,"B");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::X,"X");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::Y,"Y");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::LB,"LB");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::RB,"RB");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::START,"START");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::SELECT,"SELECT");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::LEFT_ANALOGUE,"LEFT_ANALOGUE");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::RIGHT_ANALOGUE,"RIGHT_ANALOGUE");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::LEFT_ANALOGUE_X,"LEFT_ANALOGUE_X");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::LEFT_ANALOGUE_Y,"LEFT_ANALOGUE_Y");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::RIGHT_ANALOGUE_X,"RIGHT_ANALOGUE_X");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::RIGHT_ANALOGUE_Y,"RIGHT_ANALOGUE_Y");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::LEFT_TRIGGER,"LEFT_TRIGGER");
	HX_VISIT_MEMBER_NAME(GamepadIDs_obj::RIGHT_TRIGGER,"RIGHT_TRIGGER");
};

#endif

hx::Class GamepadIDs_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("A","\x41","\x00","\x00","\x00"),
	HX_HCSTRING("B","\x42","\x00","\x00","\x00"),
	HX_HCSTRING("X","\x58","\x00","\x00","\x00"),
	HX_HCSTRING("Y","\x59","\x00","\x00","\x00"),
	HX_HCSTRING("LB","\x76","\x42","\x00","\x00"),
	HX_HCSTRING("RB","\xb0","\x47","\x00","\x00"),
	HX_HCSTRING("START","\x42","\xac","\xf9","\x01"),
	HX_HCSTRING("SELECT","\xfc","\xc6","\xb5","\x1c"),
	HX_HCSTRING("LEFT_ANALOGUE","\xf8","\x26","\x02","\x30"),
	HX_HCSTRING("RIGHT_ANALOGUE","\xa3","\x14","\x81","\x3f"),
	HX_HCSTRING("LEFT_ANALOGUE_X","\x11","\x28","\x14","\xd2"),
	HX_HCSTRING("LEFT_ANALOGUE_Y","\x12","\x28","\x14","\xd2"),
	HX_HCSTRING("RIGHT_ANALOGUE_X","\x7c","\x16","\x6a","\xf1"),
	HX_HCSTRING("RIGHT_ANALOGUE_Y","\x7d","\x16","\x6a","\xf1"),
	HX_HCSTRING("LEFT_TRIGGER","\xa0","\x31","\xc6","\xeb"),
	HX_HCSTRING("RIGHT_TRIGGER","\x55","\xe2","\x81","\x00"),
	::String(null()) };

void GamepadIDs_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("GamepadIDs","\x57","\x1e","\xba","\xe8");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = hx::TCanCast< GamepadIDs_obj >;
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

void GamepadIDs_obj::__boot()
{
	A= (int)0;
	B= (int)1;
	X= (int)2;
	Y= (int)3;
	LB= (int)4;
	RB= (int)5;
	START= (int)7;
	SELECT= (int)6;
	LEFT_ANALOGUE= (int)8;
	RIGHT_ANALOGUE= (int)9;
	LEFT_ANALOGUE_X= (int)0;
	LEFT_ANALOGUE_Y= (int)1;
	RIGHT_ANALOGUE_X= (int)3;
	RIGHT_ANALOGUE_Y= (int)4;
	LEFT_TRIGGER= (int)2;
	RIGHT_TRIGGER= (int)5;
}

