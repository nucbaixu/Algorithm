//The count - and-say sequence is the sequence of integers beginning as follows :
//1, 11, 21, 1211, 111221, ...
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2", then "one 1" or 1211.
//Given an integer n, generate the nth sequence.
//Note : The sequence of integers will be represented as a string.

//当n = 1时：输出1；
//当n = 2时，解释1，1读作1个 ，表示为11；
//当n = 3时，解释上一个11，读作2个1，表示为21；（注意相同数字的描述）
//当n = 4时，解释上一个21，读作1个2，一个1，表示为1211；
//当n = 5时，解释上一个1211，读作1个1，1个2，2个1，表示为111221；
//当n = 6时，解释上一个111221，读作3个1，2个2，1个1，表示为312211

#pragma once
#include "string"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <functional>

using namespace std;

class CountandSay
{
public:
	string countAndSay(int n)
	{
		string s("1");
		while (--n)
			s = getNext(s);
		return s;
	}
	string getNext(const string &s)
	{
		stringstream ss;
		for (auto i = s.begin(); i != s.end(); )
		{
			auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
			ss << distance(i, j) << *i;
			i = j;
		}
		return ss.str();
	}

private:

};

