// B2TDlg.h : header file
//

#if !defined(AFX_B2TDLG_H__1A306806_A119_11D2_B4BA_995AAAC0DC03__INCLUDED_)
#define AFX_B2TDLG_H__1A306806_A119_11D2_B4BA_995AAAC0DC03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CB2TDlg dialog

class CB2TDlg : public CDialog
{
// Construction
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CB2TDlg(CWnd* pParent = NULL);	// standard constructor

	BOOL fStart;
// Dialog Data
	//{{AFX_DATA(CB2TDlg)
	enum { IDD = IDD_B2T_DIALOG };
	CButton	m_StartButton;
	CString	m_BasName;
	CString	m_TxtName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB2TDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CB2TDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAboutButton();
	afx_msg void OnBasBrowse();
	afx_msg void OnTxtBrowse();
	afx_msg void OnChangeBasEdit();
	afx_msg void OnChangeTxtEdit();
	afx_msg void OnStartButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B2TDLG_H__1A306806_A119_11D2_B4BA_995AAAC0DC03__INCLUDED_)
