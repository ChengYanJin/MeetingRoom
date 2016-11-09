// Insert.cpp : 实现文件
//

#include "stdafx.h"
#include "MeetingRoom.h"
#include "Insert.h"
#include "afxdialogex.h"


// Insert 对话框

IMPLEMENT_DYNAMIC(Insert, CDialogEx)

Insert::Insert(CWnd* pParent /*=NULL*/)
	: CDialogEx(Insert::IDD, pParent)
{

}

Insert::~Insert()
{
}

void Insert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Insert, CDialogEx)
	ON_BN_CLICKED(IDOK, &Insert::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &Insert::OnBnClickedButton1)
END_MESSAGE_MAP()


// Insert 消息处理程序

void Insert::OnBnClickedOk()	//点击返回主界面按钮
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void Insert::OnBnClickedButton1()	//点击确认按钮
{
	// TODO:  在此添加控件通知处理程序代码
	CString RoomNo, Date, BeginEndTime, ContactPerson;

	((CEdit*)this->GetDlgItem(IDC_EDIT1))->GetWindowText(RoomNo);
	((CEdit*)this->GetDlgItem(IDC_EDIT2))->GetWindowText(Date);
	((CEdit*)this->GetDlgItem(IDC_EDIT3))->GetWindowText(BeginEndTime);
	((CEdit*)this->GetDlgItem(IDC_EDIT4))->GetWindowText(ContactPerson);

	CString meetingPlanFileName = _T("res/file/meetingplan.txt");
	CStdioFile myFile;

	CFileException fileException;


	if (myFile.Open(meetingPlanFileName, CFile::typeText | CFile::modeReadWrite))

	{
		myFile.SeekToEnd();
		myFile.WriteString(RoomNo + " " + Date + " " + BeginEndTime + " " + ContactPerson +  "\n");
		MessageBox(TEXT("插入成功！"), NULL, MB_OK);
		GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT3)->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT4)->SetWindowText(_T(""));

	}

	else
	{
		TRACE("Can't open file %s,error=%u\n", meetingPlanFileName, fileException.m_cause);
	}

	myFile.Close();
	
}


BOOL Insert::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
