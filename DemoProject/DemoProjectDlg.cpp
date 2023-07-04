
// DemoProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DemoProject.h"
#include "DemoProjectDlg.h"
#include "afxdialogex.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
vector<pair<string, string>>fileLine;
//map<string, vector<double>>m_csvData;
map<string, vector<double>>::iterator it;
//map<string, vector<double>>m_csvData;

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
	TreeSoft = new CTreeCtrl;
}

void CDemoProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDD_DEMOPROJECT_DIALOG, m_Tab);
	DDX_Control(pDX, IDC_LoadCSV_Btn, m_btnLoadCSV);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CDemoProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDD_DEMOPROJECT_DIALOG, &CDemoProjectDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_LoadCSV_Btn, &CDemoProjectDlg::OnBnClickedLoadCSV)
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
	// -----------tree control start
	TreeSoft->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP |
		TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT |
		TVS_SINGLEEXPAND | TVS_SHOWSELALWAYS |
		TVS_TRACKSELECT,
		CRect(60, 150, 215, 350), this, 0x1221);
	// -----------tree control end---------------
	// -----------tab contorl start--------------
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

	// -----------list control code----------

	// -----------list contorl end--------------
	shared_variable = 500;
	//testStatic = 50;

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
	m_pwndShow = NULL;
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
	default:
		m_First.ShowWindow(SW_SHOW);
		m_Second.ShowWindow(SW_HIDE);
		m_pwndShow = &m_First;
		break;
	}
	*pResult = 0;
}

void CDemoProjectDlg::OnBnClickedLoadCSV()
{
	// TODO: Add your control notification handler code here
	TreeSoft->DeleteAllItems();
	m_ListCtrl.DeleteAllItems();
	CFileDialog dlg(TRUE, _T(".csv"), NULL, OFN_FILEMUSTEXIST, _T("CSV Files (*.csv)|*.csv||"), this);
	if (dlg.DoModal() == IDOK)
	{
		CString filePath = dlg.GetPathName();
	    LoadCSVFile(filePath);// csv file is loaded here
		btnClickFlag = true;
		
		//objFirst.copyMap = m_csvData;
		//m_editCSVData.SetWindowText(csvData);
	}
	shared_variable = 500;
}

void CDemoProjectDlg::LoadCSVFile(const CString& filePath)
{
	// read the header
	ifstream file(filePath);
	string header;
	m_csvData.clear();
	DeleteListControl(m_ListCtrl);
    if (std::getline(file, header))
	{
		// Parse the header line
		istringstream headerStream(header);
		string columnName;
		int i = 0;
		while (std::getline(headerStream, columnName, ','))
		{
			// Insert the column name as the key in the map
			//vector<double> tmp;
			m_csvData[columnName];
			m_ListCtrl.InsertColumn(i, CA2T(columnName.c_str()), LVCFMT_LEFT, 150);//inserting list headings
			i++;
		}
	}
	string line;
	int rowNo = 0,item;
	vector<vector<string>>values;
	while (getline(file, line))
	{
		istringstream lineStream(line);
		string value;
		//size_t columnIndex = 0;
	    it = m_csvData.begin();
		//test = 100;
		int colNo = 0;
		bool flag = false;
		vector<string>vec;

		while (std::getline(lineStream, value, ','))
		{
			// Add the value to the corresponding column vector in the map
			it->second.push_back(stod(value));
			vec.push_back(value);
			//if (flag == false){
			//	flag = true;
			//	item = m_ListCtrl.InsertItem(colNo, CA2T(value.c_str()));
			//}
			//else
			//{
			//	vec.push_back(value);
			//	m_ListCtrl.SetItemText(item, colNo, CA2T(value.c_str()));//adding list item
			//}
			it++; colNo++;
			
		}
		values.push_back(vec);
		//rowNo++;
	}

	//int item;
	for (int row=values.size()-1; row>=0; row--) {
		bool flag = FALSE;
		int colNo = 0;
		for (int col = 0; col < values[row].size(); col++) {
			string val = values[row][col];
			if (flag == FALSE) {
				item = m_ListCtrl.InsertItem(colNo, CA2T(val.c_str()));
				flag = TRUE;
			}
			else m_ListCtrl.SetItemText(item, colNo, CA2T(val.c_str()));
			colNo++;
		}
	}
	
	file.close();
	showTree();
	//showList();
}

void CDemoProjectDlg::showTree() {
	/*TreeSoft->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP |
		TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT |
		TVS_SINGLEEXPAND | TVS_SHOWSELALWAYS |
		TVS_TRACKSELECT,
		CRect(60, 150, 215, 350), this, 0x1221);*/
	//if (TreeSoft != NULL) {
	//	TreeSoft->DeleteAllItems();
	//	//CleanTreeControl();
	//}
	
	HTREEITEM root;// , levelOne, levelTwo;
	root = TreeSoft->InsertItem(L"Used Variables", TVI_ROOT);
	for (auto header : m_csvData){
		TreeSoft->InsertItem(CA2T(header.first.c_str()), root);
	}
}

void CDemoProjectDlg:: DeleteListControl(CListCtrl& listCtrl) {
	// Get the number of columns in the list control.
	int nColumnCount = listCtrl.GetHeaderCtrl()->GetItemCount();

	// Delete all of the columns.
	for (int i = 0; i < nColumnCount; i++) {
		listCtrl.DeleteColumn(0);
	}

	// Delete all of the items in the list control.
	listCtrl.DeleteAllItems();
}
