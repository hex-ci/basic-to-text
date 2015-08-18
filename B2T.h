// B2T.h : main header file for the B2T application
//

#if !defined(AFX_B2T_H__1A306804_A119_11D2_B4BA_995AAAC0DC03__INCLUDED_)
#define AFX_B2T_H__1A306804_A119_11D2_B4BA_995AAAC0DC03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CB2TApp:
// See B2T.cpp for the implementation of this class
//

class CB2TApp : public CWinApp
{
public:
	CB2TApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB2TApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CB2TApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B2T_H__1A306804_A119_11D2_B4BA_995AAAC0DC03__INCLUDED_)
