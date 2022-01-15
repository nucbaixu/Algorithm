#pragma once
#include "vector"
//Given a sorted array of integers, find the starting and ending position of a given target value.
//Your algorithm’s runtime complexity must be in the order of O(log n).
//If the target is not found in the array, return[-1, -1].
//For example, Given[5, 7, 7, 8, 8, 10] and target value 8, return[3, 4].

class Slution
{
public:
	std::vector<int> searchRange(std::vector<int>array,int target);


private:

};

template<typename ForwardIterator, typename T>
ForwardIterator lower_bound(ForwardIterator first,
	ForwardIterator last, T value) 
{
	while (first != last)
	{
		auto mid = next(first, distance(first, last) / 2);
		if (value > *mid) first = ++mid;
		else last = mid;
	}
	return first;
}

template<typename ForwardIterator, typename T>
ForwardIterator upper_bound(ForwardIterator first,
	ForwardIterator last, T value) 
{
	while (first != last) 
	{
		//next 返回后面第N的迭代位置
		auto mid = next(first, distance(first, last) / 2);
		if (value >= *mid) first = ++mid; // 与 lower_bound 仅此不同
		else last = mid;
	}
	return first;
}

std::vector<int> Slution::searchRange(std::vector<int>array, int target)
{
	auto a0 = array.begin();
	auto lower = lower_bound(array.begin(), array.end(), target);
	auto uppper = upper_bound(lower, array.end(), target);
	if (lower == array.end() || *lower != target)
		return std::vector<int> { -1, -1 };
	else
		return std::vector<int> { static_cast<int>(distance(a0, lower)), static_cast<int>(distance(a0,prev(uppper)))};

	
}