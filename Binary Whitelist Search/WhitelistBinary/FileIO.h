#pragma once
//
//	Description:
//		File IO.
//

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>

class FileIO
{
public:
	std::string file;
	FileIO();
	FileIO(std::string file);
	void generateDataSet() const;
	static bool exists(const char *file);
	std::vector<int> readFileToArray() const;
	static std::string writeFile();
};

// Constructors
inline FileIO::FileIO()
{
	file = "./dataset.txt";
}

inline FileIO::FileIO(std::string filePath)
{
	file = filePath;
}

// Check if file exists.
inline bool FileIO::exists(const char *file)
{
	std::ifstream infile(file);

	return infile.good();
}

inline std::vector<int> FileIO::readFileToArray() const
{
	std::vector<int> array;
	if (FileIO::exists(this->file.c_str()))
	{
		std::ifstream dataFile;
		std::string line;

		dataFile.open(this->file);

		if (dataFile.is_open())
		{
			while (std::getline(dataFile, line))
			{
				try
				{
					array.push_back(stoi(line));
				}
				catch (int e)
				{
					// Handle error.
				}
			}
		}

	}

	// Sort the array
	sort(array.begin(), array.end());

	return array;
}

inline std::string FileIO::writeFile()
{
	return std::string();
}

inline void FileIO::generateDataSet() const
{
	srand(time(nullptr));

	std::ofstream dataFile;
	std::string fileData;

	dataFile.open(this->file);

	for(int i= 0; i < 101; i++)
	{

		fileData += std::to_string(rand() % 100 + 1) + "\n";
	}

	dataFile << fileData;
	dataFile.close();
}
