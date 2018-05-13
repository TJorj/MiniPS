//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ContrastSetter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
double * contrast;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner, double * _contrast)
	: TForm(Owner)
{
   contrast = _contrast;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConfirmContrastClick(TObject *Sender)
{
     contrast = ContrastInputValue ->Text.ToDouble();
    Close();
}
//---------------------------------------------------------------------------

