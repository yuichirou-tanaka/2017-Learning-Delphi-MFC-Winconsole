
// buttonMFCApplication1Dlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "buttonMFCApplication1.h"
#include "buttonMFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


const COLORREF CLOUDBLUE = RGB(128, 184, 223);
const COLORREF WHITE = RGB(255, 255, 255);
const COLORREF BLACK = RGB(1, 1, 1);
const COLORREF DKGRAY = RGB(128, 128, 128);
const COLORREF LTGRAY = RGB(192, 192, 192);
const COLORREF YELLOW = RGB(255, 255, 0);
const COLORREF DKYELLOW = RGB(128, 128, 0);
const COLORREF RED = RGB(255, 0, 0);
const COLORREF DKRED = RGB(128, 0, 0);
const COLORREF BLUE = RGB(0, 0, 255);
const COLORREF DKBLUE = RGB(0, 0, 128);
const COLORREF CYAN = RGB(0, 255, 255);
const COLORREF DKCYAN = RGB(0, 128, 128);
const COLORREF GREEN = RGB(0, 255, 0);
const COLORREF DKGREEN = RGB(0, 128, 0);
const COLORREF MAGENTA = RGB(255, 0, 255);
const COLORREF DKMAGENTA = RGB(128, 0, 128);



// CbuttonMFCApplication1Dlg ダイアログ



CbuttonMFCApplication1Dlg::CbuttonMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CbuttonMFCApplication1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CbuttonMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CbuttonMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CbuttonMFCApplication1Dlg::OnBnClickedButton1)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CbuttonMFCApplication1Dlg メッセージ ハンドラー

BOOL CbuttonMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	m_colorOk.Attach(IDC_BUTTON1, this, RED, WHITE, DKRED);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CbuttonMFCApplication1Dlg::OnPaint()
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
HCURSOR CbuttonMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CbuttonMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	static int id = 0;
	switch (id){
	default: {
		m_colorOk.SetBackGroundColor(CLOUDBLUE);//バックカラー
		m_colorOk.SetFourColor(DKGRAY);//文字の色
		m_colorOk.RedrawWindow();//再描画
	}break;
	case 1:{
		m_colorOk.SetBackGroundColor(BLUE);//バックカラー
		m_colorOk.SetFourColor(RED);//文字の色
		m_colorOk.RedrawWindow();//再描画
		//m_colorOk.Attach(IDC_BUTTON1, this, RED, WHITE, DKRED);
	}break;
	case 2:{
		m_colorOk.SetBackGroundColor(GREEN);//バックカラー
		m_colorOk.SetFourColor(BLACK);//文字の色
		m_colorOk.RedrawWindow();//再描画
	}break;
	case 3:
	{
		m_colorOk.SetBackGroundColor(YELLOW);//バックカラー
		m_colorOk.SetFourColor(WHITE);//文字の色
		m_colorOk.RedrawWindow();//再描画
	}break;
	}
	id++;
	id = (id > 3) ? 0 : id ;
}


HBRUSH CbuttonMFCApplication1Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO: ここで DC の属性を変更してください。
	return hbr;
}
