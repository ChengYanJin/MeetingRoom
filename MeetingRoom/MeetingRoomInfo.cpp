// MeetingRoomInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "MeetingRoom.h"
#include "MeetingRoomInfo.h"
#include "afxdialogex.h"


// MeetingRoomInfo 对话框

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


// MeetingRoomInfo 消息处理程序


void MeetingRoomInfo::OnBnClickedOk()//点击返回主界面
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


BOOL MeetingRoomInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD style = m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(style | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
	m_list.InsertColumn(0, _T("房间号码"), LVCFMT_LEFT, 100, -1);//显示表头信息
	m_list.InsertColumn(1, _T("日期"), LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(2, _T("起止日期"), LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(3, _T("联系人姓名"), LVCFMT_LEFT, 100, -1);
	
	CString RoomNo, Date, BeginEndTime, ContactPerson ;   //定义一个CString对象，用于保存文本框控件内的文本

	CFileFind fileFind;//查找文件是否存在
	CString strFileName;

	strFileName = _T("res/file/meetingplan.txt");

	if (!fileFind.FindFile(strFileName))
	{
		::MessageBox(NULL, TEXT("读取用户信息文件失败"), NULL, MB_OK);
	}

	CStdioFile file;
	file.Open(strFileName, CFile::modeRead);

	CString  strTemp;

	int k = 0;//k记录已经存在的列表条数

	m_list.DeleteAllItems();

	while (file.ReadString(strTemp))//整行读取
	{
		AfxExtractSubString(RoomNo, strTemp, 0, ' ');
		AfxExtractSubString(Date, strTemp, 1, ' ');
		AfxExtractSubString(BeginEndTime, strTemp, 2, ' ');
		AfxExtractSubString(ContactPerson, strTemp, 3, ' ');

		m_list.InsertItem(k,NULL);//申请一行来存放数据 K代表已经存放的条数
		m_list.SetItemText(k, 0, RoomNo);//申请后，存放数据
		m_list.SetItemText(k, 1, Date);
		m_list.SetItemText(k, 2, BeginEndTime);
		m_list.SetItemText(k, 3, ContactPerson);

		k++;
	}
	file.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}



void MeetingRoomInfo::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
}


void MeetingRoomInfo::OnBnClickedButton1()//点击删除当前信息
{
	// TODO:  在此添加控件通知处理程序代码
	POSITION p = m_list.GetFirstSelectedItemPosition();    //获取首选中行位置
	while (p)
	{
		int  nSelected = m_list.GetNextSelectedItem(p); //获取选中行的索引
		m_list.DeleteItem(nSelected); //根据索引删除
		p = m_list.GetFirstSelectedItemPosition();
	}

}
