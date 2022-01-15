#pragma once
#include <unordered_map>
#include "stdafx.h"

class Solution
{
public:
	//使用摩尔投票法
	int majorityElement(std::vector<int> &nums)
	{
		int vote = 0;
		int x = 0;

		for (auto item : nums)
		{
			if (vote == 0)
			{
				x = item;
			}

			vote += ((x == item) ? 1 : -1);
		}

		return x;

	}

	int majorityElement2(std::vector<int> & nums)
	{
		std::unordered_map<int, int> map;
		int majority = 0;
		int count = 0;

		for (auto item : nums)
		{
			map[item]++;

			if (map[item] > count)
			{
				count = map[item];
				majority = item;
			}
		}

		return majority;
	}

};
