// CFirstDialog.cpp : implementation file
//

#include "pch.h"
#include "DemoProject.h"
#include "DemoProjectDlg.h"
#include "CFirstDialog.h"
#include "afxdialogex.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
// CFirstDialog dialog

IMPLEMENT_DYNAMIC(CFirstDialog, CDialogEx)

CFirstDialog::CFirstDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_First_dialog, pParent)
{
	//btnFlag = false;
	//test++;

}

CFirstDialog::~CFirstDialog()
{
}

BOOL CFirstDialog::OnInitDialog(){
	CDialogEx::OnInitDialog();

	//int value = CDemoProjectDlg::shared_variable;
    //AddComboItems();
	CDemoProjectDlg obj;
	bool &btnFlag = obj.btnClickFlag;
	if (btnFlag == true)AddComboItems();

	return true;
}

void CFirstDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Box1);
	DDX_Control(pDX, IDC_COMBO2, m_Box2);
}


BEGIN_MESSAGE_MAP(CFirstDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CFirstDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CFirstDialog message handlers

void CFirstDialog::AddComboItems(){
	
	CDemoProjectDlg obj;
	int& value = obj.shared_variable;
	AfxMessageBox(value);


	//map<string, vector<double>>dummy = obj.m_csvData; 
	/*for (auto val : dummy) {
		m_Box1.AddString(CA2T(val.first.c_str()));
		m_Box2.AddString(CA2T(val.first.c_str()));
	}
	/*m_Box1.AddString(L"1");
	m_Box1.AddString(L"2");
	m_Box1.AddString(L"3");
	m_Box1.AddString(L"4");*/
}


void CFirstDialog::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	//map<string, vector<double>>::iterator it = copyMap.begin();
	//CString str = CA2T(it->first.c_str());
	//AfxMessageBox(L"Hello");
	//CDemoProjectDlg obj;
	//map<string, vector<double>>demo = obj.m_csvData;
	
}
