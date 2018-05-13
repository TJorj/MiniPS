//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <jpeg.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu;
	TMenuItem *File;
	TMenuItem *Save;
	TMenuItem *Load;
	TMenuItem *Filter1;
	TImage *MainImageContainer;
	TMenuItem *New;
	TOpenDialog *OpenDialogLoadImage;
	TMenuItem *View1;
	TMenuItem *Histogram1;
	TMenuItem *Modify1;
	TMenuItem *Mirror1;
	TMenuItem *Flip1;
	TMenuItem *None1;
	TMenuItem *Sepia1;
	TMenuItem *Negative1;
	TMenuItem *Metalic1;
	TMenuItem *RotateClockwise901;
	TMenuItem *RotateClockwise1801;
	TSaveDialog *SaveDialog1;
	TChart *HistogramChart;
	TFastLineSeries *Series1;
	TFastLineSeries *Series2;
	TFastLineSeries *Series3;
	TMenuItem *Color1;
	TMenuItem *RedChannel1;
	TMenuItem *GreenChannel1;
	TMenuItem *BlueChannel1;
	TMenuItem *Grayscale1;
	TMenuItem *RecomputeHistogram1;
	TMenuItem *Stretch1;
	TMenuItem *Proportional1;
	TMenuItem *Reset1;
	TMenuItem *ZoomIn1;
	TMenuItem *ZoomOut1;
	TMenuItem *About1;
	void __fastcall LoadClick(TObject *Sender);
	void __fastcall Mirror1Click(TObject *Sender);
	void __fastcall Flip1Click(TObject *Sender);
	void __fastcall Sepia1Click(TObject *Sender);
	void __fastcall Negative1Click(TObject *Sender);
	void __fastcall Metalic1Click(TObject *Sender);
	void __fastcall None1Click(TObject *Sender);
	void __fastcall RotateClockwise901Click(TObject *Sender);
	void __fastcall RotateClockwise1801Click(TObject *Sender);
	void __fastcall SaveClick(TObject *Sender);
	void __fastcall NewClick(TObject *Sender);
	void __fastcall Histogram1Click(TObject *Sender);
	void __fastcall RedChannel1Click(TObject *Sender);
	void __fastcall GreenChannel1Click(TObject *Sender);
	void __fastcall BlueChannel1Click(TObject *Sender);
	void __fastcall Grayscale1Click(TObject *Sender);
	void __fastcall RecomputeHistogram1Click(TObject *Sender);
	void __fastcall Proportional1Click(TObject *Sender);
	void __fastcall Stretch1Click(TObject *Sender);
	void __fastcall Reset1Click(TObject *Sender);
	void __fastcall ZoomIn1Click(TObject *Sender);
	void __fastcall ZoomOut1Click(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
