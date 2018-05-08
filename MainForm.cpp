//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::LoadClick(TObject *Sender)
{
		  OpenDialogLoadImage->Filter =
		   "JPEG images (*.jpg)|*.jpg| Bmp files (*.bmp) | *.BMP; " ;
        if (OpenDialogLoadImage->Execute())
		{
            if (!FileExists(OpenDialogLoadImage->FileName))
                return; // make sure it exists, else get out.
			AnsiString temp2 = ExtractFileName(OpenDialogLoadImage->FileName);
            AnsiString temp = ExtractFileExt(OpenDialogLoadImage->FileName);
			AnsiString Ext = temp.LowerCase();

            if (Ext.AnsiPos("jpg") > 0)  // it's a jpg
            {   //-- Decompress the jpeg image into a bitmap.
                TJPEGImage *myjpeg = new TJPEGImage();
                myjpeg->LoadFromFile(OpenDialogLoadImage->FileName);
                myjpeg->DIBNeeded();  // used when jpeg image needs bitmap rep
				MainImageContainer->Picture->Bitmap->Assign(myjpeg);
				delete myjpeg;
            }
            else if (Ext.AnsiPos("bmp") > 0)
				MainImageContainer->Picture->Bitmap->LoadFromFile(OpenDialogLoadImage->FileName);
          }
}
//---------------------------------------------------------------------------

