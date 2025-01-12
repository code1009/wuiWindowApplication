#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class MyBox : public wui::MessageMapWindow<MyBox, wui::BaseModalIndirectDialog>
{
public:
	wui::MemoryDialogTemplate _DialogTemplate;

public:
	MyBox();
	virtual ~MyBox();

	//-----------------------------------------------------------------------
	void initializeDialogTemplate(void);

	//-----------------------------------------------------------------------
	// wui::MessageMapWindow<MyBox, wui::BaseModalIndirectDialog>
public:
	virtual void registerWindowMessageMapHandler(void) override;

	//-----------------------------------------------------------------------
public:
	void onInitDialog(wui::WindowMessage& windowMessage);
	void onDestroy(wui::WindowMessage& windowMessage);
	void onCommand(wui::WindowMessage& windowMessage);
};
