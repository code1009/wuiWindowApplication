#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace wui
{





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class AppModule
{
private:
	HINSTANCE _InstanceHandle{ nullptr };

public:
	AppModule() = default;
	virtual ~AppModule() = default;

public:
	AppModule(const AppModule&) = delete;
	AppModule& operator=(const AppModule&) = delete;

	AppModule(AppModule&&) = delete;
	AppModule& operator=(AppModule&&) = delete;

public:
	HINSTANCE getInstanceHandle(void) const;
	HINSTANCE setInstanceHandle(HINSTANCE handle);
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
AppModule* getAppModule(void);





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




