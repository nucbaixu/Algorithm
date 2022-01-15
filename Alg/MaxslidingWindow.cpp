/******************************************************
 @ function : 	59 - 滑动窗口最大值
 @ Access 	:	
 @ Parameter:	
 @ Returns  :	
 @ Remarks 	:   
 @ author   :   
******************************************************/
#pragma once
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	vector<int> maxSliddingWindwo(vector<int> &nums, int k)
	{
		int len = nums.size();
		if (len < k || k < 0) return {};

		vector<int> ans;

		std::priority_queue<std::pair<int, int>> que;

		for (int i = 0 ; i < k; i++)
		{
			que.emplace(nums[i],i);
		}

		ans.push_back(que.top().first);

		for (int i = k; i < len;i++)
		{
			que.emplace(nums[i], i);

			while (que.top().second <= i-k)
			{
				que.pop();
			}

			ans.push_back(que.top().first);
		}
		
		return ans;
	}
};
