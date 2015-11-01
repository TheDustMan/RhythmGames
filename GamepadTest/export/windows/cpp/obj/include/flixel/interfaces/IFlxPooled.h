#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#define INCLUDED_flixel_interfaces_IFlxPooled

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxPooled)
namespace flixel{
namespace interfaces{


class HXCPP_CLASS_ATTRIBUTES  IFlxPooled_obj : public ::flixel::interfaces::IFlxDestroyable_obj{
	public:
		typedef ::flixel::interfaces::IFlxDestroyable_obj super;
		typedef IFlxPooled_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		virtual Void put( )=0;
virtual Dynamic put_dyn()=0;
};



template<typename IMPL>
class IFlxPooled_delegate_ : public IFlxPooled_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IFlxPooled_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		Void put( ) { return mDelegate->put();}
		Dynamic put_dyn() { return mDelegate->put_dyn();}
		Void destroy( ) { return mDelegate->destroy();}
		Dynamic destroy_dyn() { return mDelegate->destroy_dyn();}
};

} // end namespace flixel
} // end namespace interfaces

#endif /* INCLUDED_flixel_interfaces_IFlxPooled */ 
