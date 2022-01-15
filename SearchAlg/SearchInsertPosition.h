//Given a sorted array and a target value, return the index if the target is found.If not, 
//return the index where it would be if it were inserted in order.
//You may assume no duplicates in the array.

//[1, 3, 5, 6], 5 ¡ú 2   
//[1, 3, 5, 6], 2 ¡ú 1
//[1, 3, 5, 6], 7 ¡ú 4
//[1, 3, 5, 6], 0 ¡ú 0

#pragma once
#include "vector"

class CSearchInsertPosition
{
public:
	int searchInsert(std::vector<int>array,int tartget);
private:
};


template <typename ForwardIt,typename T>
ForwardIt Lower_bound(ForwardIt _first, ForwardIt _last,T _val)
{
	while (_first != _last)
	{
		auto mid = distance(_first, (_first + _last) / 2);
		if (*mid < _val) _first = mid;
		else
			_last = mid;
	}
	return _first;
}

int CSearchInsertPosition::searchInsert(std::vector<int>array, int tartget)
{
	return distance(array.begin(), Lower_bound(array.begin(), array.end(), tartget));
}

