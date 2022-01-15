//Given a string S, find the longest palindromic substring in S.You may assume that the maximum length
//of S is 1000, and there exists one unique longest palindromic substring.
#pragma once
#include "string"
#include <vector>
#include <algorithm>
using namespace std;

class LongestPalindromicSubstring
{
public:

	//ʹ�ö�̬�滮�㷨
	string longestPalindrome(string s) 
	{
		const int n = s.size();
		//bool f[n][n];
		//fill_n(&f[0][0], n * n, false);
		
		// �� vector �ᳬʱ
		vector<vector<bool> > f(n, vector<bool>(n, false));
		size_t max_len = 1, start = 0; // ������Ӵ��ĳ��ȣ����
		for (size_t i = 0; i < s.size(); i++)
		{
			f[i][i] = true;
			for (size_t j = 0; j < i; j++)
			{ // [j, i]
				f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
				if (f[j][i] && max_len < (i - j + 1)) 
				{
					max_len = i - j + 1;
					start = j;
				}
			}
		}
		return s.substr(start, max_len);
	}


private:

};

