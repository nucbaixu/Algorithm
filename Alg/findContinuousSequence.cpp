/******************************************************
 @ function : 	��ָ Offer 57 - II. ��Ϊs��������������
 @ Access 	:	
 @ Parameter:	����һ�������� target ��������к�Ϊ target ���������������У����ٺ�������������
				�����ڵ�������С�������У���ͬ���а����׸����ִ�С��������
 @ author   :   
******************************************************/
#pragma once
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

//ʹ���㷨����
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

//ʹ�û�������˫ָ��

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
