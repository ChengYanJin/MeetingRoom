
// MeetingRoomDlg.h : 头文件
//
#include"Insert.h"
#include"InsertMeetingRoom.h"
#include"MeetingRoomInfo.h"
#include"SearchPlan.h"
#pragma once


// CMeetingRoomDlg 对话框
class CMeetingRoomDlg : public CDialogEx
{
// 构造
public:
	CMeetingRoomDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MEETINGROOM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMenu m_Menu;
	afx_msg void OnInsertmeetingplan();
	afx_msg void OnMeetingRoomInsert();
	afx_msg void OnMeetingRoomInfo();
	afx_msg void OnSearchmeetingplan();
};
