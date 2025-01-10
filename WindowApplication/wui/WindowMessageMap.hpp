#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace wui
{





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
template <typename TWindow>
class WindowMessageMapT final
{
public:
	using WindowMessageHandler = WindowMessageHandlerT<TWindow>;
	using WindowMessageMapContainer = std::map<std::uint32_t, WindowMessageHandler>;

private:
	WindowMessageMapContainer _WindowMessageMapContainer{};

public:
	void registerWindowMessageHandler(UINT umsg, WindowMessageHandler handler)
	{
		_WindowMessageMapContainer[umsg] = handler;
	}

	void unregisterWindowMessageHandler(UINT umsg, WindowMessageHandler handler)
	{
		_WindowMessageMapContainer.erase(umsg);
	}

public:
	WindowMessageHandler& on(std::uint32_t umsg)
	{
		return _WindowMessageMapContainer[umsg];
	}

public:
	bool onWindowMessage(TWindow* window, WindowMessage& windowMessage)
	{
		auto found = _WindowMessageMapContainer.find(windowMessage.uMsg);


		if (found != _WindowMessageMapContainer.end())
		{
			auto handler = (*found).second;


			if (handler)
			{
				(window->*handler)(windowMessage);

				return true;
			}
		}

		return false;
	}
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




