#pragma once
#include "stdafx.h"
#include "math.h"
class Solution
{
public:
	//ֻ�����һ�ʽ���
	int maxProfit(std::vector<int> &prices)
	{
		int res = 0, buy = INT_MAX;
		for (auto price : prices) {
			buy = min(buy, price);
			res = max(res, price - buy);
		}
		return res;
	}
};


