// 处理 BAS 文件 --> TXT 文件

#include "stdafx.h"
#include "Bas2Txt.h"


BOOL Bas2Txt::Start(CString *szBasFile,CString *szTxtFile)
{
	CFile Bas,Txt;
	CString str;
	DWORD FileLength;
	DWORD i;
	if (!Bas.Open(*(szBasFile),CFile::modeRead)) return FALSE;
	if (!Txt.Open(*(szTxtFile),CFile::modeCreate|CFile::modeWrite)) return FALSE;

	FileLength=Bas.GetLength();
	for (i=0;i<FileLength;i++)
 	{
		if (Rec(&Bas,&str)) break;
		Txt.Write(str,str.GetLength());
		Txt.Write("\n",1);
		str.Empty();
	}
 
	Bas.Close();
    Txt.Close();

	return TRUE;

}

BOOL Bas2Txt::Rec(CFile *fp,CString *string)
{
	char *m_Table[116]=
	{
		"FORMAT","FOR","NEXT","DATA","INPUT",
		"DELETE","DIM","READ","GR","TEXT",
		"PIC","MON","CALL","PLOT","HLIN",
		"VLIN","SYSTEM","CHINESE","RENAME","HPLOT",
		"END","GAME","HTAB","HOME","DIR",
		"SCALE=","MOTOR","TRACE","NOTRACE","NORMAL",
		"INVERSE","FLASH","COLOR=","POP","VTAB",
		"HIMEM:","LOMEM:","ONERR","RESUME","SOUND=",
		"MUSIC","SPEED=","LET","GOTO","RUN","IF",
		"RESTORE","&","GOSUB","RETURN","REM",
		"STOP","ON","WAIT","LOAD","SAVE",
		"DEF","POKE","PRINT","CONT","LIST",
		"CLEAR","GET","NEW","TAB(","TO",
		"FN","SPC(","THEN","AT","NOT",
		"STEP","+","-","*","/",
		"^","AND","OR",">","=",
		"<","SGN","INT","ABS","USR",
		"FRE","SCRN(","JOY","POS","SQR",
		"RND","LOG","EXP","COS","SIN",
		"TAN","ATN","PEEK","LEN","STR$",
		"VAL","ASC","CHR$","LEFT$","RIGHT$",
		"MID$","HEX$","OFF","PALET","SLOT",
		"DEL","WPS","PR","KEY$","STUDY"
	};
	CString str;
	unsigned char data[500],ch;
	int i,j,LineNumber;
	if (fp->Read(data,4)<4) return TRUE;
	if (*(data)==0 && *(data+1)==0) return TRUE;
	for (i=4;i<500;i++)
	{
		fp->Read(&ch,1);
		*(data+i)=ch;
		if (ch==0) break;
	}
	LineNumber=(*(data+3)<<8)+(*(data+2));
	string->Format("%d ",LineNumber);
	for (j=4;j<=i && j<500;j++)
	{
		ch = *(data+j);
		if (ch==0) break;
		if (ch>127 && ch<244)
		{
			string->Insert(string->GetLength(),m_Table[ch-128]);
			string->Insert(string->GetLength()," ");
		}
		else
		{
			string->Insert(string->GetLength(),ch);
		}
	}

	return FALSE;
}
