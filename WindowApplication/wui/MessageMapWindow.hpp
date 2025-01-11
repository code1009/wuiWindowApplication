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

		return onWindowMessage(windowMessage);
	}

	//-----------------------------------------------------------------------
public:
	virtual LRESULT onWindowMessage(WindowMessage& windowMessage)
	{
		if (callWindowMessageMapHandler(windowMessage))
		{
			return windowMessage.lResult;
		}

		return static_cast<TWindow*>(this)->callWindowProc(windowMessage);
	}

	virtual bool callWindowMessageMapHandler(WindowMessage& windowMessage)
	{
		return _WindowMessageMap.onWindowMessage(static_cast<TWindow*>(this), windowMessage);
	}

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

public:
	virtual void registerWindowMessageMapHandler(void) = 0;
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




