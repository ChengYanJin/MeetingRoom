#pragma once
#include "afxcmn.h"


// SearchPlan �Ի���

class SearchPlan : public CDialogEx
{
	DECLARE_DYNAMIC(SearchPlan)

public:
	SearchPlan(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SearchPlan();

// �Ի�������
	enum { IDD = IDD_SEARCHPLAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
};
