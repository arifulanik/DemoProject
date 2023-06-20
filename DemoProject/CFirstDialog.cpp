// CFirstDialog.cpp : implementation file
//

#include "pch.h"
#include "DemoProject.h"
#include "CFirstDialog.h"
#include "afxdialogex.h"


// CFirstDialog dialog

IMPLEMENT_DYNAMIC(CFirstDialog, CDialogEx)

CFirstDialog::CFirstDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_First_dialog, pParent)
{

}

CFirstDialog::~CFirstDialog()
{
}

void CFirstDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFirstDialog, CDialogEx)
END_MESSAGE_MAP()


// CFirstDialog message handlers
