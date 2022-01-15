/******************************************************
 @ function :   剑指 Offer 46. 把数字翻译成字符串	
 @ Access 	:	
 @ Parameter:	给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
 @ Returns  :	
 @ Remarks 	:   输入: 12258
				输出: 5
				解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 @ author   :   
******************************************************/

/*
动态规划解析：
https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/mian-shi-ti-46-ba-shu-zi-fan-yi-cheng-zi-fu-chua-6/
*/


#pragma once
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	int translateNum(int num) 
	{
		string str = to_string(num);
		int len = str.size();
		if (len < 2) return len;

		vector<int> dp(len + 1);

		dp[1] = 1;
		dp[0] = 1;

		for (int i = 2; i <= len; i++) 
		{
			if (str[i - 2] == '1' || (str[i - 2] == '2' && str[i - 1] <= '5')) dp[i] = dp[i - 2] + dp[i - 1];
			else dp[i] = dp[i - 1];
		}
		return dp[len];
	}
};