/////////////////////////////////////////////////////////////////////////////
//===========================================================================
#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace wui
{





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class WindowMessageLoop
{
private:
	std::vector< std::function<void(void)> > _idleHandlers;

public:
	WindowMessageLoop() = default;

public:
	virtual ~WindowMessageLoop() = default;

public:
	WindowMessageLoop(const WindowMessageLoop&) = delete;
	WindowMessageLoop& operator=(const WindowMessageLoop&) = delete;

	WindowMessageLoop(WindowMessageLoop&&) = delete;
	WindowMessageLoop& operator=(WindowMessageLoop&&) = delete;

public:
	virtual void addIdleHandler(std::function<void(void)> handler);

public:
	virtual void run(void);
	virtual void onIdle(void);
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




