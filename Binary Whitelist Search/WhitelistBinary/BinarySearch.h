#pragma once
#include <vector>

//
//	Description:
//		Binary search header file.
//

class BinarySearch
{
protected:
	std::vector<size_t> bin_array;
	size_t min, max;
public:
	BinarySearch(std::vector<int> array);
	int search(size_t value) const;
};

inline BinarySearch::BinarySearch(std::vector<int> array)
{
	for (int i : array)
	{
		bin_array.push_back(i);
	}

	min = 0;
	max = bin_array.size();
}

inline int BinarySearch::search(size_t value) const
{
	size_t low = this->min;
	size_t high = this->max;

	while (low <= high)
	{
		const size_t middle = low + (high - low) / 2;

		if (value < this->bin_array[middle])
		{
			high = middle - 1;
		} else if(value > this->bin_array[middle])
		{
			low = middle + 1;
		} else
		{
			return middle;
		}
	}

	return -1;
}