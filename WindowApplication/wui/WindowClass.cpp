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
void WindowClass::registerWindowClass(
	HINSTANCE hInstance,
	LPCWSTR className,
	UINT idMenu, 
	UINT idIcon, UINT idSmallIcon, UINT idCursor, 
	UINT style
)
{
	//-----------------------------------------------------------------------
	if (nullptr == hInstance)
	{
		hInstance = getAppModule()->getInstanceHandle();
	}
	_InstanceHandle = hInstance;
	
	
	//-----------------------------------------------------------------------
	_WindowClassName = className;


	//-----------------------------------------------------------------------
	memset(&_WindowClassStructure, 0, sizeof(_WindowClassStructure));

	_WindowClassStructure.cbSize        = sizeof(_WindowClassStructure);
	//_WindowClassStructure.style       = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS
	_WindowClassStructure.style         = style;
	_WindowClassStructure.cbClsExtra    = 0;
	_WindowClassStructure.cbWndExtra    = 0;
	_WindowClassStructure.hInstance     = hInstance;
	_WindowClassStructure.lpfnWndProc   = WindowProc;
	_WindowClassStructure.lpszClassName = className;
	_WindowClassStructure.lpszMenuName  = MAKEINTRESOURCEW(idMenu);
	_WindowClassStructure.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
	_WindowClassStructure.hCursor       = ::LoadCursorW(nullptr, MAKEINTRESOURCEW(idCursor));
	_WindowClassStructure.hIcon         = ::LoadIconW(hInstance, MAKEINTRESOURCEW(idIcon));
	_WindowClassStructure.hIconSm       = ::LoadIconW(hInstance, MAKEINTRESOURCEW(idSmallIcon));



	//-----------------------------------------------------------------------
	WNDCLASSEXW wndClass;
	BOOL rv;


	rv = ::GetClassInfoExW(hInstance, className, &wndClass);
	if (FALSE == rv)
	{
		ATOM atom = ::RegisterClassExW(&_WindowClassStructure);
		if (!atom)
		{
			throw std::runtime_error("WindowClass::registerWindowClass()");
		}
	}
}

void WindowClass::unregisterWindowClass(void)
{
	BOOL rv;


	rv = ::UnregisterClassW(_WindowClassName.c_str(), _InstanceHandle);
	if (FALSE == rv)
	{
		throw std::runtime_error("WindowClass::unregisterWindowClass()");
	}
}

//===========================================================================
std::wstring_view WindowClass::getWindowClassName(void)
{
	return _WindowClassName;
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




