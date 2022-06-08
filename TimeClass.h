#pragma once

#include<iostream>
#include<windows.h>
#include<ctime>
#include<time.h>

using namespace std;

vector <int> hour;
vector <int> minute;
vector <int> second;
static int RoundT = 0;
bool Wait(const unsigned long& Time);
void sleep(long wait)
{
	clock_t start = clock();
	while (clock() - start < wait);
}

class Time
{
private:
    int time;
public:
	void settime(int h , int m , int s)
	{
		hour.push_back(h);
        minute.push_back(m);
        second.push_back(s);
        RoundT++;
	}

	
};

class Timer : public Time
{
private:

public:
   
    void gettime(int Round)
    {
        cout << hour.at(Round-1) << ":" << minute.at(Round - 1) << ":" << second.at(Round - 1) << endl;
    }
    
    void settimer(int Round)
    {
        int counter = hour.at(Round - 1) * 3600 + minute.at(Round - 1) * 60 + second.at(Round - 1);
        
        if (!Wait(1000));
        while (counter >= 1)
        {
            cout << "Time remaining: " << counter ;
            if (!Wait(1000));
            counter--;
        }
    }
    

};

bool Wait(const unsigned long& Time)
{
    clock_t Tick = clock_t(float(clock()) / float(CLOCKS_PER_SEC) * 1000.f);
    if (Tick < 0) // if clock() fails, it returns -1
        return 0;
    clock_t Now = clock_t(float(clock()) / float(CLOCKS_PER_SEC) * 1000.f);
    if (Now < 0)
        return 0;
    while ((Now - Tick) < Time)
    {
        Now = clock_t(float(clock()) / float(CLOCKS_PER_SEC) * 1000.f);
        if (Now < 0)
            return 0;
    }
    return 1;
}




