// SearchPlan.cpp : 实现文件
//

#include "stdafx.h"
#include "MeetingRoom.h"
#include "SearchPlan.h"
#include "afxdialogex.h"


// SearchPlan 对话框

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


// SearchPlan 消息处理程序


void SearchPlan::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void SearchPlan::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
}


void SearchPlan::OnBnClickedButton1()//点击【查询】按钮，根据日期和房间号，查找使用计划
{
	// TODO:  在此添加控件通知处理程序代码
	CString Date, RoomNo, BeginEndTime, ContactPerson;//保存输入的日期和房间号
	CString DateSearch, RoomNoSearch;
	CFileFind fileFind;//查找文件是否存在
	CString strFileName;
	int k = 0;
	strFileName = _T("res/file/meetingplan.txt");

	if (!fileFind.FindFile(strFileName))
	{
		::MessageBox(NULL, TEXT("读取用户信息文件失败"), NULL, MB_OK);
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

		if (Date == DateSearch && RoomNo == RoomNoSearch)//指定日期和房间号
		{
			m_list.InsertItem(k, NULL);//申请一行来存放数据 K代表已经存放的条数
			m_list.SetItemText(k, 0, RoomNo);//申请后，存放数据
			m_list.SetItemText(k, 1, Date);
			m_list.SetItemText(k, 2, BeginEndTime);
			m_list.SetItemText(k, 3, ContactPerson);
			k++;////////////////////新增！！！
		}

	}
}


BOOL SearchPlan::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD style = m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(style | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_list.InsertColumn(0, _T("房间号码"), LVCFMT_LEFT, 100, -1);//显示表头信息
	m_list.InsertColumn(1, _T("日期"), LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(2, _T("起止日期"), LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(3, _T("联系人姓名"), LVCFMT_LEFT, 100, -1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
