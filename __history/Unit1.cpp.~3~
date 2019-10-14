//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
 # define SWAP(x,y,t) (t=x,x=y,y=t)
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int  k,n,count=0;

char list [9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------



   // 在對應呼叫 perm() 的 button 中：

	//k = StrToInt(Edit1->Text);

	//n = StrToInt(Edit2->Text);

	//perm( list, k, n );      // 傳入 list 陣列、起始註標 k與字串長度 n

//至於 perm(~) 此 recursive function 則可在輸出時改寫如下：

void perm(char *list, int k, int n)

{   int i, tmp;

	if (k == n-1)

	{   String a = list;     // Convert char * list to String a

	   a = a.SubString(1, n);   // The first n characters of a

	   // a.SubString(1, n) ==> the n-char starting from a[1]

	   Form1->Memo1->Lines->Add(a+"  ["+IntToStr(count++)+"]");

	}
	else

	{   for (i=k; i<n; i++)

	   {   SWAP(list[k], list[i], tmp);

		  perm(list, k+1, n);

		  SWAP(list[k], list[i], tmp);

	   }

	}

}
void __fastcall TForm1::Button1Click(TObject *Sender)
{

	k = StrToInt(Edit1->Text);
	n = StrToInt(Edit2->Text);
	perm( list, k, n );
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button3Click(TObject *Sender)
{
	char ch[100];
	int i;
   String a = Edit3->Text;

   // for (i = 1; i <= a.Length(); i++)

   //     Memo2->Lines->Add("ch["+IntToStr(i)+"] = "+a[i]);

	// Hint: String a starting from position 1 ending at a.Length()

   for ( i = 0; i < a.Length(); i++) ch[i] = a[i+1];

   ch[i] = '\0';    // 字元陣列、字串的結尾

   // 將讀入的 String a[1:a.Length()] 逐字存入 ch[0:a.Length()-1]

   k = StrToInt(Edit4->Text);    // 取得排列起點

   n = Edit3->Text.Length();     // 取得字串長度、毋庸輸入

   perm( ch, k, n );
}
//---------------------------------------------------------------------------



	void permStr(String in_string, int k, int n)

	{   int i;

		wchar_t tmp;     // 定義 tmp 為 wchar_t 型態 (佔2 bytes) ，可存放中文字

		if (k == n)       // 想想為何是 (k == n) 而非 (k == n-1)

		   Form1->Memo1->Lines->Add(in_string+"  ["+IntToStr(count++)+"]");

		else

		{   for (i=k; i<=n; i++)     // Note: in_string 型態為 String; 而 in_string[i] 型態為 wchar_t

		   {   SWAP(in_string[k], in_string[i], tmp);

			  permStr(in_string, k+1, n);

			  SWAP(in_string[k], in_string[i], tmp);

		   }

		}

	}







void __fastcall TForm1::Button2Click(TObject *Sender)
{
   String	   in_string = Edit3->Text;

   k = StrToInt(Edit4->Text);

   n = in_string.Length();       // 取得字串長度、毋庸輸入

   permStr( in_string, k+1, n );

//如此一來 permStr(~) 此 recursive function 可在輸出時簡單得多：


}
//---------------------------------------------------------------------------


