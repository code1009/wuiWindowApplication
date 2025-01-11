#pragma once

/////////////////////////////////////////////////////////////////////////////
//
// File: wui.hpp
//
// Created by Eui-kwon, MOON.(code1009@naver.com)
// Created on Jan-11th, 2025.
//
// - wui(Window User Interface) 라이브러리
// - version 0.2.0.0
// 
/////////////////////////////////////////////////////////////////////////////
//===========================================================================





/////////////////////////////////////////////////////////////////////////////
//===========================================================================
// # HINSTANCE
#include "AppModule.hpp"

// # MessageLoop
//   - GetMessage()
#include "WindowMessageLoop.hpp"

// # Window
#include "WindowClass.hpp"
#include "WindowProc.hpp"
#include "Window.hpp"

//#  Window 확장
#include "WindowStyle.hpp"
#include "BaseWindow.hpp"

// # Window 메시지
// WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
#include "WindowMessage.hpp"

// # Window 메시지 맵
#include "WindowMessageHandler.hpp"
#include "WindowMessageMap.hpp"
#include "MessageMapWindow.hpp"

// # WPARAM, LPARAM 추출, LRESULT 반환
#include "WindowMessageCrack.hpp"

// # Window 함수들
#include "WindowFunction.hpp"

// # 좌표
#include "Coord.hpp"

// # DeviceContext
#include "DC.hpp"
#include "DCFunction.hpp"

// # GDI 객체
#include "GDIObject.hpp"

// # .rc 파일 리소스
#include "ResFunction.hpp"
