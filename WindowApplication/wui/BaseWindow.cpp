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
LRESULT BaseSubclassWindow::callWindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
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
WNDPROC BaseSubclassWindow::subclassWindow(HWND hwnd)
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

WNDPROC BaseSubclassWindow::unsubclassWindow(WNDPROC windowProc)
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

WNDPROC BaseSubclassWindow::getChainWindowProc(void)
{
	return _ChainWindowProc;
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
HWND BaseWindow::createWindow(
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

HWND BaseWindow::createWindow(
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

void BaseWindow::destroyWindow(void)
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
void BaseModalTemplateDialog::setTemplateName(LPCWSTR templateName)
{
	_DialogTemplateName = templateName;
}

void BaseModalTemplateDialog::setTemplateName(std::int32_t templateNameId)
{
	setTemplateName(MAKEINTRESOURCEW(templateNameId));
}

//===========================================================================
INT_PTR BaseModalTemplateDialog::doModal(
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

void BaseModalTemplateDialog::endDialog(INT_PTR result)
{
	BOOL rv;


	rv = ::EndDialog(getWindowHandle(), result);
	if (FALSE == rv)
	{
		throw std::runtime_error("BaseModalTemplateDialog::endDialog(): EndDialog() failed");
	}
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
void BaseModelessTemplateDialog::setTemplateName(LPCWSTR templateName)
{
	_DialogTemplateName = templateName;
}

void BaseModelessTemplateDialog::setTemplateName(std::int32_t templateNameId)
{
	setTemplateName(MAKEINTRESOURCEW(templateNameId));
}

HWND BaseModelessTemplateDialog::createDialog(HWND hwndParent, HINSTANCE hInstance)
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

void BaseModelessTemplateDialog::destroyDialog(void)
{
	HWND handle;
	BOOL rv;


	handle = getWindowHandle();
	if (handle)
	{
		rv = ::DestroyWindow(handle);
		if (FALSE == rv)
		{
			throw std::runtime_error("BaseModelessTemplateDialog::destroyDialog(): DestroyWindow() failed");
		}

		setWindowHandle(nullptr);
	}
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




