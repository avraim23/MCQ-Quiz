//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <queue>
#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

class question
{
	public:
		char *Text ;
		char *answerOne ;
		char *answerTwo ;
		char *answerThree ;
		int correctAnswer ;
		question(){} ;
		question( char* text , char* ans1 , char* ans2 , char* ans3 , int correctAns)
		{
			Text = text ;
			answerOne = ans1 ;
			answerTwo = ans2 ;
			answerThree = ans3 ;
			correctAnswer = correctAns ;
		}
};

std::queue<question> loadQuestions()
{
	question q1=question("Color Does Not Appeer In Olymic Ring ? " , "Black" , "Orange" , "Blue" , 2 ) ;
	question q2=question("Chemical Formula For Table Salt ? " , "NaCl2" , "NaCl" , "Na2Cl3" , 2 ) ;
	question q3=question("Longest River In The World ? " , "Nile" , "Amazon" , "Misissipi" , 1 ) ;

	std::queue<question> Questions ;
	Questions.push(q1);
	Questions.push(q2);
	Questions.push(q3);

	return Questions ;
}
std::queue<question> questions ;
question currentQuestion ;
int selectedAnswer ;
int points = 0 ;

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	PointsLabel->Text = points ;
	questions = loadQuestions() ;
	currentQuestion = questions.front();


	QuestionLabel->Text = currentQuestion.Text ;
	AnswerOneRadioButton->Text = currentQuestion.answerOne ;
	AnswerTwoRadioButton->Text = currentQuestion.answerTwo ;
	AnswerThreeRadioButton->Text = currentQuestion.answerThree ;

	questions.pop();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AnswerOneRadioButtonChange(TObject *Sender)
{
	selectedAnswer = 1 ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AnswerTwoRadioButtonChange(TObject *Sender)
{
	selectedAnswer = 2 ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AnswerThreeRadioButtonChange(TObject *Sender)
{
	selectedAnswer = 3 ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConfirmAnswerButtonClick(TObject *Sender)
{
	if (selectedAnswer == currentQuestion.correctAnswer)
	{
		points++;
	}
	PointsLabel->Text = points ;
	if (!questions.empty())
	{
		currentQuestion = questions.front();
		QuestionLabel->Text = currentQuestion.Text ;
		AnswerOneRadioButton->Text = currentQuestion.answerOne ;
		AnswerTwoRadioButton->Text = currentQuestion.answerTwo ;
		AnswerThreeRadioButton->Text = currentQuestion.answerThree ;
		questions.pop();
		AnswerOneRadioButton->IsChecked = false ;
		AnswerTwoRadioButton->IsChecked = false ;
		AnswerThreeRadioButton->IsChecked = false ;
	}
	else
	{
	   ConfirmAnswerButton->Enabled = false ;
	   ConfirmAnswerButton->Text = "THE END" ;
    }
}
//---------------------------------------------------------------------------
