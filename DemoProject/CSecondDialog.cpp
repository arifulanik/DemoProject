// CSecondDialog.cpp : implementation file
//

#include "pch.h"
#include "DemoProject.h"
#include "CSecondDialog.h"
#include "afxdialogex.h"


// CSecondDialog dialog

IMPLEMENT_DYNAMIC(CSecondDialog, CDialogEx)

CSecondDialog::CSecondDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Second_dialog, pParent)
{

}

CSecondDialog::~CSecondDialog()
{
}

void CSecondDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSecondDialog, CDialogEx)
END_MESSAGE_MAP()


// CSecondDialog message handlers
