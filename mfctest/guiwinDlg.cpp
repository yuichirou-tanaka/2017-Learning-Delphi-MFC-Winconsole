
// guiwinDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "guiwin.h"
#include "guiwinDlg.h"
#include "guiwinDlg2.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CguiwinDlg �_�C�A���O



CguiwinDlg::CguiwinDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CguiwinDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CguiwinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CguiwinDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CguiwinDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CguiwinDlg ���b�Z�[�W �n���h���[

BOOL CguiwinDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CguiwinDlg::OnPaint()
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
HCURSOR CguiwinDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CguiwinDlg::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	guiwinDlg2 dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �_�C�A���O�� <OK> �ŏ����ꂽ���̃R�[�h��
		//  �L�q���Ă��������B
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �_�C�A���O�� <�L�����Z��> �ŏ����ꂽ���̃R�[�h��
		//  �L�q���Ă��������B
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "�x��: �_�C�A���O�̍쐬�Ɏ��s���܂����B�A�v���P�[�V�����͗\�������ɏI�����܂��B\n");
		TRACE(traceAppMsg, 0, "�x��: �_�C�A���O�� MFC �R���g���[�����g�p���Ă���ꍇ�A#define _AFX_NO_MFC_CONTROLS_IN_DIALOGS ���w��ł��܂���B\n");
	}
}


void CguiwinDlg::OnBnClickedButton3()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}
