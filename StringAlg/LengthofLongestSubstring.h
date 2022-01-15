#pragma once
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
		int len = s.size();
		if (len == 0) return 0;
		
		unordered_set<char> lookup;

		int maxstr = 0;
		int left = 0;
		for (int i =0 ; i < len;i++)
		{
			//如果集合中存在
			while (lookup.find(s[i]) != lookup.end())
			{
				lookup.erase(s[left]);
				left++;
			}

			maxstr = max(maxstr,i-left + 1);
			lookup.insert(s[i]);
		}

		return maxstr;
	}
};

//不用set的方式
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxsub = 0, left = 0, pos = 0;
		vector<bool> used(256, false);
		while (pos < s.size()) {
			while (used[s[pos]]) used[s[left++]] = false;
			maxsub = max(maxsub, pos - left + 1);
			used[s[pos++]] = true;
		}
		return maxsub;
	}
};


//链接：https ://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/solution/jian-zhi-offer-48-zui-chang-bu-han-zhong-liut/
