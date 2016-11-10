#pragma once
#include "afxcmn.h"


// MeetingRoomInfo 对话框

class MeetingRoomInfo : public CDialogEx
{
	DECLARE_DYNAMIC(MeetingRoomInfo)

public:
	MeetingRoomInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MeetingRoomInfo();

// 对话框数据
	enum { IDD = IDD_INFORMATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CListCtrl m_list;

	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnBnClickedButton1();
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
