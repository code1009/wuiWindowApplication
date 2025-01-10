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
constexpr LPCWSTR MainFrame_ClassName = L"MainFrame";





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
MainFrame::MainFrame()
{
	//-----------------------------------------------------------------------
	registerWindowMessageHandler();


	//-----------------------------------------------------------------------
	wui::WindowClass windowClass;


	windowClass.registerWindowClass(
		nullptr,
		MainFrame_ClassName,
		IDC_WINDOWAPPLICATION,
		IDI_WINDOWAPPLICATION, IDI_SMALL
	);


	//-----------------------------------------------------------------------
	createWindow(MainFrame_ClassName);


	::ShowWindow(*this, SW_SHOW);
	::UpdateWindow(*this);
}

MainFrame::~MainFrame()
{
}

void MainFrame::registerWindowMessageHandler(void)
{
	_WindowMessageMap.on(WM_CREATE) = &MainFrame::onCreate;
	_WindowMessageMap.on(WM_DESTROY) = &MainFrame::onDestroy;
	_WindowMessageMap.on(WM_CLOSE) = &MainFrame::onClose;
}

void MainFrame::onCreate(wui::WindowMessage& windowMessage)
{
	wui::WM_CREATE_WindowMessageCrack wm { windowMessage };

	::MessageBox(*this, L"Hello, Windows!", wm.lpCreateStruct()->lpszClass, MB_OK);
}

void MainFrame::onDestroy(wui::WindowMessage& windowMessage)
{
	::PostQuitMessage(0);
}

void MainFrame::onClose(wui::WindowMessage& windowMessage)
{
	destroyWindow();
}
