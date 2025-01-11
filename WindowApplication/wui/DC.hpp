#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace wui
{





//////////////////////////////////////////////////////////////////////////////
//============================================================================
class DC
{
private:
	HDC _DCHandle{ nullptr };

public:
	DC() = default;
	virtual ~DC() = default;

public:
	DC(const DC&) = delete;
	DC& operator=(const DC&) = delete;

	DC(DC&&) = delete;
	DC& operator=(DC&&) = delete;

public:
	[[nodiscard]] constexpr operator HDC (void) const
	{
		return _DCHandle;
	}

public:
	virtual HDC getDCHandle(void) const;
	virtual HDC setDCHandle(HDC handle);
};





//////////////////////////////////////////////////////////////////////////////
//============================================================================
class PaintDC : public DC
{
public:
	HWND        _hwnd { nullptr };
	PAINTSTRUCT _ps   { };

public:
	explicit PaintDC(HWND hwnd);

public:
	~PaintDC();
};





//////////////////////////////////////////////////////////////////////////////
//============================================================================
class ClientDC : public DC
{
public:
	HWND _hwnd { nullptr };

public:
	explicit ClientDC(HWND hwnd);

public:
	~ClientDC();
};





//////////////////////////////////////////////////////////////////////////////
//============================================================================
class WindowDC : public DC
{
public:
	HWND _hwnd { nullptr };

public:
	explicit WindowDC(HWND hwnd);

public:
	~WindowDC();
};





//////////////////////////////////////////////////////////////////////////////
//============================================================================
class MemoryDC : public DC
{
public:
	HDC     _hOriginalDC{ nullptr };
	RECT    _rcPaint    { 0, 0, 0, 0 };
	HBITMAP _hBitmap    { nullptr };
	HBITMAP _hOldBitmap { nullptr };

public:
	explicit MemoryDC(HDC hDC, const RECT& rcPaint);

public:
	~MemoryDC();
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}


