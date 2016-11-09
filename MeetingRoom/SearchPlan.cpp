// SearchPlan.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MeetingRoom.h"
#include "SearchPlan.h"
#include "afxdialogex.h"


// SearchPlan �Ի���

IMPLEMENT_DYNAMIC(SearchPlan, CDialogEx)

SearchPlan::SearchPlan(CWnd* pParent /*=NULL*/)
	: CDialogEx(SearchPlan::IDD, pParent)
{

}

SearchPlan::~SearchPlan()
{
}

void SearchPlan::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(SearchPlan, CDialogEx)
	ON_BN_CLICKED(IDOK, &SearchPlan::OnBnClickedOk)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &SearchPlan::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, &SearchPlan::OnBnClickedButton1)
END_MESSAGE_MAP()


// SearchPlan ��Ϣ�������


void SearchPlan::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void SearchPlan::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void SearchPlan::OnBnClickedButton1()//�������ѯ����ť���������ںͷ���ţ�����ʹ�üƻ�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString Date, RoomNo, BeginEndTime, ContactPerson;//������������ںͷ����
	CString DateSearch, RoomNoSearch;
	CFileFind fileFind;//�����ļ��Ƿ����
	CString strFileName;
	int k = 0;
	strFileName = _T("res/file/meetingplan.txt");

	if (!fileFind.FindFile(strFileName))
	{
		::MessageBox(NULL, TEXT("��ȡ�û���Ϣ�ļ�ʧ��"), NULL, MB_OK);
	}

	CStdioFile file;
	file.Open(strFileName, CFile::modeRead);

	CString strTemp;
	((CEdit*)this->GetDlgItem(IDC_DATE))->GetWindowText(DateSearch);
	((CEdit*)this->GetDlgItem(IDC_RoomNo))->GetWindowText(RoomNoSearch);

	while (file.ReadString(strTemp))
	{
	
		AfxExtractSubString(RoomNo, strTemp, 0, ' ');
		AfxExtractSubString(Date, strTemp, 1, ' ');
		AfxExtractSubString(BeginEndTime, strTemp, 2, ' ');
		AfxExtractSubString(ContactPerson, strTemp, 3, ' ');

		if (Date == DateSearch && RoomNo == RoomNoSearch)//ָ�����ںͷ����
		{
			m_list.InsertItem(k, NULL);//����һ����������� K�����Ѿ���ŵ�����
			m_list.SetItemText(k, 0, RoomNo);//����󣬴������
			m_list.SetItemText(k, 1, Date);
			m_list.SetItemText(k, 2, BeginEndTime);
			m_list.SetItemText(k, 3, ContactPerson);
			k++;////////////////////����������
		}

	}
}


BOOL SearchPlan::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	DWORD style = m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(style | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_list.InsertColumn(0, _T("�������"), LVCFMT_LEFT, 100, -1);//��ʾ��ͷ��Ϣ
	m_list.InsertColumn(1, _T("����"), LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(2, _T("��ֹ����"), LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(3, _T("��ϵ������"), LVCFMT_LEFT, 100, -1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
