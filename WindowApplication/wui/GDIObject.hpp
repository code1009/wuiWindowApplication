#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace wui
{





//////////////////////////////////////////////////////////////////////////////
//============================================================================
class Font final
{
public:
	HFONT _FontHandle{ nullptr };

public:
	explicit Font(int size, const std::wstring& faceName);

public:
	~Font();

public:
	Font(const Font&) = delete;
	Font& operator=(const Font&) = delete;

	Font(Font&&) = delete;
	Font& operator=(Font&&) = delete;

public:
	[[nodiscard]] constexpr operator HFONT(void) const
	{
		return _FontHandle;
	}

public:
	HFONT select(HDC hdc);
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}


