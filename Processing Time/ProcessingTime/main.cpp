// Raymond McCann
// CSC 205-51
// Assignment: 8
// Purpose: Calculate next processing time.
#include "TimeType.h";
#include <iostream>
using namespace std;

int main()
{
	char again = 'y';
	do
	{
		int hr, min, sec;
		TimeType processTime1, processType2, processType3;

		cout << "Enter the hour: ";
		cin >> hr;

		cout << "Enter the minute: ";
		cin >> min;

		cout << "Enter the second: ";
		cin >> sec;

		system("CLS");

		// Processing the first set of time will increase the next process time.
		processTime1.SetTime(hr, min, sec);
		cout << "First Processing Time: ";
		processTime1.Display();

		processType2 = processTime1.NextProcTime();
		cout << "Second Processing Time: ";
		processType2.Display();

		processType3 = processType2.NextProcTime();
		cout << "Third Processing Time: ";
		processType3.Display();
	} while ((again == 'y'));

	return 0;
}
