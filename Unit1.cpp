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



   // �b�����I�s perm() �� button ���G

	//k = StrToInt(Edit1->Text);

	//n = StrToInt(Edit2->Text);

	//perm( list, k, n );      // �ǤJ list �}�C�B�_�l���� k�P�r����� n

//�ܩ� perm(~) �� recursive function �h�i�b��X�ɧ�g�p�U�G

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

   ch[i] = '\0';    // �r���}�C�B�r�ꪺ����

   // �NŪ�J�� String a[1:a.Length()] �v�r�s�J ch[0:a.Length()-1]

   k = StrToInt(Edit4->Text);    // ���o�ƦC�_�I

   n = Edit3->Text.Length();     // ���o�r����סB��e��J

   perm( ch, k, n );
}
//---------------------------------------------------------------------------



	void permStr(String in_string, int k, int n)

	{   int i;

		wchar_t tmp;     // �w�q tmp �� wchar_t ���A (��2 bytes) �A�i�s�񤤤�r

		if (k == n)       // �Q�Q����O (k == n) �ӫD (k == n-1)

		   Form1->Memo1->Lines->Add(in_string+"  ["+IntToStr(count++)+"]");

		else

		{   for (i=k; i<=n; i++)     // Note: in_string ���A�� String; �� in_string[i] ���A�� wchar_t

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

   n = in_string.Length();       // ���o�r����סB��e��J

   permStr( in_string, k+1, n );

//�p���@�� permStr(~) �� recursive function �i�b��X��²��o�h�G


}
//---------------------------------------------------------------------------


