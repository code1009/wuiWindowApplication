/////////////////////////////////////////////////////////////////////////////
//===========================================================================
#include "pch.hpp"

//===========================================================================
#include "wui.hpp"





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace wui
{





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
HINSTANCE AppModule::getInstanceHandle(void) const
{
	return _InstanceHandle;
}

HINSTANCE AppModule::setInstanceHandle(HINSTANCE handle)
{
	HINSTANCE old;


	old = _InstanceHandle;
	_InstanceHandle = handle;

	return _InstanceHandle;
}

/*
HINSTANCE AppModule::getResInstanceHandle(void) const
{
	if (_ResInstanceHandle)
	{
		return _ResInstanceHandle;
	}

	return _InstanceHandle;
}

HINSTANCE AppModule::setResInstanceHandle(HINSTANCE handle)
{
	HINSTANCE old;


	old = _ResInstanceHandle;
	_ResInstanceHandle = handle;

	return _ResInstanceHandle;
}
*/





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
AppModule* getAppModule(void)
{
	static AppModule instance;

	return &instance;
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




