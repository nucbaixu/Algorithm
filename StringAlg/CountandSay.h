//The count - and-say sequence is the sequence of integers beginning as follows :
//1, 11, 21, 1211, 111221, ...
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2", then "one 1" or 1211.
//Given an integer n, generate the nth sequence.
//Note : The sequence of integers will be represented as a string.

//��n = 1ʱ�����1��
//��n = 2ʱ������1��1����1�� ����ʾΪ11��
//��n = 3ʱ��������һ��11������2��1����ʾΪ21����ע����ͬ���ֵ�������
//��n = 4ʱ��������һ��21������1��2��һ��1����ʾΪ1211��
//��n = 5ʱ��������һ��1211������1��1��1��2��2��1����ʾΪ111221��
//��n = 6ʱ��������һ��111221������3��1��2��2��1��1����ʾΪ312211

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

