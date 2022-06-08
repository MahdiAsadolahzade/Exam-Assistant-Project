#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<stdlib.h>
#include<array>
#include<time.h>
#include<stdio.h>
#include<algorithm>
#include"TimeClass.h"
#include"DateClass.h"

using namespace std;

vector <string> QuestionsTest[100];
vector <string> Blank1[100];
vector <string> Blank2[100];
vector <string> Blank3[100];
vector <string> Blank4[100];

vector <string> QuestionsTrueFalse[100];
vector <string> BlankT[100];
vector <string> BlankF[100];

vector <string> QuestionsAnatomical[100];
vector <string> Answers[100];
static int Qcounter = 0;

vector <int> RightAnswers[100];
vector <int> WrongAnswers[100];

vector <double> Resaults[100];

void clean();
class Exam
{
private:
	int examnum;
	int QuestionMode;
public:
	
	void setexamnum(int num)
	{
		examnum = num;
	}

	void setquestionmode(int mode)
	{
		QuestionMode = mode;
	}

	void setquestions()
	{
		string str1;
		switch (QuestionMode)
		{
		case 1:
			cout << "Enter your questions " << endl;
			getline(cin, str1);
			for (int i = 0; i < examnum; i++)
			{
				string str ;
				string ans1;
				string ans2;
				string ans3;
				string ans4;
				cout << "Question" << i + 1 << ":" << endl;
				getline(cin, str);
				QuestionsTest->push_back(str);

				cout << "Answer 1 (True):" << endl;
				getline(cin, ans1);
				Blank1->push_back(ans1);

				cout << "Answer 2:" << endl;
				getline(cin, ans2);
				Blank2->push_back(ans2);

				cout << "Answer 3:" << endl;
				getline(cin, ans3);
				Blank3->push_back(ans3);

				cout << "Answer 4:" << endl;
				getline(cin, ans4);
				Blank4->push_back(ans4);
			}
			system("pause");
			break;
		case 2:
			getline(cin, str1);
			cout << "Enter your questions " << endl;
			for (int i = 0; i < examnum; i++)
			{
				string str;
				string ans1;
				string ans2;
				cout << "Question" << i + 1 << ":" << endl;
				getline(cin, str);
				QuestionsTrueFalse->push_back(str);

				cout << "Answer True:" << endl;
				getline(cin, ans1);
				BlankT->push_back(ans1);

				cout << "Answer False:" << endl;
				getline(cin, ans2);
				BlankF->push_back(ans2);
			}
			system("pause");
			break;
		case 3:
			getline(cin, str1);
			cout << "Enter your questions " << endl;
			for (int i = 0; i < examnum; i++)
			{
				string str;
				string ans;
				cout << "Question" << i + 1 << ":" << endl;
				getline(cin, str);
				QuestionsAnatomical->push_back(str);

				cout << "Answer True:" << endl;
				getline(cin, ans);
				Answers->push_back(ans);
			}
			system("pause");
			break;

		}

	}

	
};

class ShowExam :public Exam
{
private:
	double Grade;
public:
	int QuestionMode;
	void showexam(int modequestion ,int examcounter)
	{
		system("cls");
		QuestionMode = modequestion;
		cout << "INFORMATION" << endl;
		ShowDate d;
		d.getdate(examcounter);
		Timer t;
		t.gettime(examcounter);
		Sleep(2000);
		cout << "-----------" << endl;
		system("cls");
		if (QuestionMode == 1)
		{
			cout << "Test" << endl;
			for (int i = 0; i < QuestionsTest->size(); i++)
			{
				cout << QuestionsTest->at(i) << "? :" << endl;
				
				cout << "1." << Blank1->at(i) << "\t";
				cout << "2." << Blank2->at(i) << "\t";
				cout << "3." << Blank3->at(i) << "\t";
				cout << "4." << Blank4->at(i) << "\t";
				int choose;
				cin >> choose;
				if (choose == 1)
				{
					RightAnswers->push_back(1);
				}
				else if (choose == 2 || choose == 3 || choose == 4)
				{
					WrongAnswers->push_back(0);
				}
			}
			cout << "Want to Review your Exam ?" << endl;
			cout << "1.Yes" << endl;
			cout << "2.No" << endl;
			int wre;
			cin >> wre;
			if (wre == 1)
			{
				for (int j = 0; j < QuestionsTest->size(); j++)
				{
					cout << QuestionsTest->at(j) << "? :" << endl;
					cout << "1." << Blank1->at(j) << "\t";
					cout << "2." << Blank2->at(j) << "\t";
					cout << "3." << Blank3->at(j) << "\t";
					cout << "4." << Blank4->at(j) << "\t";
				}
				cout << endl;
			}
			system("pause");
		}
		else if (QuestionMode == 2)
		{
			cout << "True False" << endl;
			for (int i = 0; i < QuestionsTrueFalse->size(); i++)
			{
				cout << QuestionsTrueFalse->at(i) << "? :" << endl;

		
				cout << "1." << BlankT->at(i) << "\t";
				cout << "2." << BlankF->at(i) << "\t";
				int choose;
				cin >> choose;
				if (choose == 1)
				{
					RightAnswers->push_back(1);
				}
				else if (choose == 2 )
				{
					WrongAnswers->push_back(0);
				}

			}
			cout << "Want to Review your Exam ?" << endl;
			cout << "1.Yes" << endl;
			cout << "2.No" << endl;
			int wre;
			cin >> wre;
			if (wre == 1)
			{
				for (int j = 0; j < QuestionsTrueFalse->size(); j++)
				{
					cout << QuestionsTrueFalse->at(j) << "? :" << endl;
					cout << "1." << BlankT->at(j) << "\t";
					cout << "2." << BlankF->at(j) << "\t";
				}
				cout << endl;
			}
			system("pause");
		}
		else if (QuestionMode == 3)
		{
			cout << "Anatomical" << endl;
			for (int i = 0; i < QuestionsAnatomical->size() ; i++)
			{
				cout << QuestionsAnatomical->at(i) << "? :" << endl;

				cout << "enter your answer :";
				string ANS;
				cin >> ANS;

				for (int j = 0; j < Answers->size(); j++)
				{
					if (ANS == Answers->at(j))
					{
						RightAnswers->push_back(1);
					}
				}

			}
			cout << "Want to Review your Exam ?" << endl;
			cout << "1.Yes" << endl;
			cout << "2.No" << endl;
			int wre;
			cin >> wre;
			if (wre == 1)
			{
				for (int j = 0; j < QuestionsAnatomical->size(); j++)
				{
					cout << QuestionsAnatomical->at(j) << "? :" << endl;
				}
			}
			system("pause");
		}

	}

	void Correction()
	{
		system("cls");
		if (QuestionMode == 1)
		{
			cout << "Test Correction" << endl;
			double right = RightAnswers->size();
			double wrong = WrongAnswers->size();

			cout << "Right Answers : " << right << endl;
			cout << "Wrong Answers : " << wrong << endl;

			Grade = right / (right + wrong);

			cout << "Exam Grade : " << Grade * 100 << "%" << endl;
			Resaults->push_back(Grade);
			system("pause");
		}
		else if (QuestionMode == 2)
		{
			cout << "True False Correction" << endl;
			double right = RightAnswers->size();
			double wrong = WrongAnswers->size();

			cout << "Right Answers : " << right << endl;
			cout << "Wrong Answers : " << wrong << endl;

			Grade = right / (right + wrong);

			cout << "Exam Grade : " << Grade * 100 << "%" << endl;

			system("pause");
		}
		else if (QuestionMode == 3)
		{
			cout << "Anatomical Correction" << endl;
			double right = RightAnswers->size();
			cout << "Right Answers : " << right << endl;

			Grade = right / QuestionsAnatomical->size();

			cout << "Exam Grade : " << Grade * 100 << "%" << endl;

			system("pause");
		}
	}

	void resault(int num)
	{
		cout << "Resault Of Exams" << endl;
		double sum=0;
		for (int i = 0; i < Resaults->size(); i++)
		{
			sum = sum + Resaults->at(i);
		}

		cout << "Number of Exams : " << num << endl;
		cout << "Final Grade : " << (sum / (double)num)*100<<"%" << endl;
		system("pause");
	}

};

class ExamManage : public Exam, public ShowExam
{
private:

public:
	void manageexam(int QuestionMode)
	{
		if (QuestionMode == 1)
		{
			cout << "Type Of Questions : Test" << endl;
			for (int i = 0; i < QuestionsTest->size(); i++)
			{
				cout << "Question : " << QuestionsTest->at(i) << " ? " << endl;
				cout << "1." << Blank1->at(i) << "\t";
				cout << "2." << Blank2->at(i) << "\t";
				cout << "3." << Blank3->at(i) << "\t";
				cout << "4." << Blank4->at(i) << "\t";
				cout << endl;
				cout << "Right Answer : " << Blank1->at(i) << endl;

			}
			system("pause");
		}
		else if (QuestionMode == 2)
		{
			cout << "Type Of Questions : True False" << endl;
			for (int i = 0; i < QuestionsTrueFalse->size(); i++)
			{
				cout << "Question : " << QuestionsTest->at(i) << " ? " << endl;
				cout << "1." << BlankT->at(i) << "\t";
				cout << "2." << BlankF->at(i) << "\t";
				cout << endl;
				cout << "Right Answer : " << BlankT->at(i) << endl;

			}
			system("pause");
		}
		else if (QuestionMode == 3)
		{
			cout << "Type Of Questions : Anatomical" << endl;
			for (int i = 0; i < QuestionsAnatomical->size(); i++)
			{
				cout << "Question : " << QuestionsAnatomical->at(i) << " ? " << endl;
				cout << endl;
				cout << "Right Answer : " << Answers->at(i) << endl;

			}
			system("pause");
		}
	}



};

void clean()
{
	//QuestionsTest->clear();
	//Blank1->clear();
	//Blank2->clear();
	//Blank3->clear();
	//Blank4->clear();
	//QuestionsTrueFalse->clear();
	//BlankT->clear();
	//BlankF->clear();
	//QuestionsAnatomical->clear();
	//Answers->clear();
	RightAnswers->clear();
	WrongAnswers->clear();
}
