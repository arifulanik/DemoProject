
// DemoProjectDlg.h : header file
//

#pragma once
#include "CFirstDialog.h"
#include "CSecondDialog.h"


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
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	CTabCtrl m_Tab;
	CFirstDialog m_First;
	CSecondDialog m_Second;
	CWnd* m_pwndShow;
	CListCtrl m_listCtrl;
	CButton m_btnLoadCSV;
	afx_msg void OnBnClickedLoadcsvBtn();
};
