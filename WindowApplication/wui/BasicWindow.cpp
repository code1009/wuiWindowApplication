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
LRESULT SubclassWindow::callWindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	LRESULT lResult;


	if (_ChainWindowProc)
	{
		lResult = ::CallWindowProcW(
			_ChainWindowProc,
			hwnd,
			umsg,
			wparam,
			lparam
		);
	}
	else
	{
		lResult = 0;
		throw std::runtime_error("SubclassWindow::DefaultWindowProc(): _ChainWindowProc is null");
	}

	return lResult;
}

//===========================================================================
WNDPROC SubclassWindow::subclassWindow(HWND hwnd)
{
	//-----------------------------------------------------------------------
#ifdef _DEBUG
	if (reinterpret_cast<void*>(::GetWindowLongPtrW(hwnd, GWLP_USERDATA)))
	{
		throw std::runtime_error("SubclassWindow::subclassWindow(): GWLP_USERDATA");
	}
#endif


	//-----------------------------------------------------------------------
	setWindowHandle(hwnd);


	//-----------------------------------------------------------------------
	LONG_PTR rv;
	WNDPROC oldWindowProc;


	rv = ::SetWindowLongPtrW(getWindowHandle(), GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
	rv = ::SetWindowLongPtrW(getWindowHandle(), GWLP_WNDPROC , reinterpret_cast<LONG_PTR>(WindowProc));
	oldWindowProc = reinterpret_cast<WNDPROC>(rv);


	//-----------------------------------------------------------------------
	_ChainWindowProc = oldWindowProc;


	return oldWindowProc;
}

WNDPROC SubclassWindow::unsubclassWindow(WNDPROC windowProc)
{
	//-----------------------------------------------------------------------
	if (nullptr == windowProc)
	{
		windowProc = _ChainWindowProc;
	}


	//-----------------------------------------------------------------------
	LONG_PTR rv;
	WNDPROC oldWindowProc;


	rv = ::SetWindowLongPtrW(getWindowHandle(), GWLP_USERDATA, reinterpret_cast<LONG_PTR>(nullptr));
	rv = ::SetWindowLongPtrW(getWindowHandle(), GWLP_WNDPROC , reinterpret_cast<LONG_PTR>(windowProc));
	oldWindowProc = reinterpret_cast<WNDPROC>(rv);


	//-----------------------------------------------------------------------
	setWindowHandle(nullptr);
	_ChainWindowProc = nullptr;


	return oldWindowProc;
}

WNDPROC SubclassWindow::getChainWindowProc(void)
{
	return _ChainWindowProc;
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
HWND BasicWindow::createWindow(
	LPCWSTR   lpClassName ,
	HWND      hWndParent  ,
	LPCWSTR   lpWindowName,
	DWORD     dwStyle     ,
	DWORD     dwExStyle   ,
	int       X           ,
	int       Y           ,
	int       nWidth      ,
	int       nHeight     ,
	HMENU     hMenu       ,
	HINSTANCE hInstance
)
{
	//-----------------------------------------------------------------------
	if (nullptr == hInstance)
	{
		hInstance = getAppModule()->getInstanceHandle();
	}


	//-----------------------------------------------------------------------
	HWND handle;


	handle = ::CreateWindowExW(
		dwExStyle,
		lpClassName,
		lpWindowName,
		dwStyle,
		X,
		Y,
		nWidth,
		nHeight,
		hWndParent,
		hMenu,
		hInstance,
		this
	);

	return handle;
}

HWND BasicWindow::createWindow(
	LPCWSTR     lpClassName ,
	const RECT& rect        ,
	HWND        hWndParent  ,
	LPCWSTR     lpWindowName,
	DWORD       dwStyle     ,
	DWORD       dwExStyle   ,
	HMENU       hMenu       ,
	HINSTANCE   hInstance   
)
{
	return createWindow(
		lpClassName,
		hWndParent,
		lpWindowName,
		dwStyle,
		dwExStyle,
		rect.left,
		rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		hMenu,
		hInstance
	);
}

void BasicWindow::destroyWindow(void)
{
	HWND handle;
	BOOL rv;


	handle = getWindowHandle();
	if (handle)
	{
		rv = ::DestroyWindow(handle);
		if (FALSE == rv)
		{
			throw std::runtime_error("BasicWindow::destroyWindow(): DestroyWindow() failed");
		}

		setWindowHandle(nullptr);
	}
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
BasicModalTemplateDialog::BasicModalTemplateDialog(LPCWSTR templateName) :
	_DialogTemplateName{ templateName }
{
}

BasicModalTemplateDialog::BasicModalTemplateDialog(std::int32_t templateNameId) :
	_DialogTemplateName{ MAKEINTRESOURCEW(templateNameId) }
{
}

//===========================================================================
INT_PTR BasicModalTemplateDialog::doModal(
	HWND hwndParent,
	HINSTANCE hInstance
)
{
	//-----------------------------------------------------------------------
	if (nullptr == hInstance)
	{
		hInstance = getAppModule()->getInstanceHandle();
	}


	//-----------------------------------------------------------------------
	std::int64_t rv;


	rv = ::DialogBoxParamW(
		hInstance,
		_DialogTemplateName,
		hwndParent,
		DialogProc,
		reinterpret_cast<LPARAM>(this)
	);

	return rv;
}

void BasicModalTemplateDialog::endDialog(INT_PTR result)
{
	BOOL rv;


	rv = ::EndDialog(getWindowHandle(), result);
	if (FALSE == rv)
	{
		throw std::runtime_error("BasicModalTemplateDialog::endDialog(): EndDialog() failed");
	}
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
BasicModelessTemplateDialog::BasicModelessTemplateDialog(LPCWSTR templateName) :
	_DialogTemplateName{ templateName }
{
}

BasicModelessTemplateDialog::BasicModelessTemplateDialog(std::int32_t templateNameId) :
	_DialogTemplateName{ MAKEINTRESOURCEW(templateNameId) }
{
}

HWND BasicModelessTemplateDialog::createDialog(HWND hwndParent, HINSTANCE hInstance)
{
	HWND hwnd;


	hwnd = ::CreateDialogParamW(
		hInstance,
		_DialogTemplateName,
		hwndParent,
		DialogProc,
		reinterpret_cast<LPARAM>(this)
	);

	return hwnd;
}

void BasicModelessTemplateDialog::destroyDialog(void)
{
	HWND handle;
	BOOL rv;


	handle = getWindowHandle();
	if (handle)
	{
		rv = ::DestroyWindow(handle);
		if (FALSE == rv)
		{
			throw std::runtime_error("BasicModelessTemplateDialog::destroyDialog(): DestroyWindow() failed");
		}

		setWindowHandle(nullptr);
	}
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




