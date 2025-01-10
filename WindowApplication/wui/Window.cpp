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
HWND Window::getWindowHandle(void) const
{
	return _WindowHandle;
}

HWND Window::setWindowHandle(HWND handle)
{
	HWND old;


	old = _WindowHandle;
	_WindowHandle = handle;

	return _WindowHandle;
}

LRESULT Window::onMessage(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	return callWindowProc(hwnd, umsg, wparam, lparam);
}

LRESULT Window::callWindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	return ::DefWindowProcW(hwnd, umsg, wparam, lparam);
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




