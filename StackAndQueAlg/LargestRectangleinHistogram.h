//@ description:
//Given n non-negative integers representing the histogram°Øs bar height where the width of each bar is 1,
//find the area of largest rectangle in the histogram.
#pragma once
#include "string"
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class slution
{
public:
	int largestRectangleArea(vector<int> &height);

private:

};

int slution::largestRectangleArea(vector<int> &height)
{
	stack<int> s;  //¥Ê∑≈Œª÷√
	height.push_back(0);

	int result = 0;

	for (int i = 0; i < height.size(); i++)
	{
		if (height[i] > height[s.top()] || s.empty())
		{
			s.push(i);
		}
		else
		{
			int tmp = s.top();
			s.pop();
			result = max(result,height[tmp] * (s.empty() ? i : i - s.top() - 1));
		}
	}

	return result;
}