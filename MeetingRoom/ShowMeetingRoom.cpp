// ShowMeetingRoom.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MeetingRoom.h"
#include "ShowMeetingRoom.h"
#include "afxdialogex.h"


// ShowMeetingRoom �Ի���

IMPLEMENT_DYNAMIC(ShowMeetingRoom, CDialogEx)

ShowMeetingRoom::ShowMeetingRoom(CWnd* pParent /*=NULL*/)
	: CDialogEx(ShowMeetingRoom::IDD, pParent)
{

}

ShowMeetingRoom::~ShowMeetingRoom()
{
}

void ShowMeetingRoom::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(ShowMeetingRoom, CDialogEx)
END_MESSAGE_MAP()


// ShowMeetingRoom ��Ϣ�������


BOOL ShowMeetingRoom::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
