//
//	Author: Ray McCann
//
//	Description:
//
//		Binary search which removes duplicate numbers from a whitelisted file.
//
#include "FileIO.h"
#include "BinarySearch.h";
#include <iterator>
#include <cctype>

int main()
{
	FileIO file;

	// Check if data file is there, if not, create it.
	if (!file.exists(file.file.c_str()))
	{
		file.generateDataSet();
	}

	std::vector<int> array = file.readFileToArray();
	std::vector<int> newArray;

	int lastNumber = -1; // Last number added.

	// Remove duplicates from array.
	for (int i=0; i < array.size(); i++)
	{
		if (lastNumber != array.at(i)) {
			newArray.push_back(array.at(i));
		}

		lastNumber = array.at(i);
	}

	BinarySearch BinarySearch(newArray);

	char searchAgain = 'y';
	int searchNumber;


	while (searchAgain != 'n') {
		system("CLS");

		std::copy(newArray.begin(), newArray.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << "\n----------------------------------------------------------------------" << std::endl;

		std::cout << "\nWhich number would you like to find? ";
		std::cin >> searchNumber;

		// Program crashes if we search by 0.
		if (searchNumber == 0)
		{
			continue;
		}

		const int position = BinarySearch.search(searchNumber);

		if (position != -1)
		{
			std::cout << "Position: " << position << " (" << newArray.at(position) << ")" << std::endl;
		}
		else
		{
			std::cout << "Value not found in array!" << std::endl;
		}

		std::cout << "Do you want to try another search? (Y/N) ";
		std::cin >> searchAgain;

		// Convert the char to lowercase.
		searchAgain = std::tolower(searchAgain);

		if (searchAgain == 'n')
			exit(0);
	}

	system("PAUSE");
	return 0;
}
