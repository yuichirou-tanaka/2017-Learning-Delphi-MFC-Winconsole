
// buttontestMFCApplication1Dlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "buttontestMFCApplication1.h"
#include "buttontestMFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CbuttontestMFCApplication1Dlg ダイアログ

typedef struct _buttonStatusEvent{
	enum buttonstate{
		None,
		Prepare,	// 待機
		Booting,	// 起動中
		BootOk,		// 起動完了
		Unknown,	// 不明
	};

	CButton* button;
	//CMFCButton* button;
	buttonstate state;

	_buttonStatusEvent(CButton* ibutton)
		//_buttonStatusEvent(CMFCButton* ibutton)
		:button(ibutton), state(None)
	{
	}

}buttonStatusEvent;

std::vector<buttonStatusEvent> g_vbuttonStatusEvents;


CbuttontestMFCApplication1Dlg::CbuttontestMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CbuttontestMFCApplication1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CbuttontestMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CbuttontestMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CbuttontestMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CbuttontestMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CbuttontestMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CbuttontestMFCApplication1Dlg::OnBnClickedMfcbutton1)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CbuttontestMFCApplication1Dlg メッセージ ハンドラー

BOOL CbuttontestMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。


	g_vbuttonStatusEvents.clear();
	CMFCButton* t_CMFCButton = (CMFCButton*)GetDlgItem(IDC_MFCBUTTON1);
	g_vbuttonStatusEvents.push_back(buttonStatusEvent(t_CMFCButton));

	//COLORREF CLOUDBLUE;

	//m_btn1.SetBackGroundColor(CLOUDBLUE);
	//m_btn1.ShowWindow(1);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CbuttontestMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CbuttontestMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CbuttontestMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	CButton* btn = (CButton*)GetDlgItem(IDC_BUTTON1);
	btn->EnableWindow(FALSE);
	btn = (CButton*)GetDlgItem(IDC_MFCBUTTON1);
	btn->EnableWindow(FALSE);
}


void CbuttontestMFCApplication1Dlg::OnBnClickedButton3()
{
	CButton* btn = (CButton*)GetDlgItem(IDC_BUTTON1);
	btn->EnableWindow(TRUE);
	btn = (CButton*)GetDlgItem(IDC_MFCBUTTON1);
	btn->EnableWindow(TRUE);

}


void CbuttontestMFCApplication1Dlg::OnBnClickedButton1()
{
	//CDC* pDC = btn->GetDC();
	//pDC->SetBkColor(RGB(0, 255, 0));

	//CWnd *edit = (CWnd*)GetDlgItem(IDC_BUTTON1);
	//edit->Invalidate();


	g_vbuttonStatusEvents.clear();
	CMFCButton* t_CMFCButton = (CMFCButton*)GetDlgItem(IDC_MFCBUTTON1);
	g_vbuttonStatusEvents.push_back(buttonStatusEvent(t_CMFCButton));

}





void CbuttontestMFCApplication1Dlg::OnBnClickedMfcbutton1()
{
	CMFCButton* btn = static_cast<CMFCButton*>(g_vbuttonStatusEvents[0].button);// (CMFCButton*)GetDlgItem(IDC_MFCBUTTON1);
	btn->SetFaceColor(RGB(255, 0, 0), true);
	btn->SetTextColor(RGB(128, 0, 125));
	//btn->SetTooltip(_T("test"));

}


HBRUSH CbuttontestMFCApplication1Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO: ここで DC の属性を変更してください。

	// TODO: 既定値を使用したくない場合は別のブラシを返します。
	//if (pWnd->GetDlgCtrlID() == IDC_BUTTON1)
	//{
	//	pDC->SetBkColor(RGB(0, 255, 0));
	//	//hbr = m_brBack;
	//}
	//if (pWnd->GetDlgCtrlID() == IDC_MFCBUTTON1)
	//{
	//	pDC->SetBkColor(RGB(0, 255, 0));
	//	//hbr = m_brBack;
	//}
	return hbr;
}
