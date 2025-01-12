/////////////////////////////////////////////////////////////////////////////
//===========================================================================
#include "pch.hpp"

//===========================================================================
#include "../../wui/wui.hpp"
#include "../../res/resource.h"

//===========================================================================
#include "MyBox.hpp"





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
MyBox::MyBox()
{
	initializeDialogTemplate();

	registerWindowMessageMapHandler();
}

MyBox::~MyBox()
{
}

//===========================================================================
void MyBox::initializeDialogTemplate(void)
{
	wui::MemoryDialogTemplateWriter w(_DialogTemplate);

	w.BEGIN_DIALOG(10, 10, 200, 100);
	w.DIALOG_CAPTION(L"My Dialog");
	w.DIALOG_STYLE(WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU);
	w.DIALOG_FONT(8, L"MS Shell Dlg");
	w.END_DIALOG();

	w.BEGIN_CONTROLS_MAP();
	w.CONTROL_PUSHBUTTON(L"OK", IDOK, 50, 70, 50, 14, WS_TABSTOP);
	w.CONTROL_PUSHBUTTON(L"Cancel", IDCANCEL, 110, 70, 50, 14, WS_TABSTOP);
	w.END_CONTROLS_MAP();


	setTemplate(_DialogTemplate.getTemplatePtr());
}

//===========================================================================
void MyBox::registerWindowMessageMapHandler(void)
{
	_WindowMessageMap.handle(WM_INITDIALOG) = &MyBox::onInitDialog;
	_WindowMessageMap.handle(WM_DESTROY) = &MyBox::onDestroy;
	_WindowMessageMap.handle(WM_CLOSE) = &MyBox::onClose;
	_WindowMessageMap.handle(WM_COMMAND) = &MyBox::onCommand;
}

//===========================================================================
void MyBox::onInitDialog(wui::WindowMessage& windowMessage)
{
	wui::WM_INITDIALOG_WindowMessageCrack wm{ windowMessage };


	OutputDebugStringW(L"MyBox::onInitDialog\n");

	wm.Result(TRUE);
}

void MyBox::onDestroy(wui::WindowMessage& windowMessage)
{
	OutputDebugStringW(L"MyBox::onDestroy\n");
}

void MyBox::onClose(wui::WindowMessage& windowMessage)
{
	::EndDialog(*this, IDCANCEL);
	windowMessage.setResult(TRUE);
}

void MyBox::onCommand(wui::WindowMessage& windowMessage)
{
	wui::WM_COMMAND_WindowMessageCrack wm{ windowMessage };


	switch (wm.nID())
	{
	case IDOK:
		::EndDialog(*this, IDOK);
		wm.Result(TRUE);
		break;

	case IDCANCEL:
		::EndDialog(*this, IDCANCEL);
		wm.Result(TRUE);
		break;

	default:
		wm.Result(FALSE);
		break;
	}
}
