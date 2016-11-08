#pragma once


// InsertMeetingRoom 对话框

class InsertMeetingRoom : public CDialogEx
{
	DECLARE_DYNAMIC(InsertMeetingRoom)

public:
	InsertMeetingRoom(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~InsertMeetingRoom();

// 对话框数据
	enum { IDD = IDD_MeetingRoomInsert };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
