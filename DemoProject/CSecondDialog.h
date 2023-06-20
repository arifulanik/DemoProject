#pragma once


// CSecondDialog dialog

class CSecondDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSecondDialog)

public:
	CSecondDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSecondDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Second_dialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
