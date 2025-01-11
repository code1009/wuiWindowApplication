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
std::wstring getWindowText(const HWND hwnd)
{
	std::wstring s;


	int length;


	length = GetWindowTextLengthW(hwnd);


	if (length > 0)
	{
		s.resize(length + 1, 0);

		GetWindowTextW(hwnd, s.data(), length + 1);
	}


	return s;
}

void setWindowText(const HWND hwnd, const std::wstring& s)
{
	SetWindowTextW(hwnd, s.c_str());
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
std::string getWindowTextA(const HWND hwnd)
{
	std::string s;


	int length;


	length = GetWindowTextLengthA(hwnd);


	if (length > 0)
	{
		s.resize(length + 1, 0);

		GetWindowTextA(hwnd, s.data(), length + 1);
	}


	return s;
}

void setWindowTextA(const HWND hwnd, const std::string& s)
{
	SetWindowTextA(hwnd, s.c_str());
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
void moveWindow(const HWND hwnd, const RECT& rect, bool repaint)
{
	::MoveWindow(hwnd,
		rect.left, rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		repaint ? TRUE : FALSE);
}

void setWindowPos(const HWND hwnd, const HWND insertAfter, const RECT& rect, UINT flags)
{
	::SetWindowPos(hwnd,
		insertAfter,
		rect.left, rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		flags);
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
LRESULT sendWindowMessage(const HWND hwnd, WindowMessage& windowMessage)
{
	windowMessage.lResult =
		::SendMessageW(
			hwnd,
			windowMessage.uMsg,
			windowMessage.wParam,
			windowMessage.lParam
		);

	return windowMessage.lResult;
}

LRESULT sendWindowMessage(WindowMessage& windowMessage)
{
	windowMessage.lResult =
		::SendMessageW(
			windowMessage.hWnd,
			windowMessage.uMsg,
			windowMessage.wParam,
			windowMessage.lParam
		);

	return windowMessage.lResult;
}

BOOL postWindowMessage(const HWND hwnd, WindowMessage& windowMessage)
{
	BOOL rv;


	windowMessage.lResult = 0;
	rv = ::PostMessageW(
			hwnd,
			windowMessage.uMsg,
			windowMessage.wParam,
			windowMessage.lParam
		);

	return rv;
}

BOOL postWindowMessage(WindowMessage& windowMessage)
{
	BOOL rv;


	windowMessage.lResult = 0;
	rv = ::PostMessageW(
			windowMessage.hWnd,
			windowMessage.uMsg,
			windowMessage.wParam,
			windowMessage.lParam
		);

	return rv;
}




/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




