#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace wui
{





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
template <typename TWindow, typename TBaseWindow>
class MessageMapWindow : public TBaseWindow
{
protected:
	WindowMessageMapT<TWindow> _WindowMessageMap;

	//-----------------------------------------------------------------------
	// Window
public:
	virtual LRESULT onMessage(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam) override
	{
		WindowMessage windowMessage{ hwnd, umsg, wparam, lparam };


		if (_WindowMessageMap.onWindowMessage(static_cast<TWindow*>(this), windowMessage))
		{
			return windowMessage.lResult;
		}

		return static_cast<TWindow*>(this)->callWindowProc(windowMessage);
	}

	//-----------------------------------------------------------------------
public:
	virtual LRESULT callWindowProc(WindowMessage& windowMessage)
	{
		windowMessage.lResult = 
			static_cast<TBaseWindow*>(this)->callWindowProc(
				windowMessage.hWnd,
				windowMessage.uMsg,
				windowMessage.wParam,
				windowMessage.lParam
			);

		return windowMessage.lResult;
	}
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




