#pragma once





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
namespace wui
{






/////////////////////////////////////////////////////////////////////////////
//===========================================================================
class WindowMessageCrack
{
public:
	WindowMessage& _WindowMessage;

public:
	WindowMessageCrack(WindowMessage& windowMessage) :
		_WindowMessage{ windowMessage }
	{
	}

public:
	WindowMessageCrack(const WindowMessageCrack&) = delete;
	WindowMessageCrack& operator=(const WindowMessageCrack&) = delete;

	WindowMessageCrack(WindowMessageCrack&&) = delete;
	WindowMessageCrack& operator=(WindowMessageCrack&&) = delete;
};





/////////////////////////////////////////////////////////////////////////////
//
// Standard Windows message macros
// https://github.com/Win32-WTL/WTL/blob/main/Include/atlcrack.h
// 
/////////////////////////////////////////////////////////////////////////////
//===========================================================================





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
//int OnCreate(LPCREATESTRUCT lpCreateStruct)
/*
WM_CREATE
		lResult = (LRESULT)func((LPCREATESTRUCT)lParam);
*/
class WM_CREATE_WindowMessageCrack : public WindowMessageCrack
{
public:
	LPCREATESTRUCT lpCreateStruct(void){return (LPCREATESTRUCT)(_WindowMessage.lParam);}

public:
	void Result(int rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
// BOOL OnInitDialog(CWindow wndFocus, LPARAM lInitParam)
/*
WM_INITDIALOG
		lResult = (LRESULT)func((HWND)wParam, lParam);
*/
class WM_INITDIALOG_WindowMessageCrack : public WindowMessageCrack
{
public:
	HWND wndFocus(void){return (HWND)_WindowMessage.wParam;}
	LPARAM lInitParam(void){return _WindowMessage.lParam;}

public:
	void Result(BOOL rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
// BOOL OnCopyData(CWindow wnd, PCOPYDATASTRUCT pCopyDataStruct)
/*
WM_COPYDATA
		lResult = (LRESULT)func((HWND)wParam, (PCOPYDATASTRUCT)lParam);
*/
class WM_COPYDATA_WindowMessageCrack : public WindowMessageCrack
{
public:
	HWND wnd(void){return (HWND)_WindowMessage.wParam;}
	PCOPYDATASTRUCT pCopyDataStruct(void){return (PCOPYDATASTRUCT)_WindowMessage.lParam;}

public:
	void Result(BOOL rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
//void OnDestroy()
/*
WM_DESTROY
	func(); \
	lResult = 0; \
*/
class WM_DESTROY_WindowMessageCrack : public WindowMessageCrack
{
public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnMove(CPoint ptPos)
/*
WM_MOVE
		func(_WTYPES_NS::CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
*/
class WM_MOVE_WindowMessageCrack : public WindowMessageCrack
{
public:
	POINT point(void)
	{
		POINT pt{ GET_X_LPARAM(_WindowMessage.lParam), GET_Y_LPARAM(_WindowMessage.lParam) };

		return pt;
	}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnSize(UINT nType, CSize size)
/*
WM_SIZE
		func((UINT)wParam, _WTYPES_NS::CSize(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
*/
class WM_SIZE_WindowMessageCrack : public WindowMessageCrack
{
public:
	UINT nTYPE(void)
	{
		return (UINT)_WindowMessage.wParam;
	}

	SIZE size(void)
	{
		SIZE size{ GET_X_LPARAM(_WindowMessage.lParam), GET_Y_LPARAM(_WindowMessage.lParam) };

		return size;
	}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnActivate(UINT nState, BOOL bMinimized, CWindow wndOther)
/*
WM_ACTIVATE
		func((UINT)LOWORD(wParam), (BOOL)HIWORD(wParam), (HWND)lParam); \
		lResult = 0; \
*/
class WM_ACTIVATE_WindowMessageCrack : public WindowMessageCrack
{
public:
	UINT nState(void){return (UINT)LOWORD(_WindowMessage.wParam);}
	BOOL bMinimized(void){return (BOOL)HIWORD(_WindowMessage.wParam);}
	HWND wndOther(void){return (HWND)_WindowMessage.lParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnSetFocus(CWindow wndOld)
/*
WM_SETFOCUS
		func((HWND)wParam); \
		lResult = 0; \
*/
class WM_SETFOCUS_WindowMessageCrack : public WindowMessageCrack
{
public:
	HWND wndOld(void){return (HWND)_WindowMessage.wParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnKillFocus(CWindow wndFocus)
/*
WM_KILLFOCUS
		func((HWND)wParam); \
		lResult = 0; \
*/
class WM_KILLFOCUS_WindowMessageCrack : public WindowMessageCrack
{
public:
	HWND wndFocus(void){return (HWND)_WindowMessage.wParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnEnable(BOOL bEnable)
/*
WM_ENABLE
		func((BOOL)wParam); \
		lResult = 0; \
*/
class WM_ENABLE_WindowMessageCrack : public WindowMessageCrack
{
public:
	BOOL bEnable(void){return (BOOL)_WindowMessage.wParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnPaint(CDCHandle dc)
/*
WM_PAINT
		func((HDC)wParam); \
		lResult = 0; \
*/
class WM_PAINT_WindowMessageCrack : public WindowMessageCrack
{
public:
	HDC hdc(void){return (HDC)_WindowMessage.wParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnClose()
/*
WM_CLOSE
		func(); \
		lResult = 0; \
*/
class WM_CLOSE_WindowMessageCrack : public WindowMessageCrack
{
public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// BOOL OnQueryEndSession(UINT nSource, UINT uLogOff)
/*
WM_QUERYENDSESSION
		lResult = (LRESULT)func((UINT)wParam, (UINT)lParam); \
*/
class WM_QUERYENDSESSION_WindowMessageCrack : public WindowMessageCrack
{
public:
	UINT nSource(void){return (UINT)_WindowMessage.wParam;}
	UINT uLogOff(void){return (UINT)_WindowMessage.lParam;}

public:
	void Result(BOOL rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
// BOOL OnQueryOpen()
/*
WM_QUERYOPEN
		lResult = (LRESULT)func(); \
*/
class WM_QUERYOPEN_WindowMessageCrack : public WindowMessageCrack
{
public:
	void Result(BOOL rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
// BOOL OnEraseBkgnd(CDCHandle dc)
/*
WM_ERASEBKGND
		lResult = (LRESULT)func((HDC)wParam); \
*/
class WM_ERASEBKGND_WindowMessageCrack : public WindowMessageCrack
{
public:
	HDC hdc(void){return (HDC)_WindowMessage.wParam;}

public:
	void Result(BOOL rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
// void OnSysColorChange()
/*
WM_SYSCOLORCHANGE
		func(); \
		lResult = 0; \
*/
class WM_SYSCOLORCHANGE_WindowMessageCrack : public WindowMessageCrack
{
public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnEndSession(BOOL bEnding, UINT uLogOff)
/*
WM_ENDSESSION
		func((BOOL)wParam, (UINT)lParam); \
		lResult = 0; \
*/
class WM_ENDSESSION_WindowMessageCrack : public WindowMessageCrack
{
public:
	BOOL bEnding(void){return (BOOL)_WindowMessage.wParam;}
	UINT uLogOff(void){return (UINT)_WindowMessage.lParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnShowWindow(BOOL bShow, UINT nStatus)
/*
WM_SHOWWINDOW
		func((BOOL)wParam, (int)lParam); \
		lResult = 0; \
*/
class WM_SHOWWINDOW_WindowMessageCrack : public WindowMessageCrack
{
public:
	BOOL bShow(void){return (BOOL)_WindowMessage.wParam;}
	UINT nStatus(void){return (UINT)_WindowMessage.lParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// HBRUSH OnCtlColorEdit(CDCHandle dc, CEdit edit)
/*
WM_CTLCOLOREDIT
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
*/
class WM_CTLCOLOREDIT_WindowMessageCrack : public WindowMessageCrack
{
public:
	HDC hdc(void){return (HDC)_WindowMessage.wParam;}
	HWND ctl(void){return (HWND)_WindowMessage.lParam;}

public:
	void Result(HBRUSH rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
// HBRUSH OnCtlColorListBox(CDCHandle dc, CListBox listBox)
/*
WM_CTLCOLORLISTBOX
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
*/
using WM_CTLCOLORLISTBOX_WindowMessageCrack = WM_CTLCOLOREDIT_WindowMessageCrack;

//===========================================================================
// HBRUSH OnCtlColorBtn(CDCHandle dc, CButton button)
/*
WM_CTLCOLORBTN
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
*/
using WM_CTLCOLORBTN_WindowMessageCrack = WM_CTLCOLOREDIT_WindowMessageCrack;

//===========================================================================
// HBRUSH OnCtlColorDlg(CDCHandle dc, CWindow wnd)
/*
WM_CTLCOLORDLG
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
*/
using WM_CTLCOLORDLG_WindowMessageCrack = WM_CTLCOLOREDIT_WindowMessageCrack;

//===========================================================================
// HBRUSH OnCtlColorScrollBar(CDCHandle dc, CScrollBar scrollBar)
/*
WM_CTLCOLORSCROLLBAR
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
*/
using WM_CTLCOLORSCROLLBAR_WindowMessageCrack = WM_CTLCOLOREDIT_WindowMessageCrack;

//===========================================================================
// HBRUSH OnCtlColorStatic(CDCHandle dc, CStatic wndStatic)
/*
WM_CTLCOLORSTATIC
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
*/
using WM_CTLCOLORSTATIC_WindowMessageCrack = WM_CTLCOLOREDIT_WindowMessageCrack;

//===========================================================================
// void OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
/*
WM_SETTINGCHANGE
		func((UINT)wParam, (LPCTSTR)lParam); \
		lResult = 0; \
*/
class WM_SETTINGCHANGE_WindowMessageCrack : public WindowMessageCrack
{
public:
	UINT uFlags(void){return (UINT)_WindowMessage.wParam;}
	LPCTSTR lpszSection(void){return (LPCTSTR)_WindowMessage.lParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// OnDevModeChange(LPCTSTR lpDeviceName)
/*
WM_DEVMODECHANGE
		func((LPCTSTR)lParam); \
		lResult = 0; \
*/
class WM_DEVMODECHANGE_WindowMessageCrack : public WindowMessageCrack
{
public:
	LPCTSTR lpDeviceName(void){return (LPCTSTR)_WindowMessage.lParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnActivateApp(BOOL bActive, DWORD dwThreadID)
/*
WM_ACTIVATEAPP
		func((BOOL)wParam, (DWORD)lParam); \
		lResult = 0; \
*/
class WM_ACTIVATEAPP_WindowMessageCrack : public WindowMessageCrack
{
public:
	BOOL bActive(void){return (BOOL)_WindowMessage.wParam;}
	DWORD dwThreadID(void){return (DWORD)_WindowMessage.lParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnFontChange()
/*
WM_FONTCHANGE
		func(); \
		lResult = 0; \
*/
class WM_FONTCHANGE_WindowMessageCrack : public WindowMessageCrack
{
public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnTimeChange()
/*
WM_TIMECHANGE
		func(); \
		lResult = 0; \
*/
class WM_TIMECHANGE_WindowMessageCrack : public WindowMessageCrack
{
public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnCancelMode()
/*
WM_CANCELMODE
		func(); \
		lResult = 0; \
*/
class WM_CANCELMODE_WindowMessageCrack : public WindowMessageCrack
{
public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// BOOL OnSetCursor(CWindow wnd, UINT nHitTest, UINT message)
/*
WM_SETCURSOR
		lResult = (LRESULT)func((HWND)wParam, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)); \
*/
class WM_SETCURSOR_WindowMessageCrack : public WindowMessageCrack
{
public:
	HWND wnd(void){return (HWND)_WindowMessage.wParam;}
	UINT nHitTest(void){return (UINT)LOWORD(_WindowMessage.lParam);}
	UINT message(void){return (UINT)HIWORD(_WindowMessage.lParam);}

public:
	void Result(BOOL rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
// int OnMouseActivate(CWindow wndTopLevel, UINT nHitTest, UINT message)
/*
WM_MOUSEACTIVATE
		lResult = (LRESULT)func((HWND)wParam, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)); \
*/
class WM_MOUSEACTIVATE_WindowMessageCrack : public WindowMessageCrack
{
public:
	HWND wndTopLevel(void){return (HWND)_WindowMessage.wParam;}
	UINT nHitTest(void){return (UINT)LOWORD(_WindowMessage.lParam);}
	UINT message(void){return (UINT)HIWORD(_WindowMessage.lParam);}

public:
	void Result(int rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
// void OnChildActivate()
/*
WM_CHILDACTIVATE
		func(); \
		lResult = 0; \
*/
class WM_CHILDACTIVATE_WindowMessageCrack : public WindowMessageCrack
{
public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnGetMinMaxInfo(LPMINMAXINFO lpMMI)
/*
WM_GETMINMAXINFO
		func((LPMINMAXINFO)lParam); \
		lResult = 0; \
*/
class WM_GETMINMAXINFO_WindowMessageCrack : public WindowMessageCrack
{
public:
	LPMINMAXINFO lpMMI(void){return (LPMINMAXINFO)_WindowMessage.lParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnIconEraseBkgnd(CDCHandle dc)
/*
WM_ICONERASEBKGND
		func((HDC)wParam); \
		lResult = 0; \
*/
class WM_ICONERASEBKGND_WindowMessageCrack : public WindowMessageCrack
{
public:
	HDC hdc(void){return (HDC)_WindowMessage.wParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnSpoolerStatus(UINT nStatus, UINT nJobs)
/*
WM_SPOOLERSTATUS
		func((UINT)wParam, (UINT)LOWORD(lParam)); \
		lResult = 0; \
*/
class WM_SPOOLERSTATUS_WindowMessageCrack : public WindowMessageCrack
{
public:
	UINT nStatus(void) {return (UINT)_WindowMessage.wParam;}
	UINT nJobs(void) {return (UINT)LOWORD(_WindowMessage.lParam);}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
/*
WM_DRAWITEM
		func((UINT)wParam, (LPDRAWITEMSTRUCT)lParam); \
		lResult = TRUE; \
*/
class WM_DRAWITEM_WindowMessageCrack : public WindowMessageCrack
{
public:
	int nIDCtl(void) {return (UINT)_WindowMessage.wParam;}
	LPDRAWITEMSTRUCT lpDrawItemStruct(void) {return (LPDRAWITEMSTRUCT)_WindowMessage.lParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)TRUE;
	}
};

//===========================================================================
// void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct)
/*
WM_MEASUREITEM
		func((UINT)wParam, (LPMEASUREITEMSTRUCT)lParam); \
		lResult = TRUE; \
*/
class WM_MEASUREITEM_WindowMessageCrack : public WindowMessageCrack
{
public:
	int nIDCtl(void) {return (UINT)_WindowMessage.wParam;}
	LPMEASUREITEMSTRUCT lpMeasureItemStruct(void) {return (LPMEASUREITEMSTRUCT)_WindowMessage.lParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)TRUE;
	}
};

//===========================================================================
// void OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct)
/*
WM_DELETEITEM
		func((UINT)wParam, (LPDELETEITEMSTRUCT)lParam); \
		lResult = TRUE; \
*/
class WM_DELETEITEM_WindowMessageCrack : public WindowMessageCrack
{
public:
	int nIDCtl(void) {return (UINT)_WindowMessage.wParam;}
	LPDELETEITEMSTRUCT lpDeleteItemStruct(void) {return (LPDELETEITEMSTRUCT)_WindowMessage.lParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)TRUE;
	}
};

//===========================================================================
//int OnCharToItem(UINT nChar, UINT nIndex, CListBox listBox)
/*
WM_CHARTOITEM
		lResult = (LRESULT)func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), (HWND)lParam); \
*/
class WM_CHARTOITEM_WindowMessageCrack : public WindowMessageCrack
{
public:
	UINT nChar(void) {return (UINT)LOWORD(_WindowMessage.wParam);}
	UINT nIndex(void) {return (UINT)HIWORD(_WindowMessage.wParam);}
	HWND listBox(void) {return (HWND)_WindowMessage.lParam;}

public:
	void Result(int rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
// int OnVKeyToItem(UINT nKey, UINT nIndex, CListBox listBox)
/*
WM_VKEYTOITEM
		lResult = (LRESULT)func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), (HWND)lParam); \
*/
class WM_VKEYTOITEM_WindowMessageCrack : public WindowMessageCrack
{
public:
	UINT nKey(void) {return (UINT)LOWORD(_WindowMessage.wParam);}
	UINT nIndex(void) {return (UINT)HIWORD(_WindowMessage.wParam);}
	HWND listBox(void) {return (HWND)_WindowMessage.lParam;}

public:
	void Result(int rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
// HCURSOR OnQueryDragIcon()
/*
WM_QUERYDRAGICON
		lResult = (LRESULT)func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), (HWND)lParam); \
*/
class WM_QUERYDRAGICON_WindowMessageCrack : public WindowMessageCrack
{
public:
	void Result(HCURSOR rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
// int OnCompareItem(int nIDCtl, LPCOMPAREITEMSTRUCT lpCompareItemStruct)
/*
WM_COMPAREITEM
		lResult = (LRESULT)func((UINT)wParam, (LPCOMPAREITEMSTRUCT)lParam); \
*/
class WM_COMPAREITEM_WindowMessageCrack : public WindowMessageCrack
{
public:
	int nIDCtl(void) {return (UINT)_WindowMessage.wParam;}
	LPCOMPAREITEMSTRUCT lpCompareItemStruct(void) {return (LPCOMPAREITEMSTRUCT)_WindowMessage.lParam;}

public:
	void Result(int rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
// void OnCompacting(UINT nCpuTime)
/*
WM_COMPACTING
		func((UINT)wParam); \
		lResult = 0; \
*/
class WM_COMPACTING_WindowMessageCrack : public WindowMessageCrack
{
public:
	UINT nCpuTime(void){return (UINT)_WindowMessage.wParam;}

public:
	void Result(void)
	{
		_WindowMessage.lResult = (LRESULT)0;
	}
};

//===========================================================================
// BOOL OnNcCreate(LPCREATESTRUCT lpCreateStruct)
/*
WM_NCCREATE
		lResult = (LRESULT)func((LPCREATESTRUCT)lParam);
*/
class WM_NCCREATE_WindowMessageCrack : public WindowMessageCrack
{
public:
	LPCREATESTRUCT lpCreateStruct(void){return (LPCREATESTRUCT)(_WindowMessage.lParam);}

public:
	void Result(BOOL rv)
	{
		_WindowMessage.lResult = (LRESULT)rv;
	}
};

//===========================================================================
// void OnNcDestroy()
/*
WM_NCDESTROY
		func(); \
		lResult = 0; \
*/
using WM_NCDESTROY_WindowMessageCrack = WM_DESTROY_WindowMessageCrack;





//===========================================================================
// void OnCommand(UINT uNotifyCode, int nID, CWindow wndCtl)
/*
WM_COMMAND
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
*/
class WM_COMMAND_WindowMessageCrack : public WindowMessageCrack
{
public:
	UINT uNotifyCode(void){	return (UINT)HIWORD(_WindowMessage.wParam);}
	int nID(void){return (int)LOWORD(_WindowMessage.wParam);}
	HWND wndCtl(void){return (HWND)_WindowMessage.lParam;}

public:
	void Result(LRESULT lv)
	{
		_WindowMessage.lResult = (LRESULT)lv;
	}
};





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
}




