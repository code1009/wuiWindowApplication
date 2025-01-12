#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class AboutBox : public wui::MessageMapWindow<AboutBox, wui::BaseModalTemplateDialog>
{
public:
	AboutBox()
	{
		setTemplateName(IDD_ABOUTBOX);

		registerWindowMessageMapHandler();
	}

	virtual ~AboutBox() 
	{

	}

	//-----------------------------------------------------------------------
	// wui::MessageMapWindow<AboutBox, wui::BaseModalTemplateDialog>
public:
	virtual void registerWindowMessageMapHandler(void) override
	{
		_WindowMessageMap.handle(WM_INITDIALOG) = &AboutBox::onInitDialog;
		_WindowMessageMap.handle(WM_DESTROY)    = &AboutBox::onDestroy;
		_WindowMessageMap.handle(WM_CLOSE)      = &AboutBox::onClose;
		_WindowMessageMap.handle(WM_COMMAND)    = &AboutBox::onCommand;
	}

	//-----------------------------------------------------------------------
public:
	void onInitDialog(wui::WindowMessage& windowMessage)
	{
		wui::WM_INITDIALOG_WindowMessageCrack wm{ windowMessage };


		OutputDebugStringW(L"AboutBox::onInitDialog\n");

		wm.Result(TRUE);
	}

	void onDestroy(wui::WindowMessage& windowMessage)
	{
		OutputDebugStringW(L"AboutBox::onDestroy\n");
	}

	void onClose(wui::WindowMessage& windowMessage)
	{
		::EndDialog(*this, IDCANCEL);
		windowMessage.setResult(TRUE);
	}

	void onCommand(wui::WindowMessage& windowMessage)
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
};
