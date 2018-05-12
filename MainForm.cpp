//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "ContrastSetter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
Graphics::TBitmap *saveNormalState   = new Graphics::TBitmap;
int contrast;
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
			saveNormalState->Assign( MainImageContainer->Picture->Bitmap );
			saveNormalState->PixelFormat  =  MainImageContainer->Picture->Bitmap->PixelFormat;
		  }

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Mirror1Click(TObject *Sender)
{
		Graphics::TBitmap *source   = new Graphics::TBitmap;
        source->Assign( MainImageContainer->Picture->Bitmap );
		source->PixelFormat  =  MainImageContainer->Picture->Bitmap->PixelFormat;

        Graphics::TBitmap *dest     = new Graphics::TBitmap;
        dest->Width                 = source->Width;
        dest->Height                = source->Height;
        dest->PixelFormat           = source->PixelFormat;

        TColor color;

        for( int y=0; y<source->Height; y++ )
                {
                    for (int x=0; x<source->Width; x++)
                    {
                        dest->Canvas->Pixels[source->Width-x-1][y]=source->Canvas->Pixels[x][y];
                    }
                }
        MainImageContainer->Picture->Bitmap = dest;
		delete dest;  delete source;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Flip1Click(TObject *Sender)
{
		Graphics::TBitmap *source   = new Graphics::TBitmap;
		source->Assign( MainImageContainer->Picture->Bitmap );
		source->PixelFormat  =  MainImageContainer->Picture->Bitmap->PixelFormat;

        Graphics::TBitmap *dest     = new Graphics::TBitmap;
        dest->Width                 = source->Width;
        dest->Height                = source->Height;
        dest->PixelFormat           = source->PixelFormat;

        TColor color;

        for( int y=0; y<source->Height; y++ )
                {
                    for (int x=0; x<source->Width; x++)
                    {
                        dest->Canvas->Pixels[x][source->Height-y-1]=source->Canvas->Pixels[x][y];
					}
                }
		MainImageContainer->Picture->Bitmap = dest;
		//delete dest;  delete source;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Sepia1Click(TObject *Sender)
{
    Graphics::TBitmap *source   = new Graphics::TBitmap;
		source->Assign( MainImageContainer->Picture->Bitmap );
		source->PixelFormat  =  MainImageContainer->Picture->Bitmap->PixelFormat;

        Graphics::TBitmap *dest     = new Graphics::TBitmap;
        dest->Width                 = source->Width;
        dest->Height                = source->Height;
        dest->PixelFormat           = source->PixelFormat;
        dest->Assign(source);

        RGBTRIPLE* pixels;
        TColor color;
        for( int y=0; y<source->Height; y++ )
                {
                    pixels = (RGBTRIPLE*)source->ScanLine[y];
                    for (int x=0; x<source->Width; x++)
                       {int culoare = (pixels[x].rgbtRed + pixels[x].rgbtGreen + pixels[x].rgbtBlue)/3;
                       pixels[x].rgbtRed = culoare;
                       pixels[x].rgbtGreen = culoare;
                       pixels[x].rgbtBlue = culoare;
                       if(culoare>202) pixels[x].rgbtRed = 255;
                                else pixels[x].rgbtRed = culoare + 53;
                       if(culoare>235) pixels[x].rgbtGreen = 255;
                                else pixels[x].rgbtGreen = culoare + 20;
                       if(culoare<33) pixels[x].rgbtBlue = 0;
								else pixels[x].rgbtBlue = culoare - 33;
                       if(pixels[x].rgbtGreen<30) pixels[x].rgbtGreen=30;
                       if(pixels[x].rgbtBlue<30) pixels[x].rgbtBlue=30;
                       dest->Canvas->Pixels[x][y] = TColor(RGB(pixels[x].rgbtRed,pixels[x].rgbtGreen,pixels[x].rgbtBlue));
                       }
                }
		MainImageContainer->Picture->Bitmap = dest;
		delete dest; delete source;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Negative1Click(TObject *Sender)
{
		Graphics::TBitmap *source   = new Graphics::TBitmap;
        source->Assign( MainImageContainer->Picture->Bitmap );
		source->PixelFormat  =  MainImageContainer->Picture->Bitmap->PixelFormat;

        Graphics::TBitmap *dest     = new Graphics::TBitmap;
        dest->Width                 = source->Width;
        dest->Height                = source->Height;
        dest->PixelFormat           = source->PixelFormat;
        dest->Assign(source);

        RGBTRIPLE* pixels;
        TColor color;
        for( int y=0; y<source->Height; y++ )
                {
                    pixels = (RGBTRIPLE*)source->ScanLine[y];

                    for (int x=0; x<source->Width; x++)
                    {
                       dest->Canvas->Pixels[x][y] = TColor(RGB(255-pixels[x].rgbtRed, 255-pixels[x].rgbtGreen, 255-pixels[x].rgbtBlue));
                    }
                }
        MainImageContainer->Picture->Bitmap = dest;
		delete dest; delete source;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Metalic1Click(TObject *Sender)
{
    	Graphics::TBitmap *source   = new Graphics::TBitmap;
		source->Assign( MainImageContainer->Picture->Bitmap );
		source->PixelFormat  =  MainImageContainer->Picture->Bitmap->PixelFormat;

        Graphics::TBitmap *dest     = new Graphics::TBitmap;
        dest->Width                 = source->Width;
        dest->Height                = source->Height;
        dest->PixelFormat           = source->PixelFormat;

        RGBTRIPLE* pixels;
        TColor color;
        int R,G,B;
        int level=4;
        int mtab[256];
        for( int j=0; j<255; j++ )
                {
                    for (int k=0; k<256; k+= level)
                    {
                       mtab[j++] = k;
                    }
                    for(int k=255; k > 0; k-=level)
                    {
                        mtab[j++] = k;
                    }
                 }
        mtab[255] = (level % 2 == 0) ? 0 : 255;
        for( int y=0; y<source->Height; y++ )
                {
                    pixels = (RGBTRIPLE*)source->ScanLine[y];
                    for (int x=0; x<source->Width; x++)
                    {
                        R = mtab[pixels[x].rgbtRed];
                        G = mtab[pixels[x].rgbtGreen];
                        B = mtab[pixels[x].rgbtBlue];
                        dest->Canvas->Pixels[x][y] = TColor(RGB(R,G,B));

                    }
                }
		MainImageContainer->Picture->Bitmap = dest;
		delete dest;  delete source;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::None1Click(TObject *Sender)
{
	MainImageContainer->Picture->Bitmap = saveNormalState;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RotateClockwise901Click(TObject *Sender)
{
		Graphics::TBitmap *source   = new Graphics::TBitmap;
		source->Assign( MainImageContainer->Picture->Bitmap );
		source->PixelFormat  =  MainImageContainer->Picture->Bitmap->PixelFormat;

		Graphics::TBitmap *dest     = new Graphics::TBitmap;
		dest->Width                 = source->Width;
		dest->Height                = source->Height;
		dest->PixelFormat           = MainImageContainer->Picture->Bitmap->PixelFormat;

		RGBTRIPLE* pixels;
		TColor color;

		//rotate by 90‹

		dest->Width=source->Height;
		dest->Height=source->Width;

		//Rotate one pixel at a time
		for (int x=0;x<source->Width;x++)
		{
				for(int y=0;y<source->Height;y++)
				{
						dest->Canvas->Pixels[y][source->Width-1-x]=source->Canvas->Pixels[x][y];
				}
		}

		MainImageContainer->Picture->Bitmap=dest;
		delete dest; delete source;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RotateClockwise1801Click(TObject *Sender)
{
		Graphics::TBitmap *source   = new Graphics::TBitmap;
		source->Assign( MainImageContainer->Picture->Bitmap );
		source->PixelFormat  =  MainImageContainer->Picture->Bitmap->PixelFormat;

        Graphics::TBitmap *dest     = new Graphics::TBitmap;
        dest->Width                 = source->Width;
        dest->Height                = source->Height;
        dest->PixelFormat           = source->PixelFormat;

        RGBTRIPLE* pixels;
        TColor color;

        //rotate with 180 degrees
        dest->Width=source->Width;
        dest->Height=source->Height;

        //Rotate one pixel at a time
        for (int x=0;x<source->Width;x++)
        {
                for(int y=0;y<source->Height;y++)
                {
                        dest->Canvas->Pixels[x][source->Height-1-y]=source->Canvas->Pixels[x][y];
                }
        }

        MainImageContainer->Picture->Bitmap=dest;
        delete dest; delete source;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::SaveClick(TObject *Sender)
{
	if( MainImageContainer->Picture->Bitmap->Empty == true )
                return;
        SaveDialog1->Title = "Save Image";
        SaveDialog1->DefaultExt = "jpg";
        SaveDialog1->Filter =
               "JPEG images (*.jpg) | *.jpg; | Bmp files (*.bmp)|*.BMP" ;
        SaveDialog1->FilterIndex = 1;
        if (SaveDialog1->Execute())
        {
            AnsiString temp2 = ExtractFileName(SaveDialog1->FileName);
            AnsiString temp = ExtractFileExt(SaveDialog1->FileName);
            AnsiString Ext = temp.LowerCase();

            if (Ext.AnsiPos("jpg") > 0)
            {
                TJPEGImage *jp = new TJPEGImage();
                try
                {
				  jp->Assign(MainImageContainer->Picture->Bitmap);
                  jp->SaveToFile(SaveDialog1->FileName);
                }
                __finally
                {
                  delete jp;
                }
            }
            else  if (Ext.AnsiPos("bmp") > 0)
            {
			   MainImageContainer->Picture->Bitmap->SaveToFile(SaveDialog1->FileName);
            }
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::NewClick(TObject *Sender)
{


        Graphics::TBitmap *dest     = new Graphics::TBitmap;
		dest->Width                 = MainImageContainer->Width;
		dest->Height                = MainImageContainer->Height;

        RGBTRIPLE* pixels;
        TColor color;


		for( int y=0; y<dest->Height; y++ )
				{

					for (int x=0; x<dest->Width; x++)
					   dest->Canvas->Pixels[x][y] = TColor(0x00FFFFFF);
                }

        MainImageContainer->Picture->Bitmap=dest;
		delete dest;
}
//---------------------------------------------------------------------------

