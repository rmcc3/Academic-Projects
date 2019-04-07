// Raymond McCann
// CSC 205-51
// Assignment: 3
// Purpose: Calculate shipping to ship a package.
#include <iostream>
#include <iomanip>

using namespace std;

int main()  // NOLINT(bugprone-exception-escape)
{
	bool goodPackage; // Allows program to calculate cost if package meets requirements.
	char again; // Determines if program will continue running. Held Data: Y or N
	double weight = 0, // Weight of the package to be shipped, in Kg.
		   shippingCharge = 0; // Total cost to ship package.
	int distance = 0;  // Distance the package needs to be shipped, in miles.

	do 
	{
		cout << "Weight of the package in kilograms (max 20 Kg): ";
		cin >> weight;

		cout << "Distance the package is to be shipped (min. 10 Mi, max 3000 Mi): ";
		cin >> distance;
		system("cls");

		// Validate if weight is without shipment limits.
		if (weight <= 0) 
		{
			cout << "Weight must be greater than 0 Kg.\n" << endl;
			goodPackage = false;
		} else if (weight > 20.0)
		{
			cout << "We do not ship packages that weight more than 20 Kg.\n" << endl;
			goodPackage = false;
		} else if (distance < 10.0 || distance > 3000.0)
		{
			cout << "We do not ship less than 10 miles or more than 3000 miles.\n" << endl;
			goodPackage = false;
		} else
		{
			goodPackage = true;
		}

		// Calculate shipping costs if everything checks out.
		if (goodPackage)
		{
			if (weight < 2.0)
			{
				shippingCharge = 1.10 + (int((distance - 1) / 500) * 1.10);
			} else if (weight >= 2.0 && weight <= 6.0)
			{
				shippingCharge = 2.35 + (int((distance - 1) / 500) * 2.35);
			} else if (weight > 6.0 && weight < 10.0)
			{
				shippingCharge = 3.70 + (int((distance - 1) / 500) * 3.70);
			} else if (weight > 10.0 && weight <= 20.0)
			{
				shippingCharge = 4.80 + (int((distance - 1) / 500) * 4.80);
			}

			// There is an issue where precision will add extra 0's to the weight if there is more than one run.
			// This is an attempt to correct that issue as other methods are not working.
			if (fmod(weight, 1.0))
			{
				cout << setprecision(1) << fixed;
			} else
			{
				cout << setprecision(0);
			}

			cout << "The weight of the package is " << weight << " kg. The shipping distance is " << distance << " miles, ";
			cout << "and the shipping charge is $" << fixed << setprecision(2) << shippingCharge << ".\n" << endl; 
		}

		// Ask the users if they wish to process another set.
		cout << "Do you want to process another set? (Y/N): ";
		cin >> again;

		again = toupper(again); // Correct the char to uppercase.

		// Input must be Y/N, if not, put the user in an error trap.
		while ((again != 'Y') && (again != 'N'))
		{
			cout << "ERROR: Enter Y/N :";
			cin >> again;
			again = toupper(again);
		}

		// Program will end if user enters N.
		if (toupper(again) == 'N')
			break;

		
	} while (true);

	return 0;
}

