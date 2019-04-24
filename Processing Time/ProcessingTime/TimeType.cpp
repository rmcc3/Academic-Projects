// Raymond McCann
// CSC 205-51
// Assignment: 8
// Purpose: Calculate next processing time.
#include "TimeType.h"

TimeType::TimeType()
{
	this->hr = 0;
	this->min = 0;
	this->sec = 0;
}

void TimeType::SetTime(int hour, int minute, int second)
{
	if ((hour >= 0 && hour < 24)) this->hr = hour;
	else this->hr = 0;

	if ((minute >= 0 && minute < 60)) this->min = minute;
	else this->min = 0;

	if ((second >= 0 && second < 60)) this->sec = second;
	else this->sec = 0;
}

TimeType TimeType::NextProcTime()
{
	if ((this->min + 30) > 59)
	{
		this->min = ((this->min % 30));
		this->hr += 1;

		if (this->hr > 23) this->hr = 0; // Prevent the hour from going higher than it should.
	}
	else
	{
		this->min += 30;
	}

	// Creating a new TimeType to return with new time.
	TimeType time;
	time.SetTime(this->hr, this->min, this->sec);

	return time;
}

void TimeType::Display() const
{
	printf("%02i:%02i:%02i\n", this->hr, this->min, this->sec);
}

