#pragma once
#include "string"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class Solution
{
public:
	string minNumber(vector<int> & nums);
private:
	void quick_sort(std::vector<string> &src, int l, int r)
	{
		if (l >= r) return;
		
		int i = l, j = r;
		while (i < j)
		{
			while (src[j] + src[l] >= src[l] + src[j] && i < j)
			{
				j--;
			}

			while (src[i] + src[l] >= src[l] + src[i] && i < j)
			{
				i++;
			}
			swap(src[i],src[j]);
		}

		quick_sort(src, l, i - 1);
		quick_sort(src, i + 1, r);
	}
};

string Solution::minNumber(vector<int>& nums)
{
	if (nums.empty()) return "";
	const unsigned long long size = nums.size();

	vector<string> str;
	str.reserve(size);

	for (const auto item : nums)
	{
		str.emplace_back(std::to_string(item));
	}

	quick_sort(str,0, size - 1);

	string res;
	for (auto item : str)
	{
		res.append(item);
	}

		
	
	return res;
}
