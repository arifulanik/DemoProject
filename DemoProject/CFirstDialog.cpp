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
map<string, vector<double>>copyMap;
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
CFirstDialog* CFirstDialog::firstDlgPointer = NULL;
BOOL CFirstDialog::OnInitDialog(){
	CDialogEx::OnInitDialog();
	__super::OnInitDialog();
	firstDlgPointer = this;

	//CDemoProjectDlg obj;

	return true;
}

void CFirstDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Box1);
	DDX_Control(pDX, IDC_COMBO2, m_Box2);
}


BEGIN_MESSAGE_MAP(CFirstDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CFirstDialog::ExportData)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CFirstDialog::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CFirstDialog::OnCbnSelchangeCombo2)
END_MESSAGE_MAP()


// CFirstDialog message handlers

void CFirstDialog::AddComboItems(){
	
	CDemoProjectDlg* baseObjectPointer = CDemoProjectDlg::basePointer;
	copyMap = baseObjectPointer->m_csvData;
	map<string, vector<double>>::iterator it = copyMap.begin();
	string test = it->first;
	m_Box1.ResetContent();
	m_Box2.ResetContent();
	for (auto val : copyMap) {
		m_Box1.AddString(CA2T(val.first.c_str()));
		m_Box2.AddString(CA2T(val.first.c_str()));
	}
	
}

void CFirstDialog::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	int xIndex = m_Box1.GetCurSel();
	if (xIndex != CB_ERR)
	{
		m_Box1.GetLBText(xIndex, XVal);
		XFlag = true;
	}
}


void CFirstDialog::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
	int yIndex = m_Box2.GetCurSel();
	if (yIndex != CB_ERR)
	{
		m_Box2.GetLBText(yIndex, YVal);
		YFlag = true;
	}
}
void CFirstDialog::ExportData()
{
	// TODO: Add your control notification handler code here
	if (XFlag && YFlag) {
		vector<double>xvec, yvec;
		string xkey = CT2A(XVal);
		for (auto p : copyMap[xkey]) {
			xvec.push_back(p);
		}

		string ykey = CT2A(YVal);
		for (auto p : copyMap[ykey]) {
			yvec.push_back(p);
		}
		//AfxMessageBox(CA2T(xkey.c_str()));
		// export to csv file

		std::ofstream outputFile("output.csv");
		if (outputFile.is_open())
		{
			// Write the headers
			outputFile << CT2A(XVal) << ","<< CT2A(YVal) << endl;

			// Determine the maximum size of the vectors
			//size_t maxSize = std::max(xvec.size(), yvec.size());

			// Iterate over the vectors
			for (size_t i = 0; i < xvec.size(); i++)
			{
				// Write vector1 value if available
				outputFile << xvec[i];

				outputFile << ",";

				// Write vector2 value if available
				outputFile << yvec[i];

				outputFile << std::endl;
			}

			// Close the file
			outputFile.close();
		}
	}

}
