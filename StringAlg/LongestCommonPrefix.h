//Write a function to find the longest common prefix string amongst an array of strings.
#pragma once
#include <string>
#include "vector"
using namespace std;

class LongestCommonPrefix
{
public:
	//����ɨ��
	string longestCommonPrefix(vector<string> &strs)
	{
		if (strs.empty()) return "";
		for (int idx = 0; idx < strs[0].size(); ++idx)
		{
			// ����ɨ��
			for (int i = 1; i < strs.size(); ++i)
			{
				//���������бȽ϶̵��ַ���������Խ����
				if (strs[i][idx] != strs[0][idx]) 
					 return strs[0].substr(0, idx);
			}
		}
		return strs[0];
	}

	//����ɨ��
	string longestCommonPrefix2(vector<string> &strs)
	{
		if (strs.empty()) return "";
		int right_most = strs[0].size() - 1;
		for (size_t i = 1; i < strs.size(); i++)
		{
			for (int j = 0; j <= right_most; j++)
			{
				if (strs[i][j] != strs[0][j]) // ����Խ�磬��ο� string::[] ���ĵ�
					right_most = j - 1;
			}

			return strs[0].substr(0, right_most + 1);
		}
	}

private:

};