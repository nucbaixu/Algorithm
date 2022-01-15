#pragma once
#include<vector>

class Solution
{
public:

	//ɾ�����������е��ظ�Ԫ�أ�ȥ�غ�����鳤��
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

