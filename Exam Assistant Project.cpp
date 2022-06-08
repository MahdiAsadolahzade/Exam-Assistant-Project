#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<windows.h>
#include"TimeClass.h"
#include"ExamClass.h"
#include"DateClass.h"

using namespace std;

vector <string> StudentFirstNames[100];
vector <string> StudentLastNames[100];
vector <string> StudentIDs[100];
vector <string> StudentUserNames[100];
vector <string> StudentPasswords[100];
static int SIcounter = 0;

vector <string> ManagerFirstNames[100];
vector <string> ManagerLastNames[100];
vector <string> ManagerUserNames[100];
vector <string> ManagerPasswords[100];
static int MIcounter = 0;

vector <Exam> Exams[20];
static int Ecounter = 0;

vector <string> AccessedStudents[100];
static int Acounter = 0;

void menu();
void StudentForm();
void ManagerForm();
int StudentCheck();
int ManagerCheck();
void AddStudenttoExam();
void DeleteStudentfromExam();

static int ExamCounter = 0;

int main()
{	
	while (1)
	{
		menu();
	}
	
}
void menu()
{
	system("cls");
	cout << "WELLCOME" << endl;
	int choice;
	cout << "1.Management Pannel" << endl;
	cout << "2.Student Pannel" << endl;
	cout << "3.EXIT" << endl;
	cin >> choice;
	switch (choice)
	{
		static int modequestion;
	case 1:
		system("cls");
		cout << "Management Pannel" << endl;
		int mchoice;
		cout << "1.Log in" << endl;
		cout << "2.Create Account" << endl;
		cout << "3.EXIT" << endl;
		cin >> mchoice;
		switch (mchoice)
		{
		case 1:
			system("cls");
			if (ManagerCheck())
			{
				int mechoice;
				cout << "1.Design Exam" << endl;
				cout << "2.Management Exam" << endl;
				cout << "3.Exam Case History" << endl;
				cout << "4.EXIT" << endl;
				cin >> mechoice;
				switch (mechoice)
				{
				case 1:
					system("cls");
					 Exam* e;
					 e = new Exam;
					cout << "Exam is Created !" << endl;
					cout << "How many questions you want to design ?" << endl;
					int questionnum;
					cin >> questionnum;
					e->setexamnum(questionnum);
					cout << "Mode of Questions:" << endl;
					cout << "1.Test" << endl;
					cout << "2.True/False" << endl;
					cout << "3.Anatomical" << endl;
					int mq;
					cin >> mq;
					modequestion = mq;
					e->setquestionmode(modequestion);
					e->setquestions();
					system("cls");
					cout << "Date of exam :" << endl;
					Date* d;
					d = new Date;
					int dy, dm, dd;
					cout << "year:";
					cin >> dy;

					cout << "month:";
					cin >> dm;

					cout << "day:";
					cin >> dd;

					d->setdate(dy, dm, dd);

					cout << endl;

					Time* t;
					t = new Time;
					int th, tm, ts;
					cout << "hour:";
					cin >> th;

					cout << "minute:";
					cin >> tm;

					cout << "second:";
					cin >> ts;

					t->settime(th, tm, ts);

					AddStudenttoExam();
					DeleteStudentfromExam();
					ExamCounter++;
					break;
				case 2:
					ExamManage em;
					em.manageexam(modequestion);

					break;
				case 3:
					system("cls");
					cout << "Case History" << endl;
					
					for (int i = 0; i < ExamCounter; i++)
					{
						cout << "-----------" << endl;
						cout << "Exam " << i+1 << ":" << endl;
						cout << "Date : ";
						ShowDate sd;
						sd.getdate(i+1);
						cout << "Time : ";
						Timer td;
						td.gettime(i+1);
					}

					system("pause");
					break;
				case 4:
					break;
				}
			}
			else
			{
				exit(0);
			}
			break;
		case 2:
			ManagerForm();
			break;
		case 3:
			exit(0);
			break;
		}
		break;
	case 2:
		system("cls");
		cout << "Student Pannel" << endl;
		int schoice;
		cout << "1.Log in" << endl;
		cout << "2.Create Account" << endl;
		cout << "3.EXIT" << endl;
		cin >>schoice;
		switch(schoice)
		{
		case 1:
			if (StudentCheck())
			{
				system("cls");
				cout << "Recent Exams" << endl;
				string strid;
				cout << "Enter your ID:";
				cin >> strid;
				bool flag = false;
				for (int i = 0; i < AccessedStudents->size(); i++)
				{
					if (strid == AccessedStudents->at(i))
					{
						flag = true;
					}
				}
				if (flag)
				{
					ShowExam* se;
					se = new ShowExam;
					se->showexam(modequestion ,ExamCounter);
					cout << "Show Resault" << endl;

					se->Correction();
					se->resault(ExamCounter);
					clean();
				}
				else
				{
					cout << "No manager Accessed you in Exam" << endl;
					system("pause");
				}
				
			}
			else
			{
				break;
			}
			break;
		case 2:
			StudentForm();
			break;
		case 3:
			exit(0);
			break;
		}
		break;

	case 3:
		exit(0);
		break;

	}
}
void StudentForm()
{
	string StudentFirstName;
	string StudentLastName;
	string StudentID;
	string StudentUserName;
	string StudentPassword;

	SIcounter++;

	cout << " Students Regestring Form " << endl;

	cout << "Enter Your UserName :";
	cin >> StudentUserName;
	StudentUserNames->push_back(StudentUserName);
	bool temperer = false;
	int count = 0;
	for (int i = 0; i < SIcounter; i++)
	{
		if (StudentUserName == StudentUserNames->at(i))
		{
			count++;
		}
	}
	if (count == 2)
	{
		cout << "This user name is already taken" << endl;
		temperer = true;
		StudentUserNames->pop_back();
		system("cls");
	}

	if (temperer == false)
	{

		cout << "Enter Your FirstName :";
		cin >> StudentFirstName;
		StudentFirstNames->push_back(StudentFirstName);

		cout << "Enter Your LastName :";
		cin >> StudentLastName;
		StudentLastNames->push_back(StudentLastName);

		cout << "Enter Your ID :";
		cin >> StudentID;
		StudentIDs->push_back(StudentID);

		cout << "Enter Your Password :";
		cin >> StudentPassword;
		StudentPasswords->push_back(StudentPassword);
	}

}
void ManagerForm()
{
	string ManagerFirstName;
	string ManagerLastName;
	string ManagerUserName;
	string ManagerPassword;

	MIcounter++;

	cout << " Managers Regestring Form " << endl;

	cout << "Enter Your UserName :";
	cin >> ManagerUserName;
	ManagerUserNames->push_back(ManagerUserName);
	bool temperer = false;
	int count = 0;
	for (int i = 0; i < MIcounter; i++)
	{
		if (ManagerUserName == ManagerUserNames->at(i))
		{
			count++;
		}
	}
	if (count == 2)
	{
		cout << "This user name is already taken" << endl;
		temperer = true;
		ManagerUserNames->pop_back();
		system("cls");
	}

	if (temperer == false)
	{

		cout << "Enter Your FirstName :";
		cin >> ManagerFirstName;
		ManagerFirstNames->push_back(ManagerFirstName);

		cout << "Enter Your LastName :";
		cin >> ManagerLastName;
		ManagerLastNames->push_back(ManagerLastName);

		cout << "Enter Your Password :";
		cin >> ManagerPassword;
		ManagerPasswords->push_back(ManagerPassword);
	}
}
int StudentCheck()
{
	cout << "Enter your UserName:";
	string struser;
	cin >> struser;

	cout << "Enter your Password:";
	string strpass;
	cin >> strpass;

	bool userflag = false;
	bool passflag = false;
	int temp;

	for (int i = 0; i < SIcounter; i++)
	{
		if (strpass == StudentUserNames->at(i) && strpass == StudentPasswords->at(i))
		{
			userflag = true;
			passflag = true;
			temp = i;
		}
	}

	if (userflag == true && passflag == true)
	{
		cout << "Wellcome Back " << StudentFirstNames->at(temp) << endl;
		system("pause");
		return 1;
	}
	else
	{
		cout << "Your UserName or Password isn't Correct , Try Again or Register another one." << endl;
		system("pause");
		return 0;
	}
		
}
int ManagerCheck()
{
	cout << "Enter your UserName:";
	string struser;
	cin >> struser;

	cout << "Enter your Password:";
	string strpass;
	cin >> strpass;

	bool userflag = false;
	bool passflag = false;
	int temp;

	for (int i = 0; i < MIcounter; i++)
	{
		if (struser == ManagerUserNames->at(i) && strpass == ManagerPasswords->at(i))
		{
			userflag = true;
			passflag = true;
			temp = i;
		}
	}

	if (userflag == true && passflag == true)
	{
		cout << "Wellcome Back " << ManagerFirstNames->at(temp) << endl;
		system("pause");
		return 1;
	}
	else
	{
		cout << "Your UserName or Password isn't Correct , Try Again or Register another one." << endl;
		system("pause");
		return 0;
	}
}
void AddStudenttoExam()
{
	cout << "How many Student you want to add this exam ??" << endl;
	int snum;
	cin >> snum;
	for (int i = 0; i < snum; i++)
	{
		string strfname;
		string strlname;
		string strid;

		cout << "Student Name:";
		cin >> strfname;
	
		cout << "Student LastName:";
		cin >> strlname;

		cout << "Student ID:";
		cin >> strid;
		bool flag = false;
		int temp;
		for (int j = 0; j < SIcounter; j++)
		{
			if (strfname == StudentFirstNames->at(j) && strlname == StudentLastNames->at(j) && strid == StudentIDs->at(j))
			{
				flag = true;
				temp = j;
			}
		}

		if (flag==true)
		{
			AccessedStudents->push_back(StudentIDs->at(temp));
			Acounter++;
		}
		else
		{
			AccessedStudents->push_back(strid);
			StudentFirstNames->push_back(strfname);
			StudentLastNames->push_back(strlname);
			StudentIDs->push_back(strid);
			StudentUserNames->push_back(strid);
			StudentPasswords->push_back(strid);
			Acounter++;
		}
		SIcounter++;
		cout << endl;
	}
}
void DeleteStudentfromExam()
{
	cout << "You have " << AccessedStudents->size() << " Students in this Exam" << endl;
	cout << "How many Student you want to delete from this exam ??" << endl;
	int snum;
	cin >> snum;
	
	if (snum >= 0 && snum <= AccessedStudents->size())
	{
		for (int i = 0; i < snum; i++)
		{
			string strid;

			cout << "Student ID:";
			cin >> strid;
			int temp;
			for (int j = 0; j < SIcounter; j++)
			{
				if (strid == StudentIDs->at(j))
				{
					temp = j;
					AccessedStudents->erase( AccessedStudents->begin() + temp);
					Acounter--;
				}
			}

			cout << endl;
		}
	}
	else
	{
		cout << "You havent that much student to delete !" << endl;
	}

}