#include <hxcpp.h>

#include "hxMath.h"
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_input_gamepad_FlxGamepad
#include <flixel/input/gamepad/FlxGamepad.h>
#endif
#ifndef INCLUDED_flixel_input_gamepad_FlxGamepadManager
#include <flixel/input/gamepad/FlxGamepadManager.h>
#endif
#ifndef INCLUDED_flixel_input_mouse_FlxMouse
#include <flixel/input/mouse/FlxMouse.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_system_FlxSound
#include <flixel/system/FlxSound.h>
#endif
#ifndef INCLUDED_flixel_system_debug_FlxDebugger
#include <flixel/system/debug/FlxDebugger.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Watch
#include <flixel/system/debug/Watch.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Window
#include <flixel/system/debug/Window.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_CameraFrontEnd
#include <flixel/system/frontEnds/CameraFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_SoundFrontEnd
#include <flixel/system/frontEnds/SoundFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPool
#include <flixel/util/FlxPool.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_DisplayObject
#include <openfl/_legacy/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_DisplayObjectContainer
#include <openfl/_legacy/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_IBitmapDrawable
#include <openfl/_legacy/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_InteractiveObject
#include <openfl/_legacy/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_Sprite
#include <openfl/_legacy/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_EventDispatcher
#include <openfl/_legacy/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_IEventDispatcher
#include <openfl/_legacy/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__legacy_media_Sound
#include <openfl/_legacy/media/Sound.h>
#endif

Void PlayState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("PlayState","new",0xf8bf96cf,"PlayState.new","PlayState.hx",16,0xb30d7781)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(62)
	this->_currentBeatLock = false;
	HX_STACK_LINE(61)
	this->_onBeat = false;
	HX_STACK_LINE(16)
	Dynamic tmp = MaxSize;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(16)
	super::__construct(tmp);
}
;
	return null();
}

//PlayState_obj::~PlayState_obj() { }

Dynamic PlayState_obj::__CreateEmpty() { return  new PlayState_obj; }
hx::ObjectPtr< PlayState_obj > PlayState_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< PlayState_obj > _result_ = new PlayState_obj();
	_result_->__construct(MaxSize);
	return _result_;}

Dynamic PlayState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlayState_obj > _result_ = new PlayState_obj();
	_result_->__construct(inArgs[0]);
	return _result_;}

Void PlayState_obj::create( ){
{
		HX_STACK_FRAME("PlayState","create",0x82220fed,"PlayState.create","PlayState.hx",65,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(66)
		::flixel::_system::frontEnds::SoundFrontEnd tmp = ::flixel::FlxG_obj::sound;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(66)
		::flixel::_system::FlxSound tmp1 = tmp->__Field(HX_HCSTRING("load","\x26","\x9a","\xb7","\x47"), hx::paccDynamic )(HX_HCSTRING("assets/sounds/classic.ogg","\x34","\xb4","\xb5","\xab"),(int)1,true,false,true,null(),null());		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(66)
		this->_music = tmp1;
		HX_STACK_LINE(67)
		this->_musicBPM = (int)140;
		HX_STACK_LINE(68)
		::flixel::_system::FlxSound tmp2 = this->_music;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(68)
		Float tmp3 = tmp2->__Field(HX_HCSTRING("_sound","\x10","\xd4","\xb3","\x7c"), hx::paccDynamic )->__Field(HX_HCSTRING("get_length","\xaf","\x04","\x8f","\x8f"), hx::paccDynamic )();		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(68)
		this->_musicLength = tmp3;
		HX_STACK_LINE(69)
		Float tmp4 = this->_musicLength;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(69)
		::String tmp5 = (HX_HCSTRING("Length: ","\x2c","\x09","\x75","\xf9") + tmp4);		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(69)
		Dynamic tmp6 = hx::SourceInfo(HX_HCSTRING("PlayState.hx","\x81","\x77","\x0d","\xb3"),69,HX_HCSTRING("PlayState","\x5d","\x83","\xc2","\x46"),HX_HCSTRING("create","\xfc","\x66","\x0f","\x7c"));		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(69)
		::haxe::Log_obj::trace(tmp5,tmp6);
		HX_STACK_LINE(70)
		Float tmp7 = ((Float)0.42857142857142855);		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(70)
		Float tmp8 = (tmp7 * (int)1000);		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(70)
		this->_beatInterval = tmp8;
		HX_STACK_LINE(71)
		Float tmp9 = this->_beatInterval;		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(71)
		Float tmp10 = (Float(tmp9) / Float((int)10));		HX_STACK_VAR(tmp10,"tmp10");
		HX_STACK_LINE(71)
		this->_beatDelta = tmp10;
		HX_STACK_LINE(72)
		Float tmp11 = this->_beatDelta;		HX_STACK_VAR(tmp11,"tmp11");
		HX_STACK_LINE(72)
		Float tmp12 = (tmp11 * (int)5);		HX_STACK_VAR(tmp12,"tmp12");
		HX_STACK_LINE(72)
		this->_beatAcceptance = tmp12;
		HX_STACK_LINE(73)
		this->_beatDelay = ((Float)28.0);
		HX_STACK_LINE(74)
		this->_onBeat = false;
		HX_STACK_LINE(75)
		this->_currentBeatLock = false;
		HX_STACK_LINE(76)
		Float tmp13 = this->_beatInterval;		HX_STACK_VAR(tmp13,"tmp13");
		HX_STACK_LINE(76)
		Dynamic tmp14 = hx::SourceInfo(HX_HCSTRING("PlayState.hx","\x81","\x77","\x0d","\xb3"),76,HX_HCSTRING("PlayState","\x5d","\x83","\xc2","\x46"),HX_HCSTRING("create","\xfc","\x66","\x0f","\x7c"));		HX_STACK_VAR(tmp14,"tmp14");
		HX_STACK_LINE(76)
		::haxe::Log_obj::trace(tmp13,tmp14);
		HX_STACK_LINE(79)
		::flixel::input::mouse::FlxMouse tmp15 = ::flixel::FlxG_obj::mouse;		HX_STACK_VAR(tmp15,"tmp15");
		HX_STACK_LINE(79)
		tmp15->set_visible(false);
		HX_STACK_LINE(80)
		::flixel::_system::frontEnds::CameraFrontEnd tmp16 = ::flixel::FlxG_obj::cameras;		HX_STACK_VAR(tmp16,"tmp16");
		HX_STACK_LINE(80)
		tmp16->__Field(HX_HCSTRING("set_bgColor","\x81","\xe8","\xea","\x87"), hx::paccDynamic )((int)-1);
		HX_STACK_LINE(82)
		::flixel::FlxSprite tmp17 = this->createSprite((int)71,((Float)2),HX_HCSTRING("assets/images/LB.png","\x9c","\xbc","\x1f","\xc7"),((Float)0.8));		HX_STACK_VAR(tmp17,"tmp17");
		HX_STACK_LINE(82)
		this->_LB = tmp17;
		HX_STACK_LINE(83)
		::flixel::FlxSprite tmp18 = this->createSprite((int)367,((Float)2),HX_HCSTRING("assets/images/RB.png","\xd6","\xe6","\x43","\x2d"),((Float)0.8));		HX_STACK_VAR(tmp18,"tmp18");
		HX_STACK_LINE(83)
		this->_RB = tmp18;
		HX_STACK_LINE(85)
		::flixel::FlxSprite tmp19 = this->createSprite((int)0,(int)0,HX_HCSTRING("assets/images/xbox360_gamepad.png","\x0c","\x66","\xad","\x25"),(int)1);		HX_STACK_VAR(tmp19,"tmp19");
		HX_STACK_LINE(85)
		this->_controllerBg = tmp19;
		HX_STACK_LINE(87)
		::flixel::util::FlxPoint tmp20 = ::PlayState_obj::LEFT_TRIGGER_POS;		HX_STACK_VAR(tmp20,"tmp20");
		HX_STACK_LINE(87)
		Float tmp21 = tmp20->x;		HX_STACK_VAR(tmp21,"tmp21");
		HX_STACK_LINE(87)
		::flixel::util::FlxPoint tmp22 = ::PlayState_obj::LEFT_TRIGGER_POS;		HX_STACK_VAR(tmp22,"tmp22");
		HX_STACK_LINE(87)
		Float tmp23 = tmp22->y;		HX_STACK_VAR(tmp23,"tmp23");
		HX_STACK_LINE(87)
		::flixel::FlxSprite tmp24 = this->createSprite(tmp21,tmp23,HX_HCSTRING("assets/images/LB.png","\x9c","\xbc","\x1f","\xc7"),null());		HX_STACK_VAR(tmp24,"tmp24");
		HX_STACK_LINE(87)
		this->_leftTrigger = tmp24;
		HX_STACK_LINE(88)
		::flixel::util::FlxPoint tmp25 = ::PlayState_obj::RIGHT_TRIGGER_POS;		HX_STACK_VAR(tmp25,"tmp25");
		HX_STACK_LINE(88)
		Float tmp26 = tmp25->x;		HX_STACK_VAR(tmp26,"tmp26");
		HX_STACK_LINE(88)
		::flixel::util::FlxPoint tmp27 = ::PlayState_obj::RIGHT_TRIGGER_POS;		HX_STACK_VAR(tmp27,"tmp27");
		HX_STACK_LINE(88)
		Float tmp28 = tmp27->y;		HX_STACK_VAR(tmp28,"tmp28");
		HX_STACK_LINE(88)
		::flixel::FlxSprite tmp29 = this->createSprite(tmp26,tmp28,HX_HCSTRING("assets/images/RB.png","\xd6","\xe6","\x43","\x2d"),null());		HX_STACK_VAR(tmp29,"tmp29");
		HX_STACK_LINE(88)
		this->_rightTrigger = tmp29;
		HX_STACK_LINE(90)
		::flixel::util::FlxPoint tmp30 = ::PlayState_obj::LEFT_STICK_POS;		HX_STACK_VAR(tmp30,"tmp30");
		HX_STACK_LINE(90)
		Float tmp31 = tmp30->x;		HX_STACK_VAR(tmp31,"tmp31");
		HX_STACK_LINE(90)
		::flixel::util::FlxPoint tmp32 = ::PlayState_obj::LEFT_STICK_POS;		HX_STACK_VAR(tmp32,"tmp32");
		HX_STACK_LINE(90)
		Float tmp33 = tmp32->y;		HX_STACK_VAR(tmp33,"tmp33");
		HX_STACK_LINE(90)
		::flixel::FlxSprite tmp34 = this->createSprite(tmp31,tmp33,HX_HCSTRING("assets/images/Stick.png","\x60","\x59","\x32","\x55"),null());		HX_STACK_VAR(tmp34,"tmp34");
		HX_STACK_LINE(90)
		this->_leftStick = tmp34;
		HX_STACK_LINE(91)
		::flixel::util::FlxPoint tmp35 = ::PlayState_obj::RIGHT_STICK_POS;		HX_STACK_VAR(tmp35,"tmp35");
		HX_STACK_LINE(91)
		Float tmp36 = tmp35->x;		HX_STACK_VAR(tmp36,"tmp36");
		HX_STACK_LINE(91)
		::flixel::util::FlxPoint tmp37 = ::PlayState_obj::RIGHT_STICK_POS;		HX_STACK_VAR(tmp37,"tmp37");
		HX_STACK_LINE(91)
		Float tmp38 = tmp37->y;		HX_STACK_VAR(tmp38,"tmp38");
		HX_STACK_LINE(91)
		::flixel::FlxSprite tmp39 = this->createSprite(tmp36,tmp38,HX_HCSTRING("assets/images/Stick.png","\x60","\x59","\x32","\x55"),null());		HX_STACK_VAR(tmp39,"tmp39");
		HX_STACK_LINE(91)
		this->_rightStick = tmp39;
		HX_STACK_LINE(93)
		::flixel::FlxSprite tmp40 = ::flixel::FlxSprite_obj::__new((int)144,(int)126,null());		HX_STACK_VAR(tmp40,"tmp40");
		HX_STACK_LINE(93)
		this->_dPad = tmp40;
		HX_STACK_LINE(94)
		::flixel::FlxSprite tmp41 = this->_dPad;		HX_STACK_VAR(tmp41,"tmp41");
		HX_STACK_LINE(94)
		tmp41->loadGraphic(HX_HCSTRING("assets/images/DPad.png","\xd5","\x06","\xb4","\x69"),true,(int)87,(int)87,null(),null());
		HX_STACK_LINE(95)
		::flixel::FlxSprite tmp42 = this->_dPad;		HX_STACK_VAR(tmp42,"tmp42");
		HX_STACK_LINE(95)
		tmp42->set_alpha(((Float)0.5));
		HX_STACK_LINE(96)
		::flixel::FlxSprite tmp43 = this->_dPad;		HX_STACK_VAR(tmp43,"tmp43");
		HX_STACK_LINE(96)
		this->add(tmp43);
		HX_STACK_LINE(98)
		::flixel::FlxSprite tmp44 = this->createSprite((int)357,(int)70,HX_HCSTRING("assets/images/X.png","\x08","\x46","\xfa","\xbf"),null());		HX_STACK_VAR(tmp44,"tmp44");
		HX_STACK_LINE(98)
		this->_xButton = tmp44;
		HX_STACK_LINE(99)
		::flixel::FlxSprite tmp45 = this->createSprite((int)395,(int)34,HX_HCSTRING("assets/images/Y.png","\x89","\xda","\x60","\x53"),null());		HX_STACK_VAR(tmp45,"tmp45");
		HX_STACK_LINE(99)
		this->_yButton = tmp45;
		HX_STACK_LINE(100)
		::flixel::FlxSprite tmp46 = this->createSprite((int)395,(int)109,HX_HCSTRING("assets/images/A.png","\x71","\xee","\xc2","\x81"),null());		HX_STACK_VAR(tmp46,"tmp46");
		HX_STACK_LINE(100)
		this->_aButton = tmp46;
		HX_STACK_LINE(101)
		::flixel::FlxSprite tmp47 = this->createSprite((int)433,(int)70,HX_HCSTRING("assets/images/B.png","\xf2","\x82","\x29","\x15"),null());		HX_STACK_VAR(tmp47,"tmp47");
		HX_STACK_LINE(101)
		this->_bButton = tmp47;
		HX_STACK_LINE(103)
		::flixel::FlxSprite tmp48 = this->createSprite((int)199,(int)79,HX_HCSTRING("assets/images/Back.png","\xad","\xcd","\xc0","\x8e"),null());		HX_STACK_VAR(tmp48,"tmp48");
		HX_STACK_LINE(103)
		this->_backButton = tmp48;
		HX_STACK_LINE(104)
		::flixel::FlxSprite tmp49 = this->createSprite((int)306,(int)79,HX_HCSTRING("assets/images/Start.png","\x72","\x45","\x7c","\x36"),null());		HX_STACK_VAR(tmp49,"tmp49");
		HX_STACK_LINE(104)
		this->_startButton = tmp49;
		HX_STACK_LINE(105)
		::flixel::FlxSprite tmp50 = this->createSprite((int)306,(int)79,HX_HCSTRING("assets/images/Start.png","\x72","\x45","\x7c","\x36"),null());		HX_STACK_VAR(tmp50,"tmp50");
		HX_STACK_LINE(105)
		this->_startButton = tmp50;
		HX_STACK_LINE(107)
		::flixel::text::FlxText tmp51 = ::flixel::text::FlxText_obj::__new((int)60,(int)100,(int)100,HX_HCSTRING("HIT!","\x8e","\x0a","\xcf","\x2f"),(int)20,null());		HX_STACK_VAR(tmp51,"tmp51");
		HX_STACK_LINE(107)
		this->_hitText = tmp51;
		HX_STACK_LINE(108)
		::flixel::text::FlxText tmp52 = ::flixel::text::FlxText_obj::__new((int)120,(int)100,(int)100,HX_HCSTRING("MISS!","\xa5","\x81","\x5a","\x86"),(int)20,null());		HX_STACK_VAR(tmp52,"tmp52");
		HX_STACK_LINE(108)
		this->_missText = tmp52;
		HX_STACK_LINE(109)
		::flixel::text::FlxText tmp53 = this->_hitText;		HX_STACK_VAR(tmp53,"tmp53");
		HX_STACK_LINE(109)
		tmp53->set_color((int)65280);
		HX_STACK_LINE(110)
		::flixel::text::FlxText tmp54 = this->_missText;		HX_STACK_VAR(tmp54,"tmp54");
		HX_STACK_LINE(110)
		tmp54->set_color((int)16711680);
		HX_STACK_LINE(111)
		::flixel::text::FlxText tmp55 = this->_hitText;		HX_STACK_VAR(tmp55,"tmp55");
		HX_STACK_LINE(111)
		tmp55->set_visible(false);
		HX_STACK_LINE(112)
		::flixel::text::FlxText tmp56 = this->_missText;		HX_STACK_VAR(tmp56,"tmp56");
		HX_STACK_LINE(112)
		tmp56->set_visible(false);
		HX_STACK_LINE(113)
		::flixel::text::FlxText tmp57 = this->_hitText;		HX_STACK_VAR(tmp57,"tmp57");
		HX_STACK_LINE(113)
		this->add(tmp57);
		HX_STACK_LINE(114)
		::flixel::text::FlxText tmp58 = this->_missText;		HX_STACK_VAR(tmp58,"tmp58");
		HX_STACK_LINE(114)
		this->add(tmp58);
		HX_STACK_LINE(116)
		::flixel::FlxSprite tmp59 = this->_startButton;		HX_STACK_VAR(tmp59,"tmp59");
		HX_STACK_LINE(116)
		tmp59->set_alpha(((Float)0.5));
		HX_STACK_LINE(117)
		::flixel::FlxSprite tmp60 = this->_backButton;		HX_STACK_VAR(tmp60,"tmp60");
		HX_STACK_LINE(117)
		tmp60->set_alpha(((Float)0.5));
	}
return null();
}


::flixel::FlxSprite PlayState_obj::createSprite( Float X,Float Y,::String Graphic,hx::Null< Float >  __o_Alpha){
Float Alpha = __o_Alpha.Default(-1);
	HX_STACK_FRAME("PlayState","createSprite",0x01208fd2,"PlayState.createSprite","PlayState.hx",121,0xb30d7781)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_ARG(Graphic,"Graphic")
	HX_STACK_ARG(Alpha,"Alpha")
{
		HX_STACK_LINE(122)
		bool tmp = (Alpha == (int)-1);		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(122)
		if ((tmp)){
			HX_STACK_LINE(124)
			Alpha = ((Float)0.5);
		}
		HX_STACK_LINE(127)
		::flixel::FlxSprite tmp1 = ::flixel::FlxSprite_obj::__new(X,Y,Graphic);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(127)
		::flixel::FlxSprite button = tmp1;		HX_STACK_VAR(button,"button");
		HX_STACK_LINE(128)
		Float tmp2 = Alpha;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(128)
		button->set_alpha(tmp2);
		HX_STACK_LINE(129)
		::flixel::FlxSprite tmp3 = button;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(129)
		this->add(tmp3);
		HX_STACK_LINE(131)
		::flixel::FlxSprite tmp4 = button;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(131)
		return tmp4;
	}
}


HX_DEFINE_DYNAMIC_FUNC4(PlayState_obj,createSprite,return )

Void PlayState_obj::update( ){
{
		HX_STACK_FRAME("PlayState","update",0x8d182efa,"PlayState.update","PlayState.hx",135,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(136)
		this->super::update();
		HX_STACK_LINE(138)
		::flixel::input::gamepad::FlxGamepadManager tmp = ::flixel::FlxG_obj::gamepads;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(138)
		this->_gamePad = tmp->lastActive;
		HX_STACK_LINE(140)
		::flixel::input::gamepad::FlxGamepad tmp1 = this->_gamePad;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(140)
		bool tmp2 = (tmp1 == null());		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(140)
		if ((tmp2)){
			HX_STACK_LINE(141)
			return null();
		}
		HX_STACK_LINE(145)
		{
			HX_STACK_LINE(145)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(145)
			int tmp4 = tmp3->firstPressedButtonID();		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(145)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(145)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(145)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(145)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(145)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("pressed ID","\x99","\x86","\xd5","\xb3"),tmp7);
		}
		HX_STACK_LINE(146)
		{
			HX_STACK_LINE(146)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(146)
			int tmp4 = tmp3->firstJustReleasedButtonID();		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(146)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(146)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(146)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(146)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(146)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("released ID","\x5e","\x53","\x83","\xf5"),tmp7);
		}
		HX_STACK_LINE(147)
		{
			HX_STACK_LINE(147)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(147)
			int tmp4 = tmp3->firstJustPressedButtonID();		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(147)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(147)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(147)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(147)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(147)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("justPressed ID","\xe5","\x43","\x0b","\x15"),tmp7);
		}
		HX_STACK_LINE(148)
		{
			HX_STACK_LINE(148)
			::flixel::FlxGame tmp3 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(148)
			::flixel::_system::debug::Watch tmp4 = tmp3->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(148)
			::flixel::input::gamepad::FlxGamepad tmp5 = this->_gamePad;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(148)
			::flixel::util::FlxPoint tmp6 = tmp5->hat;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(148)
			tmp4->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("HAT","\x3b","\xdb","\x36","\x00"),tmp6);
		}
		HX_STACK_LINE(150)
		{
			HX_STACK_LINE(150)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(150)
			Float tmp4 = tmp3->getAxisValue((int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(150)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(150)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(150)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(150)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(150)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz0x","\xf0","\xc0","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(151)
		{
			HX_STACK_LINE(151)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(151)
			Float tmp4 = tmp3->getYAxis((int)0);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(151)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(151)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(151)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(151)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(151)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz0y","\xf1","\xc0","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(152)
		{
			HX_STACK_LINE(152)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(152)
			Float tmp4 = tmp3->getAxisValue((int)1);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(152)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(152)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(152)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(152)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(152)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz1x","\xcf","\xc1","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(153)
		{
			HX_STACK_LINE(153)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(153)
			Float tmp4 = tmp3->getYAxis((int)1);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(153)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(153)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(153)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(153)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(153)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz1y","\xd0","\xc1","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(154)
		{
			HX_STACK_LINE(154)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(154)
			Float tmp4 = tmp3->getAxisValue((int)2);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(154)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(154)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(154)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(154)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(154)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz2x","\xae","\xc2","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(155)
		{
			HX_STACK_LINE(155)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(155)
			Float tmp4 = tmp3->getYAxis((int)2);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(155)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(155)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(155)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(155)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(155)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz2y","\xaf","\xc2","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(156)
		{
			HX_STACK_LINE(156)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(156)
			Float tmp4 = tmp3->getAxisValue((int)3);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(156)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(156)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(156)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(156)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(156)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz3x","\x8d","\xc3","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(157)
		{
			HX_STACK_LINE(157)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(157)
			Float tmp4 = tmp3->getYAxis((int)3);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(157)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(157)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(157)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(157)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(157)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz3y","\x8e","\xc3","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(158)
		{
			HX_STACK_LINE(158)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(158)
			Float tmp4 = tmp3->getAxisValue((int)4);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(158)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(158)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(158)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(158)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(158)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz4x","\x6c","\xc4","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(159)
		{
			HX_STACK_LINE(159)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(159)
			Float tmp4 = tmp3->getYAxis((int)4);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(159)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(159)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(159)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(159)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(159)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz4y","\x6d","\xc4","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(160)
		{
			HX_STACK_LINE(160)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(160)
			Float tmp4 = tmp3->getAxisValue((int)5);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(160)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(160)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(160)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(160)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(160)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz5x","\x4b","\xc5","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(161)
		{
			HX_STACK_LINE(161)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(161)
			Float tmp4 = tmp3->getYAxis((int)5);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(161)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(161)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(161)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(161)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(161)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz5y","\x4c","\xc5","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(162)
		{
			HX_STACK_LINE(162)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(162)
			Float tmp4 = tmp3->getAxisValue((int)6);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(162)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(162)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(162)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(162)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(162)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz6x","\x2a","\xc6","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(163)
		{
			HX_STACK_LINE(163)
			::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(163)
			Float tmp4 = tmp3->getYAxis((int)6);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(163)
			Dynamic NewValue = tmp4;		HX_STACK_VAR(NewValue,"NewValue");
			HX_STACK_LINE(163)
			::flixel::FlxGame tmp5 = ::flixel::FlxG_obj::game;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(163)
			::flixel::_system::debug::Watch tmp6 = tmp5->debugger->__Field(HX_HCSTRING("watch","\x4f","\x16","\x25","\xc5"), hx::paccDynamic );		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(163)
			Dynamic tmp7 = NewValue;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(163)
			tmp6->__Field(HX_HCSTRING("updateQuickWatch","\x8b","\x93","\x1f","\x3e"), hx::paccDynamic )(HX_HCSTRING("axiz6y","\x2b","\xc6","\x77","\x26"),tmp7);
		}
		HX_STACK_LINE(166)
		::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(166)
		bool tmp4 = tmp3->justPressed((int)0);		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(166)
		if ((tmp4)){
			HX_STACK_LINE(167)
			::flixel::FlxSprite tmp5 = this->_aButton;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(167)
			tmp5->set_alpha(((Float)1));
			HX_STACK_LINE(169)
			bool tmp6 = this->_onBeat;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(169)
			if ((tmp6)){
				HX_STACK_LINE(170)
				::flixel::text::FlxText tmp7 = this->_hitText;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(170)
				tmp7->set_visible(true);
				HX_STACK_LINE(171)
				::flixel::text::FlxText tmp8 = this->_missText;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(171)
				tmp8->set_visible(false);
				HX_STACK_LINE(172)
				this->_currentBeatLock = true;
			}
			else{
				HX_STACK_LINE(174)
				::flixel::text::FlxText tmp7 = this->_hitText;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(174)
				tmp7->set_visible(false);
				HX_STACK_LINE(175)
				::flixel::text::FlxText tmp8 = this->_missText;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(175)
				tmp8->set_visible(true);
			}
		}
		HX_STACK_LINE(190)
		::flixel::input::gamepad::FlxGamepad tmp5 = this->_gamePad;		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(190)
		bool tmp6 = tmp5->pressed((int)1);		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(190)
		if ((tmp6)){
			HX_STACK_LINE(191)
			::flixel::FlxSprite tmp7 = this->_bButton;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(191)
			tmp7->set_alpha(((Float)1));
		}
		else{
			HX_STACK_LINE(193)
			::flixel::FlxSprite tmp7 = this->_bButton;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(193)
			tmp7->set_alpha(((Float)0.5));
		}
		HX_STACK_LINE(195)
		::flixel::input::gamepad::FlxGamepad tmp7 = this->_gamePad;		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(195)
		bool tmp8 = tmp7->pressed((int)2);		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(195)
		if ((tmp8)){
			HX_STACK_LINE(196)
			::flixel::FlxSprite tmp9 = this->_xButton;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(196)
			tmp9->set_alpha(((Float)1));
		}
		else{
			HX_STACK_LINE(198)
			::flixel::FlxSprite tmp9 = this->_xButton;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(198)
			tmp9->set_alpha(((Float)0.5));
		}
		HX_STACK_LINE(200)
		::flixel::input::gamepad::FlxGamepad tmp9 = this->_gamePad;		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(200)
		bool tmp10 = tmp9->pressed((int)3);		HX_STACK_VAR(tmp10,"tmp10");
		HX_STACK_LINE(200)
		if ((tmp10)){
			HX_STACK_LINE(201)
			::flixel::FlxSprite tmp11 = this->_yButton;		HX_STACK_VAR(tmp11,"tmp11");
			HX_STACK_LINE(201)
			tmp11->set_alpha(((Float)1));
		}
		else{
			HX_STACK_LINE(203)
			::flixel::FlxSprite tmp11 = this->_yButton;		HX_STACK_VAR(tmp11,"tmp11");
			HX_STACK_LINE(203)
			tmp11->set_alpha(((Float)0.5));
		}
		HX_STACK_LINE(205)
		::flixel::input::gamepad::FlxGamepad tmp11 = this->_gamePad;		HX_STACK_VAR(tmp11,"tmp11");
		HX_STACK_LINE(205)
		bool tmp12 = tmp11->pressed((int)7);		HX_STACK_VAR(tmp12,"tmp12");
		HX_STACK_LINE(205)
		if ((tmp12)){
			HX_STACK_LINE(206)
			::flixel::FlxSprite tmp13 = this->_startButton;		HX_STACK_VAR(tmp13,"tmp13");
			HX_STACK_LINE(206)
			tmp13->set_alpha(((Float)1));
		}
		else{
			HX_STACK_LINE(208)
			::flixel::FlxSprite tmp13 = this->_startButton;		HX_STACK_VAR(tmp13,"tmp13");
			HX_STACK_LINE(208)
			tmp13->set_alpha(((Float)0.5));
		}
		HX_STACK_LINE(210)
		::flixel::input::gamepad::FlxGamepad tmp13 = this->_gamePad;		HX_STACK_VAR(tmp13,"tmp13");
		HX_STACK_LINE(210)
		bool tmp14 = tmp13->pressed((int)6);		HX_STACK_VAR(tmp14,"tmp14");
		HX_STACK_LINE(210)
		if ((tmp14)){
			HX_STACK_LINE(211)
			::flixel::FlxSprite tmp15 = this->_backButton;		HX_STACK_VAR(tmp15,"tmp15");
			HX_STACK_LINE(211)
			tmp15->set_alpha(((Float)1));
		}
		else{
			HX_STACK_LINE(213)
			::flixel::FlxSprite tmp15 = this->_backButton;		HX_STACK_VAR(tmp15,"tmp15");
			HX_STACK_LINE(213)
			tmp15->set_alpha(((Float)0.5));
		}
		HX_STACK_LINE(215)
		::flixel::input::gamepad::FlxGamepad tmp15 = this->_gamePad;		HX_STACK_VAR(tmp15,"tmp15");
		HX_STACK_LINE(215)
		bool tmp16 = tmp15->pressed((int)4);		HX_STACK_VAR(tmp16,"tmp16");
		HX_STACK_LINE(215)
		if ((tmp16)){
			HX_STACK_LINE(216)
			::flixel::FlxSprite tmp17 = this->_LB;		HX_STACK_VAR(tmp17,"tmp17");
			HX_STACK_LINE(216)
			int tmp18 = ((Float)7.);		HX_STACK_VAR(tmp18,"tmp18");
			HX_STACK_LINE(216)
			tmp17->set_y(tmp18);
		}
		else{
			HX_STACK_LINE(218)
			::flixel::FlxSprite tmp17 = this->_LB;		HX_STACK_VAR(tmp17,"tmp17");
			HX_STACK_LINE(218)
			tmp17->set_y(((Float)2));
		}
		HX_STACK_LINE(220)
		::flixel::input::gamepad::FlxGamepad tmp17 = this->_gamePad;		HX_STACK_VAR(tmp17,"tmp17");
		HX_STACK_LINE(220)
		bool tmp18 = tmp17->pressed((int)5);		HX_STACK_VAR(tmp18,"tmp18");
		HX_STACK_LINE(220)
		if ((tmp18)){
			HX_STACK_LINE(221)
			::flixel::FlxSprite tmp19 = this->_RB;		HX_STACK_VAR(tmp19,"tmp19");
			HX_STACK_LINE(221)
			int tmp20 = ((Float)7.);		HX_STACK_VAR(tmp20,"tmp20");
			HX_STACK_LINE(221)
			tmp19->set_y(tmp20);
		}
		else{
			HX_STACK_LINE(223)
			::flixel::FlxSprite tmp19 = this->_RB;		HX_STACK_VAR(tmp19,"tmp19");
			HX_STACK_LINE(223)
			tmp19->set_y(((Float)2));
		}
		HX_STACK_LINE(225)
		::flixel::FlxSprite tmp19 = this->_leftStick;		HX_STACK_VAR(tmp19,"tmp19");
		HX_STACK_LINE(225)
		::flixel::util::FlxPoint tmp20 = ::PlayState_obj::LEFT_STICK_POS;		HX_STACK_VAR(tmp20,"tmp20");
		HX_STACK_LINE(225)
		this->updateAxis((int)0,(int)1,tmp19,tmp20);
		HX_STACK_LINE(226)
		::flixel::FlxSprite tmp21 = this->_rightStick;		HX_STACK_VAR(tmp21,"tmp21");
		HX_STACK_LINE(226)
		::flixel::util::FlxPoint tmp22 = ::PlayState_obj::RIGHT_STICK_POS;		HX_STACK_VAR(tmp22,"tmp22");
		HX_STACK_LINE(226)
		this->updateAxis((int)3,(int)4,tmp21,tmp22);
		HX_STACK_LINE(227)
		::flixel::FlxSprite tmp23 = this->_rightStick;		HX_STACK_VAR(tmp23,"tmp23");
		HX_STACK_LINE(227)
		::flixel::util::FlxPoint tmp24 = ::PlayState_obj::RIGHT_STICK_POS;		HX_STACK_VAR(tmp24,"tmp24");
		HX_STACK_LINE(227)
		this->updateAxis((int)3,(int)4,tmp23,tmp24);
		HX_STACK_LINE(228)
		::flixel::FlxSprite tmp25 = this->_rightStick;		HX_STACK_VAR(tmp25,"tmp25");
		HX_STACK_LINE(228)
		::flixel::util::FlxPoint tmp26 = ::PlayState_obj::RIGHT_STICK_POS;		HX_STACK_VAR(tmp26,"tmp26");
		HX_STACK_LINE(228)
		this->updateAxis((int)3,(int)4,tmp25,tmp26);
		HX_STACK_LINE(229)
		::flixel::FlxSprite tmp27 = this->_rightTrigger;		HX_STACK_VAR(tmp27,"tmp27");
		HX_STACK_LINE(229)
		::flixel::util::FlxPoint tmp28 = ::PlayState_obj::RIGHT_TRIGGER_POS;		HX_STACK_VAR(tmp28,"tmp28");
		HX_STACK_LINE(229)
		this->updateTrigger((int)5,tmp27,tmp28);
		HX_STACK_LINE(230)
		::flixel::FlxSprite tmp29 = this->_leftTrigger;		HX_STACK_VAR(tmp29,"tmp29");
		HX_STACK_LINE(230)
		::flixel::util::FlxPoint tmp30 = ::PlayState_obj::LEFT_TRIGGER_POS;		HX_STACK_VAR(tmp30,"tmp30");
		HX_STACK_LINE(230)
		this->updateTrigger((int)2,tmp29,tmp30);
		HX_STACK_LINE(232)
		this->updateDpad();
		HX_STACK_LINE(234)
		this->updateBeat();
	}
return null();
}


Void PlayState_obj::updateBeat( ){
{
		HX_STACK_FRAME("PlayState","updateBeat",0x85e14190,"PlayState.updateBeat","PlayState.hx",238,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(239)
		::flixel::_system::FlxSound tmp = this->_music;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(239)
		Float tmp1 = tmp->__Field(HX_HCSTRING("time","\x0d","\xcc","\xfc","\x4c"), hx::paccDynamic );		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(239)
		Float tmp2 = this->_beatDelay;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(239)
		Float tmp3 = (tmp1 + tmp2);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(239)
		Float tmp4 = this->_beatInterval;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(239)
		Float tmp5 = hx::Mod(tmp3,tmp4);		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(239)
		Float currentBeatTimingValue = tmp5;		HX_STACK_VAR(currentBeatTimingValue,"currentBeatTimingValue");
		HX_STACK_LINE(241)
		Float tmp6 = currentBeatTimingValue;		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(241)
		Float tmp7 = this->_beatDelta;		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(241)
		bool tmp8 = (tmp6 < tmp7);		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(241)
		if ((tmp8)){
			HX_STACK_LINE(242)
			::flixel::FlxSprite tmp9 = this->_controllerBg;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(242)
			tmp9->set_y(((Float)5.0));
		}
		else{
			HX_STACK_LINE(244)
			::flixel::FlxSprite tmp9 = this->_controllerBg;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(244)
			tmp9->set_y((int)0);
		}
		HX_STACK_LINE(248)
		Float tmp9 = currentBeatTimingValue;		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(248)
		Float tmp10 = this->_beatAcceptance;		HX_STACK_VAR(tmp10,"tmp10");
		HX_STACK_LINE(248)
		bool tmp11 = (tmp9 < tmp10);		HX_STACK_VAR(tmp11,"tmp11");
		HX_STACK_LINE(248)
		if ((tmp11)){
			HX_STACK_LINE(249)
			bool tmp12 = this->_onBeat;		HX_STACK_VAR(tmp12,"tmp12");
			HX_STACK_LINE(249)
			bool tmp13 = !(tmp12);		HX_STACK_VAR(tmp13,"tmp13");
			HX_STACK_LINE(249)
			if ((tmp13)){
				HX_STACK_LINE(250)
				::flixel::text::FlxText tmp14 = this->_hitText;		HX_STACK_VAR(tmp14,"tmp14");
				HX_STACK_LINE(250)
				tmp14->set_visible(false);
				HX_STACK_LINE(251)
				::flixel::text::FlxText tmp15 = this->_missText;		HX_STACK_VAR(tmp15,"tmp15");
				HX_STACK_LINE(251)
				tmp15->set_visible(false);
				HX_STACK_LINE(252)
				this->_currentBeatLock = false;
			}
			HX_STACK_LINE(254)
			this->_onBeat = true;
		}
		else{
			HX_STACK_LINE(256)
			this->_onBeat = false;
			HX_STACK_LINE(257)
			bool tmp12 = this->_currentBeatLock;		HX_STACK_VAR(tmp12,"tmp12");
			HX_STACK_LINE(257)
			bool tmp13 = !(tmp12);		HX_STACK_VAR(tmp13,"tmp13");
			HX_STACK_LINE(257)
			if ((tmp13)){
				HX_STACK_LINE(259)
				::flixel::text::FlxText tmp14 = this->_hitText;		HX_STACK_VAR(tmp14,"tmp14");
				HX_STACK_LINE(259)
				tmp14->set_visible(false);
				HX_STACK_LINE(260)
				::flixel::text::FlxText tmp15 = this->_missText;		HX_STACK_VAR(tmp15,"tmp15");
				HX_STACK_LINE(260)
				tmp15->set_visible(true);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,updateBeat,(void))

Void PlayState_obj::updateTrigger( int tID,::flixel::FlxSprite triggerSprite,::flixel::util::FlxPoint triggerPosition){
{
		HX_STACK_FRAME("PlayState","updateTrigger",0xa4dd815e,"PlayState.updateTrigger","PlayState.hx",266,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(tID,"tID")
		HX_STACK_ARG(triggerSprite,"triggerSprite")
		HX_STACK_ARG(triggerPosition,"triggerPosition")
		HX_STACK_LINE(267)
		::flixel::input::gamepad::FlxGamepad tmp = this->_gamePad;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(267)
		int tmp1 = tID;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(267)
		Float tmp2 = tmp->getAxisValue(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(267)
		Float tAxisValue = tmp2;		HX_STACK_VAR(tAxisValue,"tAxisValue");
		HX_STACK_LINE(268)
		bool tmp3 = (tAxisValue > (int)-1);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(268)
		if ((tmp3)){
			HX_STACK_LINE(269)
			Float tmp4 = triggerPosition->y;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(269)
			Float tmp5 = (tAxisValue + (int)1);		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(269)
			Float tmp6 = (Float(tmp5) / Float((int)2));		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(269)
			Float tmp7 = (tmp6 * ((Float)10));		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(269)
			Float tmp8 = (tmp4 + tmp7);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(269)
			Float newYPosition = tmp8;		HX_STACK_VAR(newYPosition,"newYPosition");
			HX_STACK_LINE(270)
			Float tmp9 = newYPosition;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(270)
			triggerSprite->set_y(tmp9);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(PlayState_obj,updateTrigger,(void))

Void PlayState_obj::updateAxis( int xID,int yID,::flixel::FlxSprite stickSprite,::flixel::util::FlxPoint stickPosition){
{
		HX_STACK_FRAME("PlayState","updateAxis",0x85467cbb,"PlayState.updateAxis","PlayState.hx",275,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(xID,"xID")
		HX_STACK_ARG(yID,"yID")
		HX_STACK_ARG(stickSprite,"stickSprite")
		HX_STACK_ARG(stickPosition,"stickPosition")
		HX_STACK_LINE(276)
		::flixel::input::gamepad::FlxGamepad tmp = this->_gamePad;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(276)
		int tmp1 = xID;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(276)
		Float tmp2 = tmp->getAxisValue(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(276)
		Float xAxisValue = tmp2;		HX_STACK_VAR(xAxisValue,"xAxisValue");
		HX_STACK_LINE(277)
		::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(277)
		int tmp4 = yID;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(277)
		Float tmp5 = tmp3->getYAxis(tmp4);		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(277)
		Float yAxisValue = tmp5;		HX_STACK_VAR(yAxisValue,"yAxisValue");
		HX_STACK_LINE(278)
		Float angle;		HX_STACK_VAR(angle,"angle");
		HX_STACK_LINE(280)
		bool tmp6 = (xAxisValue != (int)0);		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(280)
		bool tmp7 = !(tmp6);		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(280)
		bool tmp8;		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(280)
		if ((tmp7)){
			HX_STACK_LINE(280)
			tmp8 = (yAxisValue != (int)0);
		}
		else{
			HX_STACK_LINE(280)
			tmp8 = true;
		}
		HX_STACK_LINE(280)
		if ((tmp8)){
			HX_STACK_LINE(282)
			Float tmp9 = yAxisValue;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(282)
			Float tmp10 = xAxisValue;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(282)
			Float tmp11 = ::Math_obj::atan2(tmp9,tmp10);		HX_STACK_VAR(tmp11,"tmp11");
			HX_STACK_LINE(282)
			angle = tmp11;
			HX_STACK_LINE(283)
			Float tmp12 = stickPosition->x;		HX_STACK_VAR(tmp12,"tmp12");
			HX_STACK_LINE(283)
			Float tmp13 = xAxisValue;		HX_STACK_VAR(tmp13,"tmp13");
			HX_STACK_LINE(283)
			Float tmp14 = ::Math_obj::abs(tmp13);		HX_STACK_VAR(tmp14,"tmp14");
			HX_STACK_LINE(283)
			Float tmp15 = (tmp14 * ((Float)10));		HX_STACK_VAR(tmp15,"tmp15");
			HX_STACK_LINE(283)
			Float tmp16 = angle;		HX_STACK_VAR(tmp16,"tmp16");
			HX_STACK_LINE(283)
			Float tmp17 = ::Math_obj::cos(tmp16);		HX_STACK_VAR(tmp17,"tmp17");
			HX_STACK_LINE(283)
			Float tmp18 = (tmp15 * tmp17);		HX_STACK_VAR(tmp18,"tmp18");
			HX_STACK_LINE(283)
			Float tmp19 = (tmp12 + tmp18);		HX_STACK_VAR(tmp19,"tmp19");
			HX_STACK_LINE(283)
			stickSprite->set_x(tmp19);
			HX_STACK_LINE(284)
			Float tmp20 = stickPosition->y;		HX_STACK_VAR(tmp20,"tmp20");
			HX_STACK_LINE(284)
			Float tmp21 = yAxisValue;		HX_STACK_VAR(tmp21,"tmp21");
			HX_STACK_LINE(284)
			Float tmp22 = ::Math_obj::abs(tmp21);		HX_STACK_VAR(tmp22,"tmp22");
			HX_STACK_LINE(284)
			Float tmp23 = (tmp22 * ((Float)10));		HX_STACK_VAR(tmp23,"tmp23");
			HX_STACK_LINE(284)
			Float tmp24 = angle;		HX_STACK_VAR(tmp24,"tmp24");
			HX_STACK_LINE(284)
			Float tmp25 = ::Math_obj::sin(tmp24);		HX_STACK_VAR(tmp25,"tmp25");
			HX_STACK_LINE(284)
			Float tmp26 = (tmp23 * tmp25);		HX_STACK_VAR(tmp26,"tmp26");
			HX_STACK_LINE(284)
			Float tmp27 = (tmp20 + tmp26);		HX_STACK_VAR(tmp27,"tmp27");
			HX_STACK_LINE(284)
			stickSprite->set_y(tmp27);
			HX_STACK_LINE(285)
			stickSprite->set_alpha(((Float)1));
		}
		else{
			HX_STACK_LINE(289)
			Float tmp9 = stickPosition->x;		HX_STACK_VAR(tmp9,"tmp9");
			HX_STACK_LINE(289)
			stickSprite->set_x(tmp9);
			HX_STACK_LINE(290)
			Float tmp10 = stickPosition->y;		HX_STACK_VAR(tmp10,"tmp10");
			HX_STACK_LINE(290)
			stickSprite->set_y(tmp10);
			HX_STACK_LINE(291)
			stickSprite->set_alpha(((Float)0.5));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(PlayState_obj,updateAxis,(void))

Void PlayState_obj::updateDpad( ){
{
		HX_STACK_FRAME("PlayState","updateDpad",0x873c0789,"PlayState.updateDpad","PlayState.hx",296,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(297)
		::flixel::input::gamepad::FlxGamepad tmp = this->_gamePad;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(297)
		Float tmp1 = tmp->hat->x;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(297)
		bool tmp2 = (tmp1 < (int)0);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(297)
		bool dpadLeft = tmp2;		HX_STACK_VAR(dpadLeft,"dpadLeft");
		HX_STACK_LINE(298)
		::flixel::input::gamepad::FlxGamepad tmp3 = this->_gamePad;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(298)
		Float tmp4 = tmp3->hat->x;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(298)
		bool tmp5 = (tmp4 > (int)0);		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(298)
		bool dpadRight = tmp5;		HX_STACK_VAR(dpadRight,"dpadRight");
		HX_STACK_LINE(299)
		::flixel::input::gamepad::FlxGamepad tmp6 = this->_gamePad;		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(299)
		Float tmp7 = tmp6->hat->y;		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(299)
		bool tmp8 = (tmp7 < (int)0);		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(299)
		bool dpadUp = tmp8;		HX_STACK_VAR(dpadUp,"dpadUp");
		HX_STACK_LINE(300)
		::flixel::input::gamepad::FlxGamepad tmp9 = this->_gamePad;		HX_STACK_VAR(tmp9,"tmp9");
		HX_STACK_LINE(300)
		Float tmp10 = tmp9->hat->y;		HX_STACK_VAR(tmp10,"tmp10");
		HX_STACK_LINE(300)
		bool tmp11 = (tmp10 > (int)0);		HX_STACK_VAR(tmp11,"tmp11");
		HX_STACK_LINE(300)
		bool dpadDown = tmp11;		HX_STACK_VAR(dpadDown,"dpadDown");
		HX_STACK_LINE(301)
		int newIndex = (int)0;		HX_STACK_VAR(newIndex,"newIndex");
		HX_STACK_LINE(302)
		Float newAlpha = ((Float)0.5);		HX_STACK_VAR(newAlpha,"newAlpha");
		HX_STACK_LINE(304)
		bool tmp12 = dpadLeft;		HX_STACK_VAR(tmp12,"tmp12");
		HX_STACK_LINE(304)
		bool tmp13 = !(tmp12);		HX_STACK_VAR(tmp13,"tmp13");
		HX_STACK_LINE(304)
		bool tmp14 = tmp13;		HX_STACK_VAR(tmp14,"tmp14");
		HX_STACK_LINE(304)
		bool tmp15;		HX_STACK_VAR(tmp15,"tmp15");
		HX_STACK_LINE(304)
		if ((tmp14)){
			HX_STACK_LINE(304)
			tmp15 = dpadRight;
		}
		else{
			HX_STACK_LINE(304)
			tmp15 = true;
		}
		HX_STACK_LINE(304)
		bool tmp16 = !(tmp15);		HX_STACK_VAR(tmp16,"tmp16");
		HX_STACK_LINE(304)
		bool tmp17 = tmp16;		HX_STACK_VAR(tmp17,"tmp17");
		HX_STACK_LINE(304)
		bool tmp18;		HX_STACK_VAR(tmp18,"tmp18");
		HX_STACK_LINE(304)
		if ((tmp17)){
			HX_STACK_LINE(304)
			tmp18 = dpadUp;
		}
		else{
			HX_STACK_LINE(304)
			tmp18 = true;
		}
		HX_STACK_LINE(304)
		bool tmp19 = !(tmp18);		HX_STACK_VAR(tmp19,"tmp19");
		HX_STACK_LINE(304)
		bool tmp20;		HX_STACK_VAR(tmp20,"tmp20");
		HX_STACK_LINE(304)
		if ((tmp19)){
			HX_STACK_LINE(304)
			tmp20 = dpadDown;
		}
		else{
			HX_STACK_LINE(304)
			tmp20 = true;
		}
		HX_STACK_LINE(304)
		if ((tmp20)){
			HX_STACK_LINE(306)
			newAlpha = ((Float)1);
			HX_STACK_LINE(308)
			bool tmp21 = dpadRight;		HX_STACK_VAR(tmp21,"tmp21");
			HX_STACK_LINE(308)
			bool tmp22;		HX_STACK_VAR(tmp22,"tmp22");
			HX_STACK_LINE(308)
			if ((tmp21)){
				HX_STACK_LINE(308)
				tmp22 = dpadUp;
			}
			else{
				HX_STACK_LINE(308)
				tmp22 = false;
			}
			HX_STACK_LINE(308)
			if ((tmp22)){
				HX_STACK_LINE(309)
				newIndex = (int)5;
			}
			else{
				HX_STACK_LINE(310)
				bool tmp23 = dpadRight;		HX_STACK_VAR(tmp23,"tmp23");
				HX_STACK_LINE(310)
				bool tmp24;		HX_STACK_VAR(tmp24,"tmp24");
				HX_STACK_LINE(310)
				if ((tmp23)){
					HX_STACK_LINE(310)
					tmp24 = dpadDown;
				}
				else{
					HX_STACK_LINE(310)
					tmp24 = false;
				}
				HX_STACK_LINE(310)
				if ((tmp24)){
					HX_STACK_LINE(311)
					newIndex = (int)6;
				}
				else{
					HX_STACK_LINE(312)
					bool tmp25 = dpadLeft;		HX_STACK_VAR(tmp25,"tmp25");
					HX_STACK_LINE(312)
					bool tmp26;		HX_STACK_VAR(tmp26,"tmp26");
					HX_STACK_LINE(312)
					if ((tmp25)){
						HX_STACK_LINE(312)
						tmp26 = dpadDown;
					}
					else{
						HX_STACK_LINE(312)
						tmp26 = false;
					}
					HX_STACK_LINE(312)
					if ((tmp26)){
						HX_STACK_LINE(313)
						newIndex = (int)7;
					}
					else{
						HX_STACK_LINE(314)
						bool tmp27 = dpadLeft;		HX_STACK_VAR(tmp27,"tmp27");
						HX_STACK_LINE(314)
						bool tmp28;		HX_STACK_VAR(tmp28,"tmp28");
						HX_STACK_LINE(314)
						if ((tmp27)){
							HX_STACK_LINE(314)
							tmp28 = dpadUp;
						}
						else{
							HX_STACK_LINE(314)
							tmp28 = false;
						}
						HX_STACK_LINE(314)
						if ((tmp28)){
							HX_STACK_LINE(315)
							newIndex = (int)8;
						}
						else{
							HX_STACK_LINE(316)
							bool tmp29 = dpadUp;		HX_STACK_VAR(tmp29,"tmp29");
							HX_STACK_LINE(316)
							if ((tmp29)){
								HX_STACK_LINE(317)
								newIndex = (int)1;
							}
							else{
								HX_STACK_LINE(318)
								bool tmp30 = dpadRight;		HX_STACK_VAR(tmp30,"tmp30");
								HX_STACK_LINE(318)
								if ((tmp30)){
									HX_STACK_LINE(319)
									newIndex = (int)2;
								}
								else{
									HX_STACK_LINE(320)
									bool tmp31 = dpadDown;		HX_STACK_VAR(tmp31,"tmp31");
									HX_STACK_LINE(320)
									if ((tmp31)){
										HX_STACK_LINE(321)
										newIndex = (int)3;
									}
									else{
										HX_STACK_LINE(322)
										bool tmp32 = dpadLeft;		HX_STACK_VAR(tmp32,"tmp32");
										HX_STACK_LINE(322)
										if ((tmp32)){
											HX_STACK_LINE(323)
											newIndex = (int)4;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		HX_STACK_LINE(326)
		::flixel::FlxSprite tmp21 = this->_dPad;		HX_STACK_VAR(tmp21,"tmp21");
		HX_STACK_LINE(326)
		int tmp22 = newIndex;		HX_STACK_VAR(tmp22,"tmp22");
		HX_STACK_LINE(326)
		tmp21->animation->set_frameIndex(tmp22);
		HX_STACK_LINE(327)
		::flixel::FlxSprite tmp23 = this->_dPad;		HX_STACK_VAR(tmp23,"tmp23");
		HX_STACK_LINE(327)
		Float tmp24 = newAlpha;		HX_STACK_VAR(tmp24,"tmp24");
		HX_STACK_LINE(327)
		tmp23->set_alpha(tmp24);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,updateDpad,(void))

Float PlayState_obj::STICK_MOVEMENT_RANGE;

Float PlayState_obj::TRIGGER_MOVEMENT_RANGE;

Float PlayState_obj::ALPHA_OFF;

Float PlayState_obj::ALPHA_ON;

Float PlayState_obj::LB_Y;

Float PlayState_obj::RB_Y;

::flixel::util::FlxPoint PlayState_obj::LEFT_STICK_POS;

::flixel::util::FlxPoint PlayState_obj::RIGHT_STICK_POS;

::flixel::util::FlxPoint PlayState_obj::LEFT_TRIGGER_POS;

::flixel::util::FlxPoint PlayState_obj::RIGHT_TRIGGER_POS;


PlayState_obj::PlayState_obj()
{
}

void PlayState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayState);
	HX_MARK_MEMBER_NAME(_controllerBg,"_controllerBg");
	HX_MARK_MEMBER_NAME(_leftStick,"_leftStick");
	HX_MARK_MEMBER_NAME(_rightStick,"_rightStick");
	HX_MARK_MEMBER_NAME(_dPad,"_dPad");
	HX_MARK_MEMBER_NAME(_leftTrigger,"_leftTrigger");
	HX_MARK_MEMBER_NAME(_rightTrigger,"_rightTrigger");
	HX_MARK_MEMBER_NAME(_xButton,"_xButton");
	HX_MARK_MEMBER_NAME(_yButton,"_yButton");
	HX_MARK_MEMBER_NAME(_aButton,"_aButton");
	HX_MARK_MEMBER_NAME(_bButton,"_bButton");
	HX_MARK_MEMBER_NAME(_backButton,"_backButton");
	HX_MARK_MEMBER_NAME(_startButton,"_startButton");
	HX_MARK_MEMBER_NAME(_LB,"_LB");
	HX_MARK_MEMBER_NAME(_RB,"_RB");
	HX_MARK_MEMBER_NAME(_gamePad,"_gamePad");
	HX_MARK_MEMBER_NAME(_hitText,"_hitText");
	HX_MARK_MEMBER_NAME(_missText,"_missText");
	HX_MARK_MEMBER_NAME(_music,"_music");
	HX_MARK_MEMBER_NAME(_musicBPM,"_musicBPM");
	HX_MARK_MEMBER_NAME(_musicLength,"_musicLength");
	HX_MARK_MEMBER_NAME(_beatDelay,"_beatDelay");
	HX_MARK_MEMBER_NAME(_beatDelta,"_beatDelta");
	HX_MARK_MEMBER_NAME(_beatAcceptance,"_beatAcceptance");
	HX_MARK_MEMBER_NAME(_beatInterval,"_beatInterval");
	HX_MARK_MEMBER_NAME(_onBeat,"_onBeat");
	HX_MARK_MEMBER_NAME(_currentBeatLock,"_currentBeatLock");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_controllerBg,"_controllerBg");
	HX_VISIT_MEMBER_NAME(_leftStick,"_leftStick");
	HX_VISIT_MEMBER_NAME(_rightStick,"_rightStick");
	HX_VISIT_MEMBER_NAME(_dPad,"_dPad");
	HX_VISIT_MEMBER_NAME(_leftTrigger,"_leftTrigger");
	HX_VISIT_MEMBER_NAME(_rightTrigger,"_rightTrigger");
	HX_VISIT_MEMBER_NAME(_xButton,"_xButton");
	HX_VISIT_MEMBER_NAME(_yButton,"_yButton");
	HX_VISIT_MEMBER_NAME(_aButton,"_aButton");
	HX_VISIT_MEMBER_NAME(_bButton,"_bButton");
	HX_VISIT_MEMBER_NAME(_backButton,"_backButton");
	HX_VISIT_MEMBER_NAME(_startButton,"_startButton");
	HX_VISIT_MEMBER_NAME(_LB,"_LB");
	HX_VISIT_MEMBER_NAME(_RB,"_RB");
	HX_VISIT_MEMBER_NAME(_gamePad,"_gamePad");
	HX_VISIT_MEMBER_NAME(_hitText,"_hitText");
	HX_VISIT_MEMBER_NAME(_missText,"_missText");
	HX_VISIT_MEMBER_NAME(_music,"_music");
	HX_VISIT_MEMBER_NAME(_musicBPM,"_musicBPM");
	HX_VISIT_MEMBER_NAME(_musicLength,"_musicLength");
	HX_VISIT_MEMBER_NAME(_beatDelay,"_beatDelay");
	HX_VISIT_MEMBER_NAME(_beatDelta,"_beatDelta");
	HX_VISIT_MEMBER_NAME(_beatAcceptance,"_beatAcceptance");
	HX_VISIT_MEMBER_NAME(_beatInterval,"_beatInterval");
	HX_VISIT_MEMBER_NAME(_onBeat,"_onBeat");
	HX_VISIT_MEMBER_NAME(_currentBeatLock,"_currentBeatLock");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayState_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_LB") ) { return _LB; }
		if (HX_FIELD_EQ(inName,"_RB") ) { return _RB; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_dPad") ) { return _dPad; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_music") ) { return _music; }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_onBeat") ) { return _onBeat; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_xButton") ) { return _xButton; }
		if (HX_FIELD_EQ(inName,"_yButton") ) { return _yButton; }
		if (HX_FIELD_EQ(inName,"_aButton") ) { return _aButton; }
		if (HX_FIELD_EQ(inName,"_bButton") ) { return _bButton; }
		if (HX_FIELD_EQ(inName,"_gamePad") ) { return _gamePad; }
		if (HX_FIELD_EQ(inName,"_hitText") ) { return _hitText; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_missText") ) { return _missText; }
		if (HX_FIELD_EQ(inName,"_musicBPM") ) { return _musicBPM; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_leftStick") ) { return _leftStick; }
		if (HX_FIELD_EQ(inName,"_beatDelay") ) { return _beatDelay; }
		if (HX_FIELD_EQ(inName,"_beatDelta") ) { return _beatDelta; }
		if (HX_FIELD_EQ(inName,"updateBeat") ) { return updateBeat_dyn(); }
		if (HX_FIELD_EQ(inName,"updateAxis") ) { return updateAxis_dyn(); }
		if (HX_FIELD_EQ(inName,"updateDpad") ) { return updateDpad_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_rightStick") ) { return _rightStick; }
		if (HX_FIELD_EQ(inName,"_backButton") ) { return _backButton; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_leftTrigger") ) { return _leftTrigger; }
		if (HX_FIELD_EQ(inName,"_startButton") ) { return _startButton; }
		if (HX_FIELD_EQ(inName,"_musicLength") ) { return _musicLength; }
		if (HX_FIELD_EQ(inName,"createSprite") ) { return createSprite_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_controllerBg") ) { return _controllerBg; }
		if (HX_FIELD_EQ(inName,"_rightTrigger") ) { return _rightTrigger; }
		if (HX_FIELD_EQ(inName,"_beatInterval") ) { return _beatInterval; }
		if (HX_FIELD_EQ(inName,"updateTrigger") ) { return updateTrigger_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_beatAcceptance") ) { return _beatAcceptance; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_currentBeatLock") ) { return _currentBeatLock; }
	}
	return super::__Field(inName,inCallProp);
}

bool PlayState_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"LEFT_STICK_POS") ) { outValue = LEFT_STICK_POS; return true;  }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"RIGHT_STICK_POS") ) { outValue = RIGHT_STICK_POS; return true;  }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"LEFT_TRIGGER_POS") ) { outValue = LEFT_TRIGGER_POS; return true;  }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"RIGHT_TRIGGER_POS") ) { outValue = RIGHT_TRIGGER_POS; return true;  }
	}
	return false;
}

Dynamic PlayState_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_LB") ) { _LB=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_RB") ) { _RB=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_dPad") ) { _dPad=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_music") ) { _music=inValue.Cast< ::flixel::_system::FlxSound >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_onBeat") ) { _onBeat=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_xButton") ) { _xButton=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_yButton") ) { _yButton=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_aButton") ) { _aButton=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_bButton") ) { _bButton=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_gamePad") ) { _gamePad=inValue.Cast< ::flixel::input::gamepad::FlxGamepad >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_hitText") ) { _hitText=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_missText") ) { _missText=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_musicBPM") ) { _musicBPM=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_leftStick") ) { _leftStick=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_beatDelay") ) { _beatDelay=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_beatDelta") ) { _beatDelta=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_rightStick") ) { _rightStick=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_backButton") ) { _backButton=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_leftTrigger") ) { _leftTrigger=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_startButton") ) { _startButton=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_musicLength") ) { _musicLength=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_controllerBg") ) { _controllerBg=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_rightTrigger") ) { _rightTrigger=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_beatInterval") ) { _beatInterval=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_beatAcceptance") ) { _beatAcceptance=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_currentBeatLock") ) { _currentBeatLock=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool PlayState_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"LEFT_STICK_POS") ) { LEFT_STICK_POS=ioValue.Cast< ::flixel::util::FlxPoint >(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"RIGHT_STICK_POS") ) { RIGHT_STICK_POS=ioValue.Cast< ::flixel::util::FlxPoint >(); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"LEFT_TRIGGER_POS") ) { LEFT_TRIGGER_POS=ioValue.Cast< ::flixel::util::FlxPoint >(); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"RIGHT_TRIGGER_POS") ) { RIGHT_TRIGGER_POS=ioValue.Cast< ::flixel::util::FlxPoint >(); return true; }
	}
	return false;
}

void PlayState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("_controllerBg","\x60","\xc4","\x79","\x86"));
	outFields->push(HX_HCSTRING("_leftStick","\x8a","\xe3","\x93","\xf4"));
	outFields->push(HX_HCSTRING("_rightStick","\xf3","\x2c","\x60","\x59"));
	outFields->push(HX_HCSTRING("_dPad","\x2e","\x7b","\x67","\xf5"));
	outFields->push(HX_HCSTRING("_leftTrigger","\xf2","\x41","\x7c","\x8b"));
	outFields->push(HX_HCSTRING("_rightTrigger","\x9b","\x77","\xfc","\xf2"));
	outFields->push(HX_HCSTRING("_xButton","\x0b","\xda","\x3c","\xc6"));
	outFields->push(HX_HCSTRING("_yButton","\xcc","\x50","\xd2","\xef"));
	outFields->push(HX_HCSTRING("_aButton","\xb4","\x2e","\xcf","\x09"));
	outFields->push(HX_HCSTRING("_bButton","\x75","\xa5","\x64","\x33"));
	outFields->push(HX_HCSTRING("_backButton","\x98","\x14","\xf4","\xea"));
	outFields->push(HX_HCSTRING("_startButton","\xf5","\x6d","\xd0","\xb7"));
	outFields->push(HX_HCSTRING("_LB","\x95","\x58","\x48","\x00"));
	outFields->push(HX_HCSTRING("_RB","\xcf","\x5d","\x48","\x00"));
	outFields->push(HX_HCSTRING("_gamePad","\x02","\xf2","\x25","\xc3"));
	outFields->push(HX_HCSTRING("_hitText","\x21","\xbe","\x37","\x1c"));
	outFields->push(HX_HCSTRING("_missText","\x28","\x71","\x50","\x1a"));
	outFields->push(HX_HCSTRING("_music","\xe6","\x17","\x42","\x0c"));
	outFields->push(HX_HCSTRING("_musicBPM","\x99","\xb6","\x1f","\x55"));
	outFields->push(HX_HCSTRING("_musicLength","\x6c","\x11","\x52","\x47"));
	outFields->push(HX_HCSTRING("_beatDelay","\xee","\xd5","\x4f","\x3a"));
	outFields->push(HX_HCSTRING("_beatDelta","\x63","\xe6","\x4f","\x3a"));
	outFields->push(HX_HCSTRING("_beatAcceptance","\x8c","\x15","\xa0","\x62"));
	outFields->push(HX_HCSTRING("_beatInterval","\xba","\x0f","\x40","\x59"));
	outFields->push(HX_HCSTRING("_onBeat","\xd4","\xfb","\x14","\x52"));
	outFields->push(HX_HCSTRING("_currentBeatLock","\x5b","\x98","\x22","\xd2"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_controllerBg),HX_HCSTRING("_controllerBg","\x60","\xc4","\x79","\x86")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_leftStick),HX_HCSTRING("_leftStick","\x8a","\xe3","\x93","\xf4")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_rightStick),HX_HCSTRING("_rightStick","\xf3","\x2c","\x60","\x59")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_dPad),HX_HCSTRING("_dPad","\x2e","\x7b","\x67","\xf5")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_leftTrigger),HX_HCSTRING("_leftTrigger","\xf2","\x41","\x7c","\x8b")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_rightTrigger),HX_HCSTRING("_rightTrigger","\x9b","\x77","\xfc","\xf2")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_xButton),HX_HCSTRING("_xButton","\x0b","\xda","\x3c","\xc6")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_yButton),HX_HCSTRING("_yButton","\xcc","\x50","\xd2","\xef")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_aButton),HX_HCSTRING("_aButton","\xb4","\x2e","\xcf","\x09")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_bButton),HX_HCSTRING("_bButton","\x75","\xa5","\x64","\x33")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_backButton),HX_HCSTRING("_backButton","\x98","\x14","\xf4","\xea")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_startButton),HX_HCSTRING("_startButton","\xf5","\x6d","\xd0","\xb7")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_LB),HX_HCSTRING("_LB","\x95","\x58","\x48","\x00")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,_RB),HX_HCSTRING("_RB","\xcf","\x5d","\x48","\x00")},
	{hx::fsObject /*::flixel::input::gamepad::FlxGamepad*/ ,(int)offsetof(PlayState_obj,_gamePad),HX_HCSTRING("_gamePad","\x02","\xf2","\x25","\xc3")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(PlayState_obj,_hitText),HX_HCSTRING("_hitText","\x21","\xbe","\x37","\x1c")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(PlayState_obj,_missText),HX_HCSTRING("_missText","\x28","\x71","\x50","\x1a")},
	{hx::fsObject /*::flixel::_system::FlxSound*/ ,(int)offsetof(PlayState_obj,_music),HX_HCSTRING("_music","\xe6","\x17","\x42","\x0c")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,_musicBPM),HX_HCSTRING("_musicBPM","\x99","\xb6","\x1f","\x55")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,_musicLength),HX_HCSTRING("_musicLength","\x6c","\x11","\x52","\x47")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,_beatDelay),HX_HCSTRING("_beatDelay","\xee","\xd5","\x4f","\x3a")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,_beatDelta),HX_HCSTRING("_beatDelta","\x63","\xe6","\x4f","\x3a")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,_beatAcceptance),HX_HCSTRING("_beatAcceptance","\x8c","\x15","\xa0","\x62")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,_beatInterval),HX_HCSTRING("_beatInterval","\xba","\x0f","\x40","\x59")},
	{hx::fsBool,(int)offsetof(PlayState_obj,_onBeat),HX_HCSTRING("_onBeat","\xd4","\xfb","\x14","\x52")},
	{hx::fsBool,(int)offsetof(PlayState_obj,_currentBeatLock),HX_HCSTRING("_currentBeatLock","\x5b","\x98","\x22","\xd2")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsFloat,(void *) &PlayState_obj::STICK_MOVEMENT_RANGE,HX_HCSTRING("STICK_MOVEMENT_RANGE","\xbc","\x34","\x58","\x0c")},
	{hx::fsFloat,(void *) &PlayState_obj::TRIGGER_MOVEMENT_RANGE,HX_HCSTRING("TRIGGER_MOVEMENT_RANGE","\xd4","\xe1","\xc7","\x70")},
	{hx::fsFloat,(void *) &PlayState_obj::ALPHA_OFF,HX_HCSTRING("ALPHA_OFF","\x8e","\xca","\xbf","\xfe")},
	{hx::fsFloat,(void *) &PlayState_obj::ALPHA_ON,HX_HCSTRING("ALPHA_ON","\xc0","\x16","\xd4","\x7a")},
	{hx::fsFloat,(void *) &PlayState_obj::LB_Y,HX_HCSTRING("LB_Y","\x10","\x9f","\x6e","\x32")},
	{hx::fsFloat,(void *) &PlayState_obj::RB_Y,HX_HCSTRING("RB_Y","\xca","\xe6","\x65","\x36")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(void *) &PlayState_obj::LEFT_STICK_POS,HX_HCSTRING("LEFT_STICK_POS","\x2d","\x82","\xbc","\x73")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(void *) &PlayState_obj::RIGHT_STICK_POS,HX_HCSTRING("RIGHT_STICK_POS","\x22","\x8a","\x4d","\xf3")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(void *) &PlayState_obj::LEFT_TRIGGER_POS,HX_HCSTRING("LEFT_TRIGGER_POS","\x15","\xc0","\x57","\x48")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(void *) &PlayState_obj::RIGHT_TRIGGER_POS,HX_HCSTRING("RIGHT_TRIGGER_POS","\x4a","\x6f","\x32","\x94")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("_controllerBg","\x60","\xc4","\x79","\x86"),
	HX_HCSTRING("_leftStick","\x8a","\xe3","\x93","\xf4"),
	HX_HCSTRING("_rightStick","\xf3","\x2c","\x60","\x59"),
	HX_HCSTRING("_dPad","\x2e","\x7b","\x67","\xf5"),
	HX_HCSTRING("_leftTrigger","\xf2","\x41","\x7c","\x8b"),
	HX_HCSTRING("_rightTrigger","\x9b","\x77","\xfc","\xf2"),
	HX_HCSTRING("_xButton","\x0b","\xda","\x3c","\xc6"),
	HX_HCSTRING("_yButton","\xcc","\x50","\xd2","\xef"),
	HX_HCSTRING("_aButton","\xb4","\x2e","\xcf","\x09"),
	HX_HCSTRING("_bButton","\x75","\xa5","\x64","\x33"),
	HX_HCSTRING("_backButton","\x98","\x14","\xf4","\xea"),
	HX_HCSTRING("_startButton","\xf5","\x6d","\xd0","\xb7"),
	HX_HCSTRING("_LB","\x95","\x58","\x48","\x00"),
	HX_HCSTRING("_RB","\xcf","\x5d","\x48","\x00"),
	HX_HCSTRING("_gamePad","\x02","\xf2","\x25","\xc3"),
	HX_HCSTRING("_hitText","\x21","\xbe","\x37","\x1c"),
	HX_HCSTRING("_missText","\x28","\x71","\x50","\x1a"),
	HX_HCSTRING("_music","\xe6","\x17","\x42","\x0c"),
	HX_HCSTRING("_musicBPM","\x99","\xb6","\x1f","\x55"),
	HX_HCSTRING("_musicLength","\x6c","\x11","\x52","\x47"),
	HX_HCSTRING("_beatDelay","\xee","\xd5","\x4f","\x3a"),
	HX_HCSTRING("_beatDelta","\x63","\xe6","\x4f","\x3a"),
	HX_HCSTRING("_beatAcceptance","\x8c","\x15","\xa0","\x62"),
	HX_HCSTRING("_beatInterval","\xba","\x0f","\x40","\x59"),
	HX_HCSTRING("_onBeat","\xd4","\xfb","\x14","\x52"),
	HX_HCSTRING("_currentBeatLock","\x5b","\x98","\x22","\xd2"),
	HX_HCSTRING("create","\xfc","\x66","\x0f","\x7c"),
	HX_HCSTRING("createSprite","\x21","\x1c","\xeb","\xe5"),
	HX_HCSTRING("update","\x09","\x86","\x05","\x87"),
	HX_HCSTRING("updateBeat","\x1f","\xcc","\xc8","\xf9"),
	HX_HCSTRING("updateTrigger","\x2f","\xba","\x4d","\xf1"),
	HX_HCSTRING("updateAxis","\x4a","\x07","\x2e","\xf9"),
	HX_HCSTRING("updateDpad","\x18","\x92","\x23","\xfb"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(PlayState_obj::STICK_MOVEMENT_RANGE,"STICK_MOVEMENT_RANGE");
	HX_MARK_MEMBER_NAME(PlayState_obj::TRIGGER_MOVEMENT_RANGE,"TRIGGER_MOVEMENT_RANGE");
	HX_MARK_MEMBER_NAME(PlayState_obj::ALPHA_OFF,"ALPHA_OFF");
	HX_MARK_MEMBER_NAME(PlayState_obj::ALPHA_ON,"ALPHA_ON");
	HX_MARK_MEMBER_NAME(PlayState_obj::LB_Y,"LB_Y");
	HX_MARK_MEMBER_NAME(PlayState_obj::RB_Y,"RB_Y");
	HX_MARK_MEMBER_NAME(PlayState_obj::LEFT_STICK_POS,"LEFT_STICK_POS");
	HX_MARK_MEMBER_NAME(PlayState_obj::RIGHT_STICK_POS,"RIGHT_STICK_POS");
	HX_MARK_MEMBER_NAME(PlayState_obj::LEFT_TRIGGER_POS,"LEFT_TRIGGER_POS");
	HX_MARK_MEMBER_NAME(PlayState_obj::RIGHT_TRIGGER_POS,"RIGHT_TRIGGER_POS");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PlayState_obj::STICK_MOVEMENT_RANGE,"STICK_MOVEMENT_RANGE");
	HX_VISIT_MEMBER_NAME(PlayState_obj::TRIGGER_MOVEMENT_RANGE,"TRIGGER_MOVEMENT_RANGE");
	HX_VISIT_MEMBER_NAME(PlayState_obj::ALPHA_OFF,"ALPHA_OFF");
	HX_VISIT_MEMBER_NAME(PlayState_obj::ALPHA_ON,"ALPHA_ON");
	HX_VISIT_MEMBER_NAME(PlayState_obj::LB_Y,"LB_Y");
	HX_VISIT_MEMBER_NAME(PlayState_obj::RB_Y,"RB_Y");
	HX_VISIT_MEMBER_NAME(PlayState_obj::LEFT_STICK_POS,"LEFT_STICK_POS");
	HX_VISIT_MEMBER_NAME(PlayState_obj::RIGHT_STICK_POS,"RIGHT_STICK_POS");
	HX_VISIT_MEMBER_NAME(PlayState_obj::LEFT_TRIGGER_POS,"LEFT_TRIGGER_POS");
	HX_VISIT_MEMBER_NAME(PlayState_obj::RIGHT_TRIGGER_POS,"RIGHT_TRIGGER_POS");
};

#endif

hx::Class PlayState_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("STICK_MOVEMENT_RANGE","\xbc","\x34","\x58","\x0c"),
	HX_HCSTRING("TRIGGER_MOVEMENT_RANGE","\xd4","\xe1","\xc7","\x70"),
	HX_HCSTRING("ALPHA_OFF","\x8e","\xca","\xbf","\xfe"),
	HX_HCSTRING("ALPHA_ON","\xc0","\x16","\xd4","\x7a"),
	HX_HCSTRING("LB_Y","\x10","\x9f","\x6e","\x32"),
	HX_HCSTRING("RB_Y","\xca","\xe6","\x65","\x36"),
	HX_HCSTRING("LEFT_STICK_POS","\x2d","\x82","\xbc","\x73"),
	HX_HCSTRING("RIGHT_STICK_POS","\x22","\x8a","\x4d","\xf3"),
	HX_HCSTRING("LEFT_TRIGGER_POS","\x15","\xc0","\x57","\x48"),
	HX_HCSTRING("RIGHT_TRIGGER_POS","\x4a","\x6f","\x32","\x94"),
	::String(null()) };

void PlayState_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("PlayState","\x5d","\x83","\xc2","\x46");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &PlayState_obj::__GetStatic;
	__mClass->mSetStaticField = &PlayState_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< PlayState_obj >;
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

void PlayState_obj::__boot()
{
	STICK_MOVEMENT_RANGE= ((Float)10);
	TRIGGER_MOVEMENT_RANGE= ((Float)10);
	ALPHA_OFF= ((Float)0.5);
	ALPHA_ON= ((Float)1);
	LB_Y= ((Float)2);
	RB_Y= ((Float)2);
struct _Function_0_1{
	inline static ::flixel::util::FlxPoint Block( ){
		HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","PlayState.hx",27,0xb30d7781)
		{
			HX_STACK_LINE(27)
			::flixel::util::FlxPool tmp = ::flixel::util::FlxPoint_obj::_pool;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(27)
			::flixel::util::FlxPoint tmp1 = tmp->get();		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(27)
			::flixel::util::FlxPoint tmp2 = tmp1->set((int)80,(int)48);		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(27)
			::flixel::util::FlxPoint point = tmp2;		HX_STACK_VAR(point,"point");
			HX_STACK_LINE(27)
			point->_inPool = false;
			HX_STACK_LINE(27)
			return point;
		}
		return null();
	}
};
	LEFT_STICK_POS= _Function_0_1::Block();
struct _Function_0_2{
	inline static ::flixel::util::FlxPoint Block( ){
		HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","PlayState.hx",28,0xb30d7781)
		{
			HX_STACK_LINE(28)
			::flixel::util::FlxPool tmp = ::flixel::util::FlxPoint_obj::_pool;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(28)
			::flixel::util::FlxPoint tmp1 = tmp->get();		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(28)
			::flixel::util::FlxPoint tmp2 = tmp1->set((int)304,(int)136);		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(28)
			::flixel::util::FlxPoint point = tmp2;		HX_STACK_VAR(point,"point");
			HX_STACK_LINE(28)
			point->_inPool = false;
			HX_STACK_LINE(28)
			return point;
		}
		return null();
	}
};
	RIGHT_STICK_POS= _Function_0_2::Block();
struct _Function_0_3{
	inline static ::flixel::util::FlxPoint Block( ){
		HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","PlayState.hx",29,0xb30d7781)
		{
			HX_STACK_LINE(29)
			::flixel::util::FlxPool tmp = ::flixel::util::FlxPoint_obj::_pool;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(29)
			::flixel::util::FlxPoint tmp1 = tmp->get();		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(29)
			::flixel::util::FlxPoint tmp2 = tmp1->set((int)71,(int)15);		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(29)
			::flixel::util::FlxPoint point = tmp2;		HX_STACK_VAR(point,"point");
			HX_STACK_LINE(29)
			point->_inPool = false;
			HX_STACK_LINE(29)
			return point;
		}
		return null();
	}
};
	LEFT_TRIGGER_POS= _Function_0_3::Block();
struct _Function_0_4{
	inline static ::flixel::util::FlxPoint Block( ){
		HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","PlayState.hx",30,0xb30d7781)
		{
			HX_STACK_LINE(30)
			::flixel::util::FlxPool tmp = ::flixel::util::FlxPoint_obj::_pool;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(30)
			::flixel::util::FlxPoint tmp1 = tmp->get();		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(30)
			::flixel::util::FlxPoint tmp2 = tmp1->set((int)367,(int)15);		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(30)
			::flixel::util::FlxPoint point = tmp2;		HX_STACK_VAR(point,"point");
			HX_STACK_LINE(30)
			point->_inPool = false;
			HX_STACK_LINE(30)
			return point;
		}
		return null();
	}
};
	RIGHT_TRIGGER_POS= _Function_0_4::Block();
}

