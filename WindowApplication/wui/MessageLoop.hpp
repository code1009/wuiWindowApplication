/////////////////////////////////////////////////////////////////////////////
//===========================================================================
#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace wui
{





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class MessageLoop
{
private:
	std::vector< std::function<void(void)> > _idleHandlers;

public:
	MessageLoop() = default;

public:
	virtual ~MessageLoop() = default;

public:
	MessageLoop(const MessageLoop&) = delete;
	MessageLoop& operator=(const MessageLoop&) = delete;

	MessageLoop(MessageLoop&&) = delete;
	MessageLoop& operator=(MessageLoop&&) = delete;

public:
	virtual void addIdleHandler(std::function<void(void)> handler);

public:
	virtual void run(void);
	virtual void onIdle(void);
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




