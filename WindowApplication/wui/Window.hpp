#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace wui
{




/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class Window
{
private:
	HWND _WindowHandle{ nullptr };

public:
	Window() = default;
	virtual ~Window() = default;

public:
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	Window(Window&&) = delete;
	Window& operator=(Window&&) = delete;

public:
	[[nodiscard]] constexpr operator HWND (void) const
	{
		return _WindowHandle;
	}

public:
	virtual HWND getWindowHandle(void) const;
	virtual HWND setWindowHandle(HWND handle);

public:
	virtual LRESULT WindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




