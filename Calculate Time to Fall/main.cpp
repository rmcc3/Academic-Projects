// Raymond McCann
// CSC 205-51
// Assignment: 4
// Purpose: Calculate falling distance from time.

#include <iostream>
#include <iomanip>

using namespace std;

// Constant variables
const double GRAVITY = 9.8;

// Function prototypes
double getData(double); // Gets the user input.
double fallingDistance(double); // Distance is to fall.
void display(double, double); // Displays calculated outputs.

int main()
{
	do
	{
		char again = 'N';
		double time = 0, distance = 0;

		time = getData(time);
		distance = fallingDistance(time);
		display(time, distance);

		// Check if the program should loop through it again.
		cout << "Do you like to continue (y/n) ? ";
		cin >> again;
		again = toupper(again);

		while ((again != 'Y') && (again != 'N'))
		{
			cout << "ERROR: Enter Y/N :";
			cin >> again;

			again = toupper(again);
		}

		if (again == 'Y')
		{
			system("CLS");
			continue;
		}
		else
		{
			break;
		}

	} while (true);

	return 0;
}

// This function gets the total time to fall.
double getData(double time)
{
	cout << "Enter time (Seconds): ";
	cin >> time;

	return time;
}

// Calculate the falling distance.
double fallingDistance(double time)
{
	return 0.5 * (GRAVITY * pow(time, 2));
}

// Display the calculated outputs.
void display(double time, double distance)
{
	system("CLS");
	cout << fixed << showpoint << setprecision(1);
	cout << "Falling time: " << time << " seconds" << endl;
	cout << "Falling distance: " << distance << " meters\n" << endl;
}