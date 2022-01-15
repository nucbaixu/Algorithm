/******************************************************
 @ function : 	队列最大值
 @ Access 	:	
 @ Parameter:	
 @ Returns  :	
 @ Remarks 	:   
 @ author   :   
******************************************************/
#pragma once
#include "string"
#include <stack>
#include <vector>
using namespace std;
class MaxQueue
{
public:

	MaxQueue(){}

	int max_value()
	{
		return maxque.empty() ? -1 : maxque.front();
	}

	void push_back(int val)
	{
		que.push_back(val);

		while (!maxque.empty() && maxque.back() < val)
		{
			maxque.pop_back();
		}

		maxque.push_back(val);
	}

	int pop()
	{
		if (que.empty())
		{
			return -1;
		}

		int val = que.front();
		if (val == maxque.front())
		{
			maxque.pop_front();
		}

		que.pop_front();

		return val;
	}
	

private:
	std::deque<int> que;
	std::deque<int> maxque;
};
