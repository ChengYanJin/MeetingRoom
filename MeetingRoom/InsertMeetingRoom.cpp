// InsertMeetingRoom.cpp : 实现文件
//

#include "stdafx.h"
#include "MeetingRoom.h"
#include "InsertMeetingRoom.h"
#include "afxdialogex.h"


// InsertMeetingRoom 对话框

IMPLEMENT_DYNAMIC(InsertMeetingRoom, CDialogEx)

InsertMeetingRoom::InsertMeetingRoom(CWnd* pParent /*=NULL*/)
	: CDialogEx(InsertMeetingRoom::IDD, pParent)
{

}

InsertMeetingRoom::~InsertMeetingRoom()
{
}

void InsertMeetingRoom::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(InsertMeetingRoom, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &InsertMeetingRoom::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &InsertMeetingRoom::OnBnClickedOk)
END_MESSAGE_MAP()


// InsertMeetingRoom 消息处理程序


void InsertMeetingRoom::OnBnClickedButton1()//点击确认输入
{
	// TODO:  在此添加控件通知处理程序代码
	CString RoomNo, numPeople;

	((CEdit*)this->GetDlgItem(IDC_EDIT1))->GetWindowText(RoomNo);
	((CEdit*)this->GetDlgItem(IDC_EDIT2))->GetWindowText(numPeople);
	
	CString meetingPlanFileName = _T("res/file/meetingRoom.txt");
	CStdioFile myFile;

	CFileException fileException;


	if (myFile.Open(meetingPlanFileName, CFile::typeText | CFile::modeReadWrite))

	{
		myFile.SeekToEnd();
		myFile.WriteString(RoomNo + " " + numPeople +  "\n");
		MessageBox(TEXT("插入成功！"), NULL, MB_OK);
		GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	
	}

	else
	{
		TRACE("Can't open file %s,error=%u\n", meetingPlanFileName, fileException.m_cause);
	}

	myFile.Close();

}


void InsertMeetingRoom::OnBnClickedOk()//点击返回主菜单
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
