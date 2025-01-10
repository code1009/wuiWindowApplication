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
	wui::WindowClass windowClass;


	windowClass.registerWindowClass(
		nullptr,
		MainFrame_ClassName,
		IDC_WINDOWAPPLICATION,
		IDI_WINDOWAPPLICATION, IDI_SMALL
	);

	createWindow(MainFrame_ClassName);


	::ShowWindow(*this, SW_SHOW);
	::UpdateWindow(*this);
}

MainFrame::~MainFrame()
{
}
