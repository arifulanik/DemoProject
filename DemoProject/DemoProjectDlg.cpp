
// DemoProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DemoProject.h"
#include "DemoProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDemoProjectDlg dialog



CDemoProjectDlg::CDemoProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEMOPROJECT_DIALOG, pParent)
	, m_pwndShow(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDD_DEMOPROJECT_DIALOG, m_Tab);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
	DDX_Control(pDX, IDC_LoadCSV_Btn, m_btnLoadCSV);
}

BEGIN_MESSAGE_MAP(CDemoProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDD_DEMOPROJECT_DIALOG, &CDemoProjectDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_LoadCSV_Btn, &CDemoProjectDlg::OnBnClickedLoadcsvBtn)
END_MESSAGE_MAP()


// CDemoProjectDlg message handlers

BOOL CDemoProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CString strTmp = L"";
	for (int i = 1; i <= 2; ++i) {
		strTmp.Format(L"%dth Tab", i);
		m_Tab.InsertItem(i, strTmp);
	}
	CRect rect;
	m_Tab.GetClientRect(&rect);

	m_Second.Create(IDD_Second_dialog, &m_Tab);
	m_Second.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_SHOWWINDOW | SWP_NOZORDER);

	m_First.Create(IDD_First_dialog, &m_Tab);
	m_First.SetWindowPos(NULL, 5, 25, rect.Width() - 10, rect.Height() - 30, SWP_SHOWWINDOW | SWP_NOZORDER);
	m_pwndShow = &m_Second;

	// list control code
	m_listCtrl.InsertColumn(
		0,              // Rank/order of item 
		L"ID",          // Caption for this header 
		LVCFMT_LEFT,    // Relative position of items under header 
		100);           // Width of items under header

	m_listCtrl.InsertColumn(1, L"Name", LVCFMT_CENTER, 80);
	m_listCtrl.InsertColumn(2, L"Age", LVCFMT_LEFT, 100);
	m_listCtrl.InsertColumn(3, L"Address", LVCFMT_LEFT, 80);

	int nItem;

	nItem = m_listCtrl.InsertItem(0, L"1");
	m_listCtrl.SetItemText(nItem, 1, L"Mark");
	m_listCtrl.SetItemText(nItem, 2, L"45");
	m_listCtrl.SetItemText(nItem, 3, L"Address 1");

	nItem = m_listCtrl.InsertItem(0, L"2");
	m_listCtrl.SetItemText(nItem, 1, L"Allan");
	m_listCtrl.SetItemText(nItem, 2, L"29");
	m_listCtrl.SetItemText(nItem, 3, L"Address 2");
	/*m_listCtrl.InsertItem(1, L"Name");
	m_listCtrl.InsertItem(7, L"2nd item");
	m_listCtrl.InsertItem(2, L"3nd item");
	m_listCtrl.InsertItem(3, L"4nd item");
	m_listCtrl.InsertItem(4, L"5nd item");
	m_listCtrl.InsertItem(5, L"6nd item");
	m_listCtrl.InsertItem(6, L"7nd item");
	m_listCtrl.InsertItem(8, L"8nd item");
	m_listCtrl.InsertItem(9, L"9nd item");*/



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDemoProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDemoProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDemoProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDemoProjectDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	//m_pwndShow = NULL;
	if (m_pwndShow != NULL) {
		m_pwndShow->ShowWindow(SW_HIDE);
		m_pwndShow = NULL;
	}
	int nIndex = m_Tab.GetCurSel();
	switch (nIndex) {
	case 0:
		m_First.ShowWindow(SW_SHOW);
		m_Second.ShowWindow(SW_HIDE);
		m_pwndShow = &m_First;
		break;
	case 1:
		m_Second.ShowWindow(SW_SHOW);
		m_First.ShowWindow(SW_HIDE);
		m_pwndShow = &m_Second;
		break;
	
	}
	*pResult = 0;
}


void CDemoProjectDlg::OnBnClickedLoadcsvBtn()
{
	// TODO: Add your control notification handler code here
}
