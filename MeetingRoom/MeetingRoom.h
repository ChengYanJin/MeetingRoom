
// MeetingRoom.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMeetingRoomApp: 
// �йش����ʵ�֣������ MeetingRoom.cpp
//

class CMeetingRoomApp : public CWinApp
{
public:
	CMeetingRoomApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMeetingRoomApp theApp;