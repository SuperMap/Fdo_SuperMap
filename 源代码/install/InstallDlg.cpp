// InstallDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Install.h"
#include "InstallDlg.h"
#include "FileUtil.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// opcode
enum {REGDLL_INSTALL = 0x000C5ED9, REGDLL_UNINSTALL};

//using namespace ATL;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	// 生成的消息映射函数
	virtual BOOL OnInitDialog() 
	{ 
		UpdateData(0); 
		int i;
		CWordArray aLanguageIDs;
		theApp.m_lsetup.GetLanguages(aLanguageIDs);
		for (i = 0; i < aLanguageIDs.GetSize(); i++)
		{
			TCHAR szLang[128];
			int ret = GetLocaleInfo(aLanguageIDs[i], LOCALE_SLANGUAGE, szLang, _COUNTOF(szLang));

			if (ret== 0 && aLanguageIDs[i] == MAKELANGID(LANG_ENGLISH, SUBLANG_DEFAULT) )
				_tcscpy(szLang, _T("English") );

			if (!_tcscmp(szLang, _T("中文(台湾)")))
				_tcscpy(szLang, _T("中文(繁体)"));

			if (!_tcscmp(szLang, _T("Chinese (Taiwan)")))
				_tcscpy(szLang, _T("Chinese (Tradition)"));

			m_language.SetItemData(m_language.AddString(szLang), aLanguageIDs[i]);
		}

		for(i = 0; i < m_language.GetCount(); i++)
		{
			if(m_language.GetItemData(i) == theApp.m_wdCurrentLocaleID)
				m_language.SetCurSel(i);
		}

		theApp.m_lsetup.SetLanguageID(theApp.m_wdCurrentLocaleID);
		theApp.m_lsetup.SetLanguage();
		Localize();

		return TRUE;
	}
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg void OnSelchangeLangs();

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	void Localize(void);
public:
	CComboBox	m_language;
	CString m_EdtBox;
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
, m_EdtBox(_T(""))
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_BOX, m_EdtBox);
	DDX_Control(pDX, IDC_LANGS, m_language);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_LANGS, OnSelchangeLangs)
END_MESSAGE_MAP()

void CAboutDlg::OnSelchangeLangs() 
{
	// TODO: Add your control notification handler code here
	LANGID byNewLang =  (LANGID)m_language.GetItemData(m_language.GetCurSel());
	if (theApp.m_lsetup.GetLanguageID() != byNewLang)
	{
		if	(!theApp.m_lsetup.IsLanguageSupported(byNewLang, false))
		{
			MessageBox(_T("不支持该语言。"), GetResString(IDS_INSTALL_TITLE),
			MB_OK | MB_ICONEXCLAMATION);
		}
		else
		{
			theApp.m_lsetup.SetLanguageID(byNewLang);
			theApp.m_lsetup.SetLanguage();
			theApp.m_wdCurrentLocaleID = byNewLang;
			Localize();
		}
	}
}

void CAboutDlg::Localize(void)
{
	GetDlgItem(IDC_EDT_BOX)->SetWindowText(GetResString(IDS_LICENSE));
	GetDlgItem(IDC_STATIC_NAME)->SetWindowText(GetResString(IDS_ABOUTBOX_CAPTION));
	GetDlgItem(IDC_STATIC_COPYRIGHT)->SetWindowText(GetResString(IDS_COPYRIGHT));
	GetDlgItem(IDOK)->SetWindowText(GetResString(IDS_OK));
	SetWindowText(GetResString(IDS_ABOUTBOX_CAPTION));
}


// CInstallDlg 对话框

CInstallDlg::CInstallDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInstallDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strInstallPath = "";
}

void CInstallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_INSTALLPATH, m_ComboInstallPath);
}

BEGIN_MESSAGE_MAP(CInstallDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CInstallDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CInstallDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CInstallDlg 消息处理程序

BOOL CInstallDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	//ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	//ASSERT(IDM_ABOUTBOX < 0xF000);

	//CMenu* pSysMenu = GetSystemMenu(FALSE);
	//if (pSysMenu != NULL)
	//{
	//	CString strAboutMenu;
	//	strAboutMenu.LoadString(IDS_ABOUTBOX);
	//	if (!strAboutMenu.IsEmpty())
	//	{
	//		pSysMenu->AppendMenu(MF_SEPARATOR);
	//		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	//	}
	//}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	CAboutDlg dlg;
	dlg.DoModal();

	theApp.m_lsetup.SetLanguageID(theApp.m_wdCurrentLocaleID);
	theApp.m_lsetup.SetLanguage();
	Localize();

	LPCTSTR lp[] = {
		_T("SOFTWARE\\Autodesk\\AutoCAD\\R17.1\\ACAD-6002:804"),
		_T("SOFTWARE\\Autodesk\\AutoCAD\\R17.1\\ACAD-6000:804"),
		/*	支持英文Map 3D 和 Civil 3D	*/
		_T("SOFTWARE\\Autodesk\\AutoCAD\\R17.1\\ACAD-6002:409"),
		_T("SOFTWARE\\Autodesk\\AutoCAD\\R17.1\\ACAD-6000:409")
	};

	for (int i = 0; i < _COUNTOF(lp); i++)
	{
		CRegKey rk;
		DWORD pCount = MAX_PATH + 1024;
		CString KeyValue;
		TCHAR szValue[MAX_PATH + 1024];
		if (rk.Open(HKEY_LOCAL_MACHINE, lp[i]) == ERROR_SUCCESS)
		{
			LPCTSTR lKeyName = _T("Location");

			if(rk.QueryStringValue(lKeyName, szValue, &pCount) == ERROR_SUCCESS)
			{
				KeyValue = szValue;
				m_ComboInstallPath.AddString(KeyValue);

				GetDlgItem(IDOK)->EnableWindow(TRUE);
			}
		}
		rk.Close();

	}

	if(m_ComboInstallPath.GetCount() == 0)
		ShowInfo(GetResString(IDS_SHOW_NOT_FOUND_PATH));
	else
		m_ComboInstallPath.SetCurSel(0);

	Localize();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CInstallDlg::Localize(void)
{
	GetDlgItem(IDOK)->SetWindowText(GetResString(IDS_INSTALL));
	GetDlgItem(IDCANCEL)->SetWindowText(GetResString(IDS_CANCEL));
	GetDlgItem(IDC_BTN_UNINASTALL)->SetWindowText(GetResString(IDS_UNINASTALL));
	GetDlgItem(IDC_STATIC_PATH)->SetWindowText(GetResString(IDS_STATIC_PATH));
	GetDlgItem(IDC_STATIC_OPTION)->SetWindowText(GetResString(IDS_STATIC_OPTION));
	SetWindowText(GetResString(IDS_CAPTION));
}


void CInstallDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CInstallDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CInstallDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CInstallDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	MessageBox(GetResString(IDS_INSTALL_INFO), GetResString(IDS_INSTALL_TITLE),
		MB_OK | MB_ICONEXCLAMATION);

	UpdateData();

	int nCurSel = m_ComboInstallPath.GetCurSel();
	if (nCurSel == -1)
		return ;

	m_ComboInstallPath.GetLBText(nCurSel, m_strInstallPath);
		
	InstallProvider();

	OnOK();
}

void CInstallDlg::InstallProvider(void)
{
	// 读文件列表 "filelist.lst"
	CStdioFile file;

	if( !file.Open( _T("filelist.lst"), CFile::modeRead | CFile::typeText ) ) 
	{
		MessageBox(GetResString(IDS_NOT_FILELIST), GetResString(IDS_INSTALL_TITLE),
		MB_OK | MB_ICONEXCLAMATION);
		return ;
	}
	
	// 开始安装
	GetDlgItem(IDOK)->EnableWindow(FALSE);

	// 过滤文件
	switch(theApp.m_wdCurrentLocaleID)
	{
	case LANGID_ZH_CN:
		{
			// 改名
			CopyFile(_T("SuperMapConnectionPluginCN.dll"), _T("SuperMapConnectionPlugin.dll"), FALSE);
			CopyFile(_T("SuperMapMessageCN.dll"), _T("SuperMapMessage.dll"), FALSE);
		}
		break;
	case LANGID_EN_US:
		{
			CopyFile(_T("SuperMapConnectionPluginEN.dll"), _T("SuperMapConnectionPlugin.dll"), FALSE);
			FileUtil::Delete(_T("SuperMapMessage.dll"));
			CString strDel = m_strInstallPath + _T("\\FDO\\Bin\\SuperMapMessage.dll");
			FileUtil::Delete(strDel);
		}
		break;
	default:
		break;
	}


	TCHAR szNewPath[MAX_PATH];

	CString strBuffer;
	while(file.ReadString(strBuffer)) 
	{
		if(strBuffer.Trim().GetLength() != 0 && strBuffer[0] != '#')
		{
			CString strInstallFile = FileUtil::GetPartContent(strBuffer, FileUtil::FNAME) 
						+ FileUtil::GetPartContent(strBuffer, FileUtil::EXT);
			if(FileUtil::FileExists(strInstallFile))
			{
				//Sleep(500);
				ShowInfo(GetResString(IDS_COPYING) + strBuffer + CString(" ..."));

				//
				CString strPath = FileUtil::GetPartContent(strBuffer, FileUtil::DRIVE)
					+ FileUtil::GetPartContent(strBuffer, FileUtil::DIR);

				CString strMakePath;
				if ( !strPath.IsEmpty() )
				{
					if(FileUtil::GetPartContent(strBuffer, FileUtil::DRIVE).IsEmpty())
					{
						if(strPath[0] != '\\' && strPath[0] != '/')
							strMakePath = m_strInstallPath  + CString("\\FDO\\Bin\\") + strPath;
						else
							// 如果是根目录，加上盘符
							strMakePath = FileUtil::GetPartContent(m_strInstallPath, FileUtil::DRIVE) + strPath;
					}
					else
					{
						strMakePath = strPath;
					}

					if (!FileUtil::SuperMkDir(strMakePath))
					{
						AfxMessageBox(GetResString(IDS_NOTDIR));
						GetDlgItem(IDOK)->EnableWindow(TRUE);
						ShowInfo(strPath);
						return ;
					}
				}
				else
				{
					strMakePath = m_strInstallPath  + CString("\\FDO\\Bin\\"); 
				}

				_stprintf(szNewPath, _T("%s%s"), strMakePath, strInstallFile);

				if (!CopyFile(strInstallFile, szNewPath, FALSE)) // 覆盖
				{
					MessageBox(GetResString(IDS_NO_COPYFILE) + strInstallFile, 
						GetResString(IDS_INSTALL_TITLE),
						MB_OK | MB_ICONERROR);
				}
			}
		}
	}

	file.Close();

	ShowInfo(GetResString(IDS_SHOW_CONFIG));
	// 配置文件
	CString strPathName = m_strInstallPath  + CString("\\FDO\\Bin\\SuperMapProvider.dll"); 
	RegisterJob(strPathName, REGDLL_INSTALL);

	// 安装完成
	GetDlgItem(IDOK)->EnableWindow(TRUE);
	ShowInfo(GetResString(IDS_SHOW_INSTALL_DONE));
	AfxMessageBox(GetResString(IDS_SHOW_INSTALL_DONE));
}

void CInstallDlg::UninstallProvider(void)
{
	CString strPathName = m_strInstallPath  + CString("\\FDO\\Bin\\SuperMapProvider.dll"); 
	RegisterJob(strPathName, REGDLL_UNINSTALL);
}


void CInstallDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}

void CInstallDlg::ShowInfo(CString info)
{
	GetDlgItem(IDC_STATIC_INFO)->SetWindowText(info);
}

void CInstallDlg::RegisterJob(CString strFullFileName, int nOpCode)
{
	TCHAR pszCmdLine[_MAX_PATH + 1];	//	command line for regsvr32.exe

	switch(nOpCode)
	{
	case REGDLL_INSTALL:
		_stprintf(pszCmdLine, _T("regsvr32.exe /s \"%s\""), strFullFileName);
		break;
	case REGDLL_UNINSTALL:
		_stprintf(pszCmdLine, _T("regsvr32.exe /s /u \"%s\""), strFullFileName);
		break;
	default:
		break;
	}

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOW;
	ZeroMemory(&pi, sizeof(pi));

	if(CreateProcess(0, pszCmdLine, 0, 0, FALSE, CREATE_DEFAULT_ERROR_MODE | NORMAL_PRIORITY_CLASS, 0, 0, &si, &pi))
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		MessageBox(GetResString(IDS_PROCESS_ERROR), GetResString(IDS_INSTALL_TITLE), MB_OK);
	}
}

/*
	LANGID a = LANGID_ZH_CN;
	LANGID b = LANGID_EN_US;
*/
