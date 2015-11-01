#include <hxcpp.h>

#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif

Void Xml_obj::__construct()
{
	return null();
}

//Xml_obj::~Xml_obj() { }

Dynamic Xml_obj::__CreateEmpty() { return  new Xml_obj; }
hx::ObjectPtr< Xml_obj > Xml_obj::__new()
{  hx::ObjectPtr< Xml_obj > _result_ = new Xml_obj();
	_result_->__construct();
	return _result_;}

Dynamic Xml_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Xml_obj > _result_ = new Xml_obj();
	_result_->__construct();
	return _result_;}

::String Xml_obj::get( ::String att){
	HX_STACK_FRAME("Xml","get",0x2e441e5f,"Xml.get","C:\\HaxeToolkit\\haxe\\std/Xml.hx",166,0x6fe08e00)
	HX_STACK_THIS(this)
	HX_STACK_ARG(att,"att")
	HX_STACK_LINE(167)
	int tmp = this->nodeType;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(167)
	int tmp1 = ::Xml_obj::Element;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(167)
	bool tmp2 = (tmp != tmp1);		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(167)
	if ((tmp2)){
		HX_STACK_LINE(168)
		int tmp3 = this->nodeType;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(168)
		::String tmp4 = (HX_HCSTRING("Bad node type, expected Element but found ","\xd8","\x90","\x8b","\xbb") + tmp3);		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(168)
		HX_STACK_DO_THROW(tmp4);
	}
	HX_STACK_LINE(170)
	::haxe::ds::StringMap tmp3 = this->attributeMap;		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(170)
	::String tmp4 = att;		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(170)
	::String tmp5 = tmp3->get(tmp4);		HX_STACK_VAR(tmp5,"tmp5");
	HX_STACK_LINE(170)
	::String tmp6 = tmp5;		HX_STACK_VAR(tmp6,"tmp6");
	HX_STACK_LINE(170)
	return tmp6;
}


HX_DEFINE_DYNAMIC_FUNC1(Xml_obj,get,return )

Dynamic Xml_obj::elements( ){
	HX_STACK_FRAME("Xml","elements",0x0310ffce,"Xml.elements","C:\\HaxeToolkit\\haxe\\std/Xml.hx",229,0x6fe08e00)
	HX_STACK_THIS(this)
	HX_STACK_LINE(230)
	{
		HX_STACK_LINE(230)
		int tmp = this->nodeType;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(230)
		int tmp1 = ::Xml_obj::Document;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(230)
		bool tmp2 = (tmp != tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(230)
		bool tmp3;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(230)
		if ((tmp2)){
			HX_STACK_LINE(230)
			int tmp4 = this->nodeType;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(230)
			int tmp5 = tmp4;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(230)
			int tmp6 = ::Xml_obj::Element;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(230)
			int tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(230)
			tmp3 = (tmp5 != tmp7);
		}
		else{
			HX_STACK_LINE(230)
			tmp3 = false;
		}
		HX_STACK_LINE(230)
		if ((tmp3)){
			HX_STACK_LINE(230)
			int tmp4 = this->nodeType;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(230)
			::String tmp5 = (HX_HCSTRING("Bad node type, expected Element or Document but found ","\xa0","\xd6","\xba","\x79") + tmp4);		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(230)
			HX_STACK_DO_THROW(tmp5);
		}
	}
	HX_STACK_LINE(231)
	Array< ::Dynamic > ret;		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(231)
	{
		HX_STACK_LINE(231)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(231)
		{
			HX_STACK_LINE(231)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(231)
			Array< ::Dynamic > _g2 = this->children;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(231)
			while((true)){
				HX_STACK_LINE(231)
				bool tmp = (_g1 < _g2->length);		HX_STACK_VAR(tmp,"tmp");
				HX_STACK_LINE(231)
				bool tmp1 = !(tmp);		HX_STACK_VAR(tmp1,"tmp1");
				HX_STACK_LINE(231)
				if ((tmp1)){
					HX_STACK_LINE(231)
					break;
				}
				HX_STACK_LINE(231)
				::Xml tmp2 = _g2->__get(_g1).StaticCast< ::Xml >();		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(231)
				::Xml child = tmp2;		HX_STACK_VAR(child,"child");
				HX_STACK_LINE(231)
				++(_g1);
				HX_STACK_LINE(231)
				int tmp3 = child->nodeType;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(231)
				int tmp4 = ::Xml_obj::Element;		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(231)
				bool tmp5 = (tmp3 == tmp4);		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(231)
				if ((tmp5)){
					HX_STACK_LINE(231)
					::Xml tmp6 = child;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(231)
					_g->push(tmp6);
				}
			}
		}
		HX_STACK_LINE(231)
		ret = _g;
	}
	HX_STACK_LINE(232)
	Dynamic tmp = ret->iteratorFast< ::Xml >();		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(232)
	return tmp;
}


HX_DEFINE_DYNAMIC_FUNC0(Xml_obj,elements,return )

int Xml_obj::Element;

int Xml_obj::Document;


Xml_obj::Xml_obj()
{
}

void Xml_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Xml);
	HX_MARK_MEMBER_NAME(nodeType,"nodeType");
	HX_MARK_MEMBER_NAME(nodeName,"nodeName");
	HX_MARK_MEMBER_NAME(children,"children");
	HX_MARK_MEMBER_NAME(attributeMap,"attributeMap");
	HX_MARK_END_CLASS();
}

void Xml_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nodeType,"nodeType");
	HX_VISIT_MEMBER_NAME(nodeName,"nodeName");
	HX_VISIT_MEMBER_NAME(children,"children");
	HX_VISIT_MEMBER_NAME(attributeMap,"attributeMap");
}

Dynamic Xml_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nodeType") ) { return nodeType; }
		if (HX_FIELD_EQ(inName,"nodeName") ) { return nodeName; }
		if (HX_FIELD_EQ(inName,"children") ) { return children; }
		if (HX_FIELD_EQ(inName,"elements") ) { return elements_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"attributeMap") ) { return attributeMap; }
	}
	return super::__Field(inName,inCallProp);
}

bool Xml_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"Element") ) { outValue = Element; return true;  }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Document") ) { outValue = Document; return true;  }
	}
	return false;
}

Dynamic Xml_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"nodeType") ) { nodeType=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nodeName") ) { nodeName=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"children") ) { children=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"attributeMap") ) { attributeMap=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool Xml_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"Element") ) { Element=ioValue.Cast< int >(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Document") ) { Document=ioValue.Cast< int >(); return true; }
	}
	return false;
}

void Xml_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("nodeType","\xdc","\x51","\x86","\xf6"));
	outFields->push(HX_HCSTRING("nodeName","\x6d","\xd1","\x7c","\xf2"));
	outFields->push(HX_HCSTRING("children","\x3f","\x19","\x6a","\x70"));
	outFields->push(HX_HCSTRING("attributeMap","\xe0","\x4b","\xb2","\x95"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Xml_obj,nodeType),HX_HCSTRING("nodeType","\xdc","\x51","\x86","\xf6")},
	{hx::fsString,(int)offsetof(Xml_obj,nodeName),HX_HCSTRING("nodeName","\x6d","\xd1","\x7c","\xf2")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Xml_obj,children),HX_HCSTRING("children","\x3f","\x19","\x6a","\x70")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(Xml_obj,attributeMap),HX_HCSTRING("attributeMap","\xe0","\x4b","\xb2","\x95")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsInt,(void *) &Xml_obj::Element,HX_HCSTRING("Element","\x9c","\xd6","\xa5","\xd3")},
	{hx::fsInt,(void *) &Xml_obj::Document,HX_HCSTRING("Document","\x3b","\xab","\xc4","\x74")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("nodeType","\xdc","\x51","\x86","\xf6"),
	HX_HCSTRING("nodeName","\x6d","\xd1","\x7c","\xf2"),
	HX_HCSTRING("children","\x3f","\x19","\x6a","\x70"),
	HX_HCSTRING("attributeMap","\xe0","\x4b","\xb2","\x95"),
	HX_HCSTRING("get","\x96","\x80","\x4e","\x00"),
	HX_HCSTRING("elements","\x37","\x36","\xc4","\x83"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Xml_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Xml_obj::Element,"Element");
	HX_MARK_MEMBER_NAME(Xml_obj::Document,"Document");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Xml_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Xml_obj::Element,"Element");
	HX_VISIT_MEMBER_NAME(Xml_obj::Document,"Document");
};

#endif

hx::Class Xml_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("Element","\x9c","\xd6","\xa5","\xd3"),
	HX_HCSTRING("Document","\x3b","\xab","\xc4","\x74"),
	::String(null()) };

void Xml_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("Xml","\xb7","\x25","\x43","\x00");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Xml_obj::__GetStatic;
	__mClass->mSetStaticField = &Xml_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Xml_obj >;
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

void Xml_obj::__boot()
{
	Element= (int)0;
	Document= (int)6;
}

