
// buttontestMFCApplication1Dlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "buttontestMFCApplication1.h"
#include "buttontestMFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CbuttontestMFCApplication1Dlg �_�C�A���O

typedef struct _buttonStatusEvent{
	enum buttonstate{
		None,
		Prepare,	// �ҋ@
		Booting,	// �N����
		BootOk,		// �N������
		Unknown,	// �s��
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


// CbuttontestMFCApplication1Dlg ���b�Z�[�W �n���h���[

BOOL CbuttontestMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B


	g_vbuttonStatusEvents.clear();
	CMFCButton* t_CMFCButton = (CMFCButton*)GetDlgItem(IDC_MFCBUTTON1);
	g_vbuttonStatusEvents.push_back(buttonStatusEvent(t_CMFCButton));

	//COLORREF CLOUDBLUE;

	//m_btn1.SetBackGroundColor(CLOUDBLUE);
	//m_btn1.ShowWindow(1);

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CbuttontestMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
HCURSOR CbuttontestMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CbuttontestMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

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

	// TODO: ������ DC �̑�����ύX���Ă��������B

	// TODO: ����l���g�p�������Ȃ��ꍇ�͕ʂ̃u���V��Ԃ��܂��B
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
