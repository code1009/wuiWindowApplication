#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace wui
{





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class WindowMessage final
{
public:
	HWND     hWnd;
	UINT     uMsg;
	WPARAM   wParam;
	LPARAM   lParam;
	LRESULT  lResult;

public:
	explicit WindowMessage(
		HWND   hwnd,
		UINT   umsg,
		WPARAM wparam,
		LPARAM lparam
	);

public:
	WindowMessage(const WindowMessage& other);
	WindowMessage& operator=(const WindowMessage& other);

	WindowMessage(WindowMessage&& other) noexcept;
	WindowMessage& operator=(WindowMessage&& other) noexcept;
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




