/////////////////////////////////////////////////////////////////////////////
//===========================================================================
#include "pch.hpp"
#include "framework.hpp"
#include "../wui/wui.hpp"
#include "Main.hpp"
#include "Window/MainFrame.hpp"





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
int APIENTRY wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR    lpCmdLine,
	int       nCmdShow)
{
	wui::getAppModule()->setInstanceHandle(hInstance);

	
	MainFrame mainFrame;


	wui::MessageLoop messageLoop;


	messageLoop.run();


	return 0;
}
