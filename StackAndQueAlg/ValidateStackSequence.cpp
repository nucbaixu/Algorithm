//给定入栈顺序，判断出栈顺序是否正确
#pragma once
#include "string"
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
	bool validateStackSequences(vector<int> & pushed,vector<int> &poped)
	{
		stack<int> ha;
		int h = 0;
		for (auto i :pushed)
		{
			ha.push(i);

			while (!ha.empty()&&poped[h] == ha.top())
			{
				ha.pop();
				h++;
			}
		}

		return ha.empty();
	}

private:

};
