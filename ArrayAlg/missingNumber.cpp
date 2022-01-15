#pragma once
#include <vector>
using namespace std;
class Solution
{
public:
	int missdingNumber(std::vector<int> &nums)
	{
		int left = 0;
		int right = nums.size();
		int mid = 0;

		while (left < right)
		{
			mid = (left + right) >> 1;

			if (nums[mid] > mid)
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}

		return left;
	}
};
