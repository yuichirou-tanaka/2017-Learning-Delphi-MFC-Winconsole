
// TabtestMFCApplication1Dlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "TabtestMFCApplication1.h"
#include "TabtestMFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTabtestMFCApplication1Dlg ダイアログ



CTabtestMFCApplication1Dlg::CTabtestMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabtestMFCApplication1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTabtestMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_xcTab);
}

BEGIN_MESSAGE_MAP(CTabtestMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CTabtestMFCApplication1Dlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON1, &CTabtestMFCApplication1Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTabtestMFCApplication1Dlg メッセージ ハンドラー

BOOL CTabtestMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	SetDlgItemText(IDC_STATIC, L"Page1");
	m_xcTab.InsertItem(0, L"P1");
	m_xcTab.InsertItem(1, L"P2");
	m_xcTab.InsertItem(3, L"P3");

	{
		m_TabDialog1.Create(, m_TabDialog1.GetActiveWindow());

	}


	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CTabtestMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CTabtestMFCApplication1Dlg::OnPaint()
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
HCURSOR CTabtestMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTabtestMFCApplication1Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	
	switch (m_xcTab.GetCurSel()){
	case 0:
		SetDlgItemText(IDC_STATIC, L"Page1");
		break;
	case 1:
		SetDlgItemText(IDC_STATIC, L"Page2");
		break;
	case 2:
		SetDlgItemText(IDC_STATIC, L"Page3");
		break;
	}
	*pResult = 0;

}


void CTabtestMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}
