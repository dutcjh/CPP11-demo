
// Shuduko.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CShudukoApp: 
// �йش����ʵ�֣������ Shuduko.cpp
//

class CShudukoApp : public CWinApp
{
public:
	CShudukoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CShudukoApp theApp;