/////////////////////////////////////////////////////////////////////////////
//===========================================================================
#include "pch.hpp"

//===========================================================================
#include "../../wui/wui.hpp"
#include "../../res/resource.h"

//===========================================================================
#include "MainFrame.hpp"






/////////////////////////////////////////////////////////////////////////////
//===========================================================================
constexpr LPCWSTR MainFrame_WindowClassName = L"MainFrame";





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
MainFrame::MainFrame()
{
	//-----------------------------------------------------------------------
	registerWindowMessageMapHandler();


	//-----------------------------------------------------------------------
	wui::WindowClass windowClass;


	windowClass.registerWindowClass(
		nullptr,
		MainFrame_WindowClassName,
		IDC_WINDOWAPPLICATION,
		IDI_WINDOWAPPLICATION, IDI_SMALL
	);


	//-----------------------------------------------------------------------
	createWindow(MainFrame_WindowClassName);


	::ShowWindow(*this, SW_SHOW);
	::UpdateWindow(*this);
}

MainFrame::~MainFrame()
{
}

void MainFrame::registerWindowMessageMapHandler(void)
{
	_WindowMessageMap.handle(WM_CREATE) = &MainFrame::onCreate;
	_WindowMessageMap.handle(WM_DESTROY) = &MainFrame::onDestroy;
	_WindowMessageMap.handle(WM_CLOSE) = &MainFrame::onClose;

	_WindowMessageMap.handle(WM_PAINT) = &MainFrame::onDestroy;
	_WindowMessageMap.handle(WM_ERASEBKGND) = &MainFrame::onClose;
}

void MainFrame::onCreate(wui::WindowMessage& windowMessage)
{
	wui::WM_CREATE_WindowMessageCrack wm { windowMessage };


	::MessageBox(*this, L"Hello, Windows!", wm.lpCreateStruct()->lpszClass, MB_OK);

	wm.Result(0);
}

void MainFrame::onDestroy(wui::WindowMessage& windowMessage)
{
	wui::WM_DESTROY_WindowMessageCrack wm{ windowMessage };


	::PostQuitMessage(0);

	wm.Result();
}

void MainFrame::onClose(wui::WindowMessage& windowMessage)
{
	wui::WM_CLOSE_WindowMessageCrack wm{ windowMessage };


	destroyWindow();

	wm.Result();
}

void MainFrame::onPaint(wui::WindowMessage& windowMessage)
{
	wui::WM_PAINT_WindowMessageCrack wm{ windowMessage };


	wm.hdc();

	wm.Result();
}

void MainFrame::onEraseBkgnd(wui::WindowMessage& windowMessage)
{
	wui::WM_ERASEBKGND_WindowMessageCrack wm{ windowMessage };


	wm.Result(TRUE);
}
