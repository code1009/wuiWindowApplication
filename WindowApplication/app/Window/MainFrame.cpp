/////////////////////////////////////////////////////////////////////////////
//===========================================================================
#include "pch.hpp"

//===========================================================================
#include "../../wui/wui.hpp"
#include "../../res/resource.h"

//===========================================================================
#include "MainFrame.hpp"
#include "AboutBox.hpp"





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
	_WindowMessageMap.handle(WM_CREATE)     = &MainFrame::onCreate;
	_WindowMessageMap.handle(WM_DESTROY)    = &MainFrame::onDestroy;
	_WindowMessageMap.handle(WM_CLOSE)      = &MainFrame::onClose;
	_WindowMessageMap.handle(WM_PAINT)      = &MainFrame::onPaint;
//	_WindowMessageMap.handle(WM_ERASEBKGND) = &MainFrame::onEraseBkgnd;
	_WindowMessageMap.handle(WM_COMMAND)    = &MainFrame::onCommand;
}

void MainFrame::onCreate(wui::WindowMessage& windowMessage)
{
	wui::WM_CREATE_WindowMessageCrack wm { windowMessage };


	::MessageBoxW(*this, L"Hello, Windows!", wm.lpCreateStruct()->lpszClass, MB_OK);
}

void MainFrame::onDestroy(wui::WindowMessage& windowMessage)
{
	::PostQuitMessage(0);
}

void MainFrame::onClose(wui::WindowMessage& windowMessage)
{
	destroyWindow();
}

void MainFrame::onPaint(wui::WindowMessage& windowMessage)
{
	wui::PaintDC paintDC{ *this };
	

	::TextOutW(paintDC, 10, 10, L"Hello, Windows!", 15);
}

void MainFrame::onEraseBkgnd(wui::WindowMessage& windowMessage)
{
	wui::WM_ERASEBKGND_WindowMessageCrack wm{ windowMessage };


	wm.Result(FALSE);
}

void MainFrame::onCommand(wui::WindowMessage& windowMessage)
{
	wui::WM_COMMAND_WindowMessageCrack wm{ windowMessage };


	if (wm.wndCtl() == nullptr)
	{
		onMenuCommand(windowMessage);
	}
	else
	{
		onCtlCommand(windowMessage);
	}
}

void MainFrame::onMenuCommand(wui::WindowMessage& windowMessage)
{
	wui::WM_COMMAND_WindowMessageCrack wm{ windowMessage };


	switch (wm.nID())
	{
	case IDM_ABOUT:
		onAppAbout(windowMessage);
		break;

	case IDM_EXIT:
		::PostMessage(*this, WM_CLOSE, 0, 0);
		break;

	default:
		callWindowProc(windowMessage);
		break;
	}
}

void MainFrame::onAppAbout(wui::WindowMessage& windowMessage)
{
	AboutBox aboutBox;


	aboutBox.doModal(*this);
}

void MainFrame::onCtlCommand(wui::WindowMessage& windowMessage)
{
	wui::WM_COMMAND_WindowMessageCrack wm{ windowMessage };


	switch (wm.nID())
	{
	case IDC_WINDOWAPPLICATION:
		::MessageBox(*this, L"WindowApplication", L"WindowApplication", MB_OK);
		break;

	default:
		callWindowProc(windowMessage);
	}
}
