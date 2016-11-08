// MeetingRoomInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MeetingRoom.h"
#include "MeetingRoomInfo.h"
#include "afxdialogex.h"


// MeetingRoomInfo �Ի���

IMPLEMENT_DYNAMIC(MeetingRoomInfo, CDialogEx)

MeetingRoomInfo::MeetingRoomInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(MeetingRoomInfo::IDD, pParent)
{

}

MeetingRoomInfo::~MeetingRoomInfo()
{
}

void MeetingRoomInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(MeetingRoomInfo, CDialogEx)
	ON_BN_CLICKED(IDOK, &MeetingRoomInfo::OnBnClickedOk)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &MeetingRoomInfo::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, &MeetingRoomInfo::OnBnClickedButton1)
END_MESSAGE_MAP()


// MeetingRoomInfo ��Ϣ�������


void MeetingRoomInfo::OnBnClickedOk()//�������������
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


BOOL MeetingRoomInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	DWORD style = m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(style | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
	m_list.InsertColumn(0, _T("�������"), LVCFMT_LEFT, 100, -1);//��ʾ��ͷ��Ϣ
	m_list.InsertColumn(1, _T("����"), LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(2, _T("��ֹ����"), LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(3, _T("��ϵ������"), LVCFMT_LEFT, 100, -1);
	
	CString RoomNo, Date, BeginEndTime, ContactPerson ;   //����һ��CString�������ڱ����ı���ؼ��ڵ��ı�

	CFileFind fileFind;//�����ļ��Ƿ����
	CString strFileName;

	strFileName = _T("res/file/meetingplan.txt");

	if (!fileFind.FindFile(strFileName))
	{
		::MessageBox(NULL, TEXT("��ȡ�û���Ϣ�ļ�ʧ��"), NULL, MB_OK);
	}

	CStdioFile file;
	file.Open(strFileName, CFile::modeRead);

	CString  strTemp;

	int k = 0;//k��¼�Ѿ����ڵ��б�����

	m_list.DeleteAllItems();

	while (file.ReadString(strTemp))//���ж�ȡ
	{
		AfxExtractSubString(RoomNo, strTemp, 0, ' ');
		AfxExtractSubString(Date, strTemp, 1, ' ');
		AfxExtractSubString(BeginEndTime, strTemp, 2, ' ');
		AfxExtractSubString(ContactPerson, strTemp, 3, ' ');

		m_list.InsertItem(k,NULL);//����һ����������� K�����Ѿ���ŵ�����
		m_list.SetItemText(k, 0, RoomNo);//����󣬴������
		m_list.SetItemText(k, 1, Date);
		m_list.SetItemText(k, 2, BeginEndTime);
		m_list.SetItemText(k, 3, ContactPerson);

		k++;
	}
	file.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}



void MeetingRoomInfo::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void MeetingRoomInfo::OnBnClickedButton1()//���ɾ����ǰ��Ϣ
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	POSITION p = m_list.GetFirstSelectedItemPosition();    //��ȡ��ѡ����λ��
	while (p)
	{
		int  nSelected = m_list.GetNextSelectedItem(p); //��ȡѡ���е�����
		m_list.DeleteItem(nSelected); //��������ɾ��
		p = m_list.GetFirstSelectedItemPosition();
	}

}
