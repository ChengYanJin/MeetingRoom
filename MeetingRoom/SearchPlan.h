#pragma once
#include "afxcmn.h"


// SearchPlan 对话框

class SearchPlan : public CDialogEx
{
	DECLARE_DYNAMIC(SearchPlan)

public:
	SearchPlan(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SearchPlan();

// 对话框数据
	enum { IDD = IDD_SEARCHPLAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
};
