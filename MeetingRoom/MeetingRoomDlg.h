
// MeetingRoomDlg.h : ͷ�ļ�
//
#include"Insert.h"
#pragma once


// CMeetingRoomDlg �Ի���
class CMeetingRoomDlg : public CDialogEx
{
// ����
public:
	CMeetingRoomDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MEETINGROOM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMenu m_Menu;
	afx_msg void OnInsertmeetingplan();
};
