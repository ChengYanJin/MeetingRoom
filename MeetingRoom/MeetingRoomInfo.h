#pragma once
#include "afxcmn.h"


// MeetingRoomInfo �Ի���

class MeetingRoomInfo : public CDialogEx
{
	DECLARE_DYNAMIC(MeetingRoomInfo)

public:
	MeetingRoomInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MeetingRoomInfo();

// �Ի�������
	enum { IDD = IDD_INFORMATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CListCtrl m_list;

	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnBnClickedButton1();
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
