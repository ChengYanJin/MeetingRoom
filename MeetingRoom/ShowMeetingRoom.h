#pragma once
#include "afxcmn.h"


// ShowMeetingRoom �Ի���

class ShowMeetingRoom : public CDialogEx
{
	DECLARE_DYNAMIC(ShowMeetingRoom)

public:
	ShowMeetingRoom(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ShowMeetingRoom();

// �Ի�������
	enum { IDD = IDD_MEETINGROMMINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
};
