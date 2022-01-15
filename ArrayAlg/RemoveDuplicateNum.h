#pragma once
#include<vector>

class Solution
{
public:

	//删除有序数组中的重复元素，去重后的数组长度
	int RemoveDumplicates(std::vector<int>& nums)
	{
		const int iArraylen = nums.size();

		if (iArraylen <= 1)
		{
			return 1;
		}

		
		int index = 0;

		for (size_t i = 1; i < iArraylen; i++)
		{
			if (!(nums[index] | nums[i]))
			{
				nums[++index] = nums[i];
			}
		}

		return index + 1;
	}
};

