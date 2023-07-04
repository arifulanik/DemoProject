
// DemoProjectDlg.h : header file
//

#pragma once
#include "CFirstDialog.h"
#include "CSecondDialog.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
// CDemoProjectDlg dialog
class CDemoProjectDlg : public CDialogEx
{
// Construction
public:
	CDemoProjectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEMOPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//afx_msg BOOL OnInitDialog();
	friend class CFirstDialog;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	CTabCtrl m_Tab;
	CFirstDialog m_First;
	CSecondDialog m_Second;
	CWnd* m_pwndShow;
	//tree control variable
	CTreeCtrl* TreeSoft;
	CButton m_btnLoadCSV;
	CEdit m_editCSVData;
	void LoadCSVFile(const CString& filePath);
	afx_msg void OnBnClickedLoadCSV();
	void showTree();

	CListCtrl m_ListCtrl;
	void CDemoProjectDlg::DeleteListControl(CListCtrl& listCtr);
	map<string, vector<double>>m_csvData;
	//vector<pair<string, string>>fileLine;
public:
	  
	 //map<string, vector<double>>::iterator it;
	   int shared_variable=100;
	   //static int testStatic;
	   bool btnClickFlag = false;
	  
	
	
};
