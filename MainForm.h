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
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
