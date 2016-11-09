// Insert.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MeetingRoom.h"
#include "Insert.h"
#include "afxdialogex.h"


// Insert �Ի���

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


// Insert ��Ϣ�������

void Insert::OnBnClickedOk()	//������������水ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void Insert::OnBnClickedButton1()	//���ȷ�ϰ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(TEXT("����ɹ���"), NULL, MB_OK);
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
