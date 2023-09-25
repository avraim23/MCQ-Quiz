//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *QuestionLabel;
	TLabel *Points;
	TLabel *PointsLabel;
	TRadioButton *AnswerOneRadioButton;
	TRadioButton *AnswerTwoRadioButton;
	TRadioButton *AnswerThreeRadioButton;
	TButton *ConfirmAnswerButton;
	void __fastcall AnswerOneRadioButtonChange(TObject *Sender);
	void __fastcall AnswerTwoRadioButtonChange(TObject *Sender);
	void __fastcall AnswerThreeRadioButtonChange(TObject *Sender);
	void __fastcall ConfirmAnswerButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
