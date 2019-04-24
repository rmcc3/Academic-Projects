// Raymond McCann
// CSC 205-51
// Assignment: 8
// Purpose: Calculate next processing time.
#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class TimeType
{
private:
	int hr;
	int min;
	int sec;

public:
	TimeType(); //Constructor to set hr = 0, min = 0, sec = 0
	void SetTime(int, int, int); //Time is set according to the incoming parameter
	TimeType NextProcTime(); //Time is increased by 30 minutes to get next processing time
	void Display() const; //Displayed in the form of hh:mm:ss
};
