//Write a function to find the longest common prefix string amongst an array of strings.
#pragma once
#include <string>
#include "vector"
using namespace std;

class LongestCommonPrefix
{
public:
	//纵向扫描
	string longestCommonPrefix(vector<string> &strs)
	{
		if (strs.empty()) return "";
		for (int idx = 0; idx < strs[0].size(); ++idx)
		{
			// 纵向扫描
			for (int i = 1; i < strs.size(); ++i)
			{
				//如果后面的有比较短的字符串，不会越界吗？
				if (strs[i][idx] != strs[0][idx]) 
					 return strs[0].substr(0, idx);
			}
		}
		return strs[0];
	}

	//横向扫描
	string longestCommonPrefix2(vector<string> &strs)
	{
		if (strs.empty()) return "";
		int right_most = strs[0].size() - 1;
		for (size_t i = 1; i < strs.size(); i++)
		{
			for (int j = 0; j <= right_most; j++)
			{
				if (strs[i][j] != strs[0][j]) // 不会越界，请参考 string::[] 的文档
					right_most = j - 1;
			}

			return strs[0].substr(0, right_most + 1);
		}
	}

private:

};