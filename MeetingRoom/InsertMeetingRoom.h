#pragma once


// InsertMeetingRoom �Ի���

class InsertMeetingRoom : public CDialogEx
{
	DECLARE_DYNAMIC(InsertMeetingRoom)

public:
	InsertMeetingRoom(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~InsertMeetingRoom();

// �Ի�������
	enum { IDD = IDD_MeetingRoomInsert };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
