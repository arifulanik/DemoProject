#pragma once


// CFirstDialog dialog

class CFirstDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CFirstDialog)

public:
	CFirstDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFirstDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_First_dialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
