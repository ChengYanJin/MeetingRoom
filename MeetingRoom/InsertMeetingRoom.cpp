// InsertMeetingRoom.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MeetingRoom.h"
#include "InsertMeetingRoom.h"
#include "afxdialogex.h"


// InsertMeetingRoom �Ի���

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


// InsertMeetingRoom ��Ϣ�������


void InsertMeetingRoom::OnBnClickedButton1()//���ȷ������
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(TEXT("����ɹ���"), NULL, MB_OK);
		GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	
	}

	else
	{
		TRACE("Can't open file %s,error=%u\n", meetingPlanFileName, fileException.m_cause);
	}

	myFile.Close();

}


void InsertMeetingRoom::OnBnClickedOk()//����������˵�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
