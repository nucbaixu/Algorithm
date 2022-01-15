#pragma once
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;


class Solution
{
public:
	//使用对称遍历，每个Bi本质是是左侧Ai的乘积和右侧Ai的乘积
	vector<int> constructArr(vector<int> & nums)
	{
		int n = nums.size();

		vector<int> res(n, 1);
		int left = 1, right = 1;
		for (int i = 0 ; i < n;i++)
		{
			res[i] = left;
			left *= nums[i];
		}

		for (int i = n - 1; i >=0;i--)
		{
			res[i] *= right ;
			right *= nums[i];
		}

		return res;
	}

private:

};

