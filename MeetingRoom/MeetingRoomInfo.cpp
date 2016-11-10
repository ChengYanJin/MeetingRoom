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
//	ON_BN_CLICKED(IDC_BUTTON1, &MeetingRoomInfo::OnBnClickedButton1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &MeetingRoomInfo::OnClickList1)
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


void MeetingRoomInfo::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)//填选修改后的信息并在list中点击，点击后消息响应函数
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	POSITION ps;
	CString str;
	int nIndex, i;

	ps = m_list.GetFirstSelectedItemPosition();
	nIndex = m_list.GetNextSelectedItem(ps);
	m_list.SetItemState(nIndex, LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);

	str = m_list.GetItemText(nIndex, 0) + ' ';//str获得当前所选行的信息
	for (i = 1; i < 3; i++){
		str = str + m_list.GetItemText(nIndex, i) + ' ';
	}
	str = str + m_list.GetItemText(nIndex, 3);

	try{
		CString strFileName;//在meetingplan.txt中查找当前所选行信息
		CString strTemp;
		CString mRoomNo, mDate, mBeginEndTime, mContact;

		strFileName = _T("res/file/meetingplan.txt");

		((CEdit*)this->GetDlgItem(IDC_EDIT1))->GetWindowText(mRoomNo);
		((CEdit*)this->GetDlgItem(IDC_EDIT2))->GetWindowText(mDate);
		((CEdit*)this->GetDlgItem(IDC_EDIT3))->GetWindowText(mBeginEndTime);
		((CEdit*)this->GetDlgItem(IDC_EDIT4))->GetWindowText(mContact);
		CString modifystr = mRoomNo + " " + mDate + " " + mBeginEndTime + " " + mContact + '\n';
		CStdioFile file;

		file.Open(strFileName, CFile::typeText | CFile::modeReadWrite);
		DWORD dwPos = 0;

		while (file.ReadString(strTemp)){
			if (strTemp == str){//在文档中找到当前数据
				dwPos = (DWORD)file.GetPosition() - (_tcslen(str) + _tcslen(_T("\r\n")));
				break;
			}
		}

		file.Close();
		file.Open(strFileName, CFile::modeWrite);
		file.Seek(dwPos, CFile::begin);
		file.WriteString(modifystr);
		file.Close();
	}//try

	catch (CException* e)
	{
		e->ReportError();
		e->Delete();
	}

	MessageBox(TEXT("修改会议室计划成功！"), NULL, MB_OK);
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT3)->SetWindowText(_T(""));
	GetDlgItem(IDC_EDIT4)->SetWindowText(_T(""));

	*pResult = 0;

}
