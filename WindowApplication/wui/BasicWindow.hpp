#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace wui
{





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class SubclassWindow : public Window
{
private:
	WNDPROC _ChainWindowProc{ nullptr };

	//-----------------------------------------------------------------------
	// Window
public:
	virtual LRESULT callWindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam) override;

	//-----------------------------------------------------------------------
public:
	virtual WNDPROC subclassWindow(HWND hwnd);
	virtual WNDPROC unsubclassWindow(WNDPROC windowProc = nullptr);

public:
	virtual WNDPROC getChainWindowProc(void);
};




/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class BasicWindow : public Window
{
public:
	virtual HWND createWindow(
		LPCWSTR   lpClassName,
		HWND      hWndParent   = nullptr,
		LPCWSTR   lpWindowName = L"Window",
		DWORD     dwStyle      = FrameWindowStyle,
		DWORD     dwExStyle    = FrameWindowStyleEx,
		int       X            = CW_USEDEFAULT,
		int       Y            = CW_USEDEFAULT,
		int       nWidth       = CW_USEDEFAULT,
		int       nHeight      = CW_USEDEFAULT,
		HMENU     hMenu        = nullptr,
		HINSTANCE hInstance    = nullptr
	);

	virtual HWND createWindow(
		LPCWSTR     lpClassName,
		const RECT& rect,
		HWND        hWndParent   = nullptr,
		LPCWSTR     lpWindowName = L"Window",
		DWORD       dwStyle      = FrameWindowStyle,
		DWORD       dwExStyle    = FrameWindowStyleEx,
		HMENU       hMenu        = nullptr,
		HINSTANCE   hInstance    = nullptr
	);

	virtual void destroyWindow(void);
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class BasicModalTemplateDialog : public Window
{
private:
	LPCWSTR _DialogTemplateName{ nullptr };

public:
	explicit BasicModalTemplateDialog(LPCWSTR templateName);
	explicit BasicModalTemplateDialog(std::int32_t templateNameId);

public:
	virtual INT_PTR doModal(
		HWND hwndParent,
		HINSTANCE hinstance = nullptr
	);

	virtual void endDialog(INT_PTR result);
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class BasicModelessTemplateDialog : public Window
{
private:
	LPCWSTR _DialogTemplateName{ nullptr };

public:
	explicit BasicModelessTemplateDialog(LPCWSTR templateName);
	explicit BasicModelessTemplateDialog(std::int32_t templateNameId);

public:
	virtual HWND createDialog(HWND hwndParent, HINSTANCE hInstance = nullptr);
	virtual void destroyDialog(void);
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




