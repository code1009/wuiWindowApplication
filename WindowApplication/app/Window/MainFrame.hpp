#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class MainFrame : public wui::MessageMapWindow<MainFrame, wui::BaseWindow>
{
public:
	MainFrame();
	virtual ~MainFrame();

public:
	void onDestroy(wui::WindowMessage& windowMessage);
	void onClose(wui::WindowMessage& windowMessage);
};
