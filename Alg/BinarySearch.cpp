#include "stdafx.h"
#include "stdio.h"
#include <algorithm>
#include <vector>

using namespace std;

// ·ÇµÝ¹é
int BinarySearch(vector<int> v, int value)
{
	if (v.size() <= 0)
		return -1;

	int low = 0;
	int high = v.size() - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (v[mid] == value)
			return mid;
		else if (v[mid] > value)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}

// µÝ¹é
int BinarySearch2(vector<int> v, int value, int low, int high)
{
	if (low > high)
		return -1;
	int mid = low + (high - low) / 2;
	if (v[mid] == value)
		return mid;
	else if (v[mid] > value)
		return BinarySearch2(v, value, low, mid - 1);
	else
		return BinarySearch2(v, value, mid + 1, high);
}