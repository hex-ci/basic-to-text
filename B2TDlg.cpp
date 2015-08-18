// B2TDlg.cpp : implementation file
//

#include "stdafx.h"
#include "B2T.h"
#include "B2TDlg.h"

#include "Bas2Txt.h"
#include "Gbs2Txt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CB2TDlg dialog

CB2TDlg::CB2TDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CB2TDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CB2TDlg)
	m_BasName = _T("");
	m_TxtName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
	fStart=FALSE;

}

void CB2TDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CB2TDlg)
	DDX_Control(pDX, IDC_START_BUTTON, m_StartButton);
	DDX_Text(pDX, IDC_BAS_EDIT, m_BasName);
	DDV_MaxChars(pDX, m_BasName, 255);
	DDX_Text(pDX, IDC_TXT_EDIT, m_TxtName);
	DDV_MaxChars(pDX, m_TxtName, 255);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CB2TDlg, CDialog)
	//{{AFX_MSG_MAP(CB2TDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ABOUT_BUTTON, OnAboutButton)
	ON_BN_CLICKED(IDC_BAS_BROWSE, OnBasBrowse)
	ON_BN_CLICKED(IDC_TXT_BROWSE, OnTxtBrowse)
	ON_EN_CHANGE(IDC_BAS_EDIT, OnChangeBasEdit)
	ON_EN_CHANGE(IDC_TXT_EDIT, OnChangeTxtEdit)
	ON_BN_CLICKED(IDC_START_BUTTON, OnStartButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CB2TDlg message handlers

BOOL CB2TDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	// CG: The following block was added by the ToolTips component.
	{
		// Create the ToolTip control.
		m_tooltip.Create(this);
		m_tooltip.Activate(TRUE);

		// TODO: Use one of the following forms to add controls:
		// m_tooltip.AddTool(GetDlgItem(IDC_<name>), <string-table-id>);
		// m_tooltip.AddTool(GetDlgItem(IDC_<name>), "<text>");
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CB2TDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CB2TDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CB2TDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CB2TDlg::OnAboutButton() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();

	// TODO: Add your control notification handler code here
	
}

void CB2TDlg::OnBasBrowse() 
{
	char szFileFilter[]="HT-BASIC 文件(*.BAS)|*.BAS|G-BASIC 文件(*.GBS)|*.GBS|所有文件(*.*)|*.*||";
	CFileDialog dlg(TRUE,
		"BAS",
		"",
		OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,
		szFileFilter,
		this);
	if (dlg.DoModal()==IDOK)
	{
		int i;
		CString temp;
		m_BasName=dlg.GetPathName();
		i=m_BasName.FindOneOf(".");
		temp=m_BasName.Left(i);
		m_TxtName=temp+".txt";
		UpdateData(FALSE);
	}

	// TODO: Add your control notification handler code here
	
}

void CB2TDlg::OnTxtBrowse() 
{
	char szFileFilter[]="文本文件(*.TXT)|*.TXT|所有文件(*.*)|*.*||";
	CFileDialog dlg(FALSE,
		"TXT",
		"",
		OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,
		szFileFilter,
		this);
	if (dlg.DoModal()==IDOK)
	{
		m_TxtName=dlg.GetPathName();
		UpdateData(FALSE);
	}

	// TODO: Add your control notification handler code here
	
}

void CB2TDlg::OnChangeBasEdit() 
{
	UpdateData(TRUE);
	
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CB2TDlg::OnChangeTxtEdit() 
{
	UpdateData(TRUE);
	
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CB2TDlg::OnStartButton() 
{
	m_BasName.MakeUpper();

	if (m_BasName.IsEmpty() || m_TxtName.IsEmpty())
	{
		MessageBox("对不起！您还没有输入文件名！","错误",MB_OK | MB_ICONEXCLAMATION);
	}
	else if (m_BasName.Right(4) == ".GBS")
	{
		Gbs2Txt g2t;
		if (g2t.Start(&m_BasName,&m_TxtName))
			MessageBox("恭喜！转换完成！","完成",MB_OK | MB_ICONINFORMATION);
		else
			MessageBox("抱歉！转换失败！\n可能原因：文件未找到！","错误",MB_OK | MB_ICONEXCLAMATION);
	}
	else if (m_BasName.Right(4) == ".BAS")
	{
		Bas2Txt b2t;
		if (b2t.Start(&m_BasName,&m_TxtName))
			MessageBox("恭喜！转换完成！","完成",MB_OK | MB_ICONINFORMATION);
		else
			MessageBox("抱歉！转换失败！\n可能原因：文件未找到！","错误",MB_OK | MB_ICONEXCLAMATION);
	}
	else
	{
		MessageBox("对不起！暂不支持此类型文件，或者文件未找到！","错误",MB_OK | MB_ICONEXCLAMATION);
	}

	// TODO: Add your control notification handler code here
}

BOOL CB2TDlg::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following block was added by the ToolTips component.
	{
		// Let the ToolTip process this message.
		m_tooltip.RelayEvent(pMsg);
	}
	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}
