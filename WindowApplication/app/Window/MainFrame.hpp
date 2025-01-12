#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class MainFrame : public wui::MessageMapWindow<MainFrame, wui::BaseWindow>
{
public:
	MainFrame();
	virtual ~MainFrame();

	//-----------------------------------------------------------------------
	// wui::MessageMapWindow<MainFrame, wui::BaseWindow>
public:
	virtual void registerWindowMessageMapHandler(void) override;

	//-----------------------------------------------------------------------
public:
	void onCreate(wui::WindowMessage& windowMessage);
	void onDestroy(wui::WindowMessage& windowMessage);
	void onClose(wui::WindowMessage& windowMessage);
	void onPaint(wui::WindowMessage& windowMessage);
	void onEraseBkgnd(wui::WindowMessage& windowMessage);
	void onCommand(wui::WindowMessage& windowMessage);
	void onMenuCommand(wui::WindowMessage& windowMessage);
	void onCtlCommand(wui::WindowMessage& windowMessage);

public:
	void onAppAbout(wui::WindowMessage& windowMessage);
};
