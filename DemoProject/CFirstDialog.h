#pragma once

#include "DemoProjectDlg.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

// CFirstDialog dialog
using namespace std;

class CFirstDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CFirstDialog)

public:
	virtual BOOL OnInitDialog();
	CFirstDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFirstDialog();


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_First_dialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support


	DECLARE_MESSAGE_MAP()
public:

	CComboBox m_Box1;
	CComboBox m_Box2;
	void AddComboItems();
    //map<string, vector<double>>copyMap;
	//bool& btnFlag;
	afx_msg void OnBnClickedButton1();
	 //int test;
};
