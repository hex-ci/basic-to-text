// 处理 GBS 文件 --> TXT 文件

#include "stdafx.h"
#include "Gbs2Txt.h"


BOOL Gbs2Txt::Start(CString *szGbsFile,CString *szTxtFile)
{
	CFile Gbs,Txt;
	CString str;
	DWORD FileLength;
	DWORD i;
	if (!Gbs.Open(*(szGbsFile),CFile::modeRead)) return FALSE;
	if (!Txt.Open(*(szTxtFile),CFile::modeCreate|CFile::modeWrite)) return FALSE;

	FileLength=Gbs.GetLength();
	for (i=0;i<FileLength;i++)
 	{
		if (Rec(&Gbs,&str)) break;
		Txt.Write(str,str.GetLength());
		Txt.Write("\n",1);
		str.Empty();
	}
 
	Gbs.Close();
    Txt.Close();

	return TRUE;

}

BOOL Gbs2Txt::Rec(CFile *fp,CString *string)
{
	char *m_Table[126]=
	{
		"GOTO","GOSUB","RUN","RETURN","RESTORE",
		"THEN","LIST","DIR","TO","STEP",
		"SPRITE","PRINT","FOR","NEXT","PAUSE",
		"INPUT","LINPUT","DATA","IF","READ",
		"DIM","REM","STOP","CONT","CLS",
		"CLEAR","ON","OFF","CUT","NEW",
		"POKE","CGSET","VIEW","MOVE","END",
		"PLAY","BEEP","LOAD","SAVE","POSITION",
		"KEY","COLOR","DEF","CGEN","SWAP","CALL",
		"LOCATE","PALET","ERA",
		"","","","","","","","","","","","","",
		"","","","","","","","","","","","",
		"ABS","ASC",
		"STR$","FRE","LEN","PEEK","RND",
		"SGN","SPC","TAB","MID$","STICK",
		"STRIG","XPOS","YPOS","VAL","POS",
		"CSRLIN","CHR$","HEX$","INKEY$","RIGHT$",
		"LEFT$","SCR$",
		"","","","","","","","","","","","","",
		"XOR","OR","AND",
		"NOT","<>",">=","<=","=",
		">","<","+","-","MOD",
		"/","*"
	};
	CString str;
	unsigned char data[500],TempBuf[20],ch;
	int i,j,LineNumber,TempNum;
	if (fp->Read(data,3)<3) return TRUE;
	if (*(data)==0 && *(data+1)==0) return TRUE;
	for (i=3;i<500;i++)
	{
		if (fp->Read(&ch,1)<1)
		{
			*(data+i) = 0;
			break;
		}
		*(data+i)=ch;

		if (ch==0x12)
		{
			fp->Read(data+i+1,2);
			i += 2;
		}
		else if (ch == 0x0b)
		{
			fp->Read(data+i+1,2);
			i += 2;
		}
		else if (ch==0)
		{
			break;
		}
	}
	LineNumber = (*(data+2)<<8)+(*(data+1));
	string->Format("%d ",LineNumber);
	for (j=3;j<=i && j<500;j++)
	{
		ch = *(data+j);
		if (ch == 0x12 && j+2<=i)
		{
			TempNum = (*(data+j+2)<<8)+(*(data+j+1));
			j += 2;
			itoa(TempNum,(char*)TempBuf,10);
			string->Insert(string->GetLength(), (char*)TempBuf);
		}
		else if (ch == 0x0b && j+2<=i)
		{
			TempNum = (*(data+j+2)<<8)+(*(data+j+1));
			j += 2;
			itoa(TempNum,(char*)TempBuf,10);
			string->Insert(string->GetLength(), (char*)TempBuf);
		}
		else if (ch>127 && ch<254)
		{
			string->Insert(string->GetLength(),m_Table[ch-128]);
			string->Insert(string->GetLength()," ");
		}
		else if (ch==0) break;
		else
		{
			string->Insert(string->GetLength(),ch);
		}
	}
	return FALSE;
}
