#pragma once
#include "afxcmn.h"


// ShowMeetingRoom 对话框

class ShowMeetingRoom : public CDialogEx
{
	DECLARE_DYNAMIC(ShowMeetingRoom)

public:
	ShowMeetingRoom(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ShowMeetingRoom();

// 对话框数据
	enum { IDD = IDD_MEETINGROMMINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
};
