/******************************************************
 @ function : 	剑指 Offer 57 - II. 和为s的连续正数序列
 @ Access 	:	
 @ Parameter:	输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
				序列内的数字由小到大排列，不同序列按照首个数字从小到大排列
 @ author   :   
******************************************************/
#pragma once
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

//使用算法计算
//https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/jian-zhi-offer-57-ii-he-wei-s-de-lian-xu-t85z/
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int i = 1;
		double j = 2.0;
		vector<vector<int>> res;
		while (i < j) {
			j = (-1 + sqrt(1 + 4 * (2 * target + (long)i * i - i))) / 2;
			if (i < j && j == (int)j) {
				vector<int> ans;
				for (int k = i; k <= (int)j; k++)
					ans.push_back(k);
				res.push_back(ans);
			}
			i++;
		}
		return res;
	}
};

//使用滑动窗：双指针

class Solution2 {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		
		int i = 1;
		int j = 2;
		int sum = 3;
		vector<vector<int>> res;

		while (i < j)
		{
			if (sum == target)
			{
				vector<int> ans;
				for (int k = i; k <= j; k++)
					ans.push_back(k);
				res.push_back(ans);
			}

			if (sum >= target)
			{
				sum -= i;
				i = i + 1;
			}
			else
			{
				j = j + 1;
				sum += j;
			}
		}

		return res;
	}
};
