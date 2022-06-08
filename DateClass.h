#pragma once
#include<iostream>
#include<windows.h>
#include<string>
#include<time.h>
#include<ctime>

using namespace std;

vector <int> year;
vector <int> month;
vector <int> day;
static int RoundD = 0;

class Date
{
private:
public:
	void setdate(int y , int m , int d)
	{
		year.push_back(y);
		month.push_back(m);
		day.push_back(d);
		RoundD++;
	}
};

class ShowDate : public Date
{
private:

public:
	void getdate(int Round)
	{
		cout << year.at(Round-1) << "/" << month.at(Round-1) << "/" << day.at(Round-1) << endl;
	}
};
