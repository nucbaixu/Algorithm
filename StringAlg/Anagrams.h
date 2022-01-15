//Given an array of strings, return all groups of strings that are anagrams.
//Note: All inputs will be in lower - case.

//Anagram�����Ĺ��ʷ�����ָ������ĸ˳��Ӷ��õ��µĵ��ʣ����� "dormitory" ������ĸ˳
//����� "dirty room" ��"tea" ����"eat"��
//���Ĺ��ʷ���һ���ص㣺���������ĸ���������Ŀû�иı䣬ֻ�Ǹı�����ĸ������˳��
//��ˣ����������ʰ�����ĸ˳���������������ȣ�����������ͬһ�� anagrams ��
#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;



class Solution 
{
public:
	vector<string> anagrams(vector<string> &strs) 
	{
		unordered_map<string, vector<string> > group;
		for (const auto &s : strs) {
			string key = s;
			sort(key.begin(), key.end());
			group[key].push_back(s);
		}
		
		vector<string> result;
		for (auto it = group.cbegin(); it != group.cend(); it++) 
		{
			if (it->second.size() > 1)
				result.insert(result.end(), it->second.begin(), it->second.end());
		}
		return result;
	}
};