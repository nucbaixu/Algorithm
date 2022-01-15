#pragma once
#include "stdafx.h"
#include <unordered_map>
class Solution
{
public:
	bool exitDumplicatenumber(std::vector<int> & nums)
	{
		const rsize_t iveclen = nums.size();
		std::unordered_map<int, int> map;

		if (iveclen < 1)
		{
			return false;
		}

		for (size_t i = 0; i < iveclen; i++)
		{
			if (map.find(nums[i]) != map.end())
			{
				return true;
			}

			map[nums[i]] = i;
		}
		
		return false;
	}
};
