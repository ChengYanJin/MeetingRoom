// ShowMeetingRoom.cpp : 实现文件
//

#include "stdafx.h"
#include "MeetingRoom.h"
#include "ShowMeetingRoom.h"
#include "afxdialogex.h"


// ShowMeetingRoom 对话框

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


// ShowMeetingRoom 消息处理程序


BOOL ShowMeetingRoom::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
