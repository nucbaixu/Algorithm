#pragma once
#include "string"
#include <stack>
#include <algorithm>
using namespace std;
// @ description £ºGiven a string containing just the characters ¡¯(¡¯ and ¡¯)¡¯, find the length of the longest valid
//                 (well- formed) parentheses substring

// @ example      :For ¡±(()¡±, the longest valid parentheses substring is ¡±()¡±, which has length = 2.
//                :Another example is ¡±)()())¡±, where the longest valid parentheses substring is ¡±()()¡±, which has
//                 length = 4

class Slution
{

public:
	int longestValidParentheses(const std::string &s);
private:

};

int Slution::longestValidParentheses(const std::string &s)
{
	std::stack<int> stk;   // keep track of the positions of non-matching '('s
	size_t max_len = 0;
	size_t last = -1;         // the position of the last ')'

	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			stk.emplace(i);
		}
		else
		{
			if (stk.empty())
			{
				//no match 
				last = i;
			}
			else
			{
				//find a match pair
				stk.pop();

				if (stk.empty())
				{
					max_len = max(max_len, i - last);
				}
				else
				{
					max_len = max(max_len,i - stk.top());
				}
			}
		}
	}

	return max_len;
}