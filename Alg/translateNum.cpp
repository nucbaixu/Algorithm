/******************************************************
 @ function :   ��ָ Offer 46. �����ַ�����ַ���	
 @ Access 	:	
 @ Parameter:	����һ�����֣����ǰ������¹����������Ϊ�ַ�����0 ����� ��a�� ��1 ����� ��b����������11 ����� ��l����������25 ����� ��z����һ�����ֿ����ж�����롣����ʵ��һ����������������һ�������ж����ֲ�ͬ�ķ��뷽����
 @ Returns  :	
 @ Remarks 	:   ����: 12258
				���: 5
				����: 12258��5�ֲ�ͬ�ķ��룬�ֱ���"bccfi", "bwfi", "bczi", "mcfi"��"mzi"
 @ author   :   
******************************************************/

/*
��̬�滮������
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