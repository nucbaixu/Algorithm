/******************************************************
 @ function : 	剑指 Offer 58 - I. 翻转单词顺序
 @ Access 	:	
 @ Parameter:	
 @ Returns  :	
 @ Remarks 	:   
 @ author   :   
******************************************************/
#pragma once
#include "string"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <functional>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string reverseWords(string s) 
	{
		string res;
		if (s.empty()) return res;

		int s_size = s.size();
		int right = s_size - 1;

		while (right >= 0)
		{
			while (right >= 0 && s[right] == ' ')
			{
				right--;
			}

			if (right < 0) break;

			int left = right;
			while (left >= 0 && s[left] != ' ')
			{
				left--;
			}

			//添加单词到结果
			res += s.substr(left + 1, right - left);
			res += " ";
			right = left;
		}


		//去除最后一个字符空格
		if (!res.empty()) res.pop_back();
		return res;	
	}
};


