/////////////////////////////////////////////////////////////////////////////
//===========================================================================
#include "pch.hpp"

//===========================================================================
#include "wui.hpp"





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace wui
{





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
Font::Font(int size, const std::wstring& faceName)
{
	//-----------------------------------------------------------------------
	HDC   hdc;
	POINT pt    = { 0, 0 };
	POINT ptOrg = { 0, 0 };
	int   lpsy;


	// 72 points/inch, 10 decipoints/point
	hdc  = ::GetDC(NULL);
	lpsy = ::GetDeviceCaps(hdc, LOGPIXELSY);
	pt.y = ::MulDiv(lpsy, size, 720);
	::DPtoLP(hdc, &pt   , 1);
	::DPtoLP(hdc, &ptOrg, 1);
	::ReleaseDC(NULL, hdc);


	//-----------------------------------------------------------------------
	LOGFONTW logFont = {};


	logFont.lfCharSet = DEFAULT_CHARSET;
	logFont.lfHeight  = -abs(pt.y - ptOrg.y);
	lstrcpyW(logFont.lfFaceName, faceName.c_str());

	_FontHandle = ::CreateFontIndirectW(&logFont);
}

Font::~Font()
{
	::DeleteObject(_FontHandle);
}

//===========================================================================
HFONT Font::select(HDC hdc)
{
	return reinterpret_cast<HFONT>(::SelectObject(hdc, *this));
}





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}


