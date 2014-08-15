// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"

#include <dwmapi.h>
#pragma comment(lib,"dwmapi.lib")

CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
	m_bLayoutInited=FALSE;
} 

CMainDlg::~CMainDlg()
{
}

int CMainDlg::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	// 		MARGINS mar = {5,5,30,5};
	// 		DwmExtendFrameIntoClientArea ( m_hWnd, &mar );
	SetMsgHandled(FALSE);
	return 0;
}

void CMainDlg::OnShowWindow( BOOL bShow, UINT nStatus )
{
	if(bShow)
	{
 		AnimateHostWindow(200,AW_CENTER);
	}
}


BOOL CMainDlg::OnInitDialog( HWND hWnd, LPARAM lParam )
{
    m_bLayoutInited=TRUE;
    SFlashCtrl * pFlash = FindChildByName2<SFlashCtrl>(L"flash_bkgnd");
    if(pFlash)
    {
        wchar_t szCurDir[MAX_PATH+1];
        GetCurrentDirectoryW(MAX_PATH,szCurDir);
        wcscat(szCurDir,L"\\flash\\morning.swf");
        pFlash->Play(szCurDir);
    }
    return 0;
}

