#pragma once
#include "string"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <functional>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	char FristUniqChar(string s)
	{
		if (s.empty()) return ' ';

		unordered_map<char, int> map;

		for (auto item : s)
		{
			map[item]++;
		}

		for (auto item : s)
		{
			if (map[item] == 1)
			{
				return item;
			}
		}

		return ' ';
	}
};

class Solution2
{
public:
	char FristUniqChar(string s)
	{
		if (s.empty()) return ' ';

		unordered_map<char, bool> map;

		for (auto item : s)
		{
			map[item] = map.find(item) == map.end();
		}

		for (auto item : s)
		{
			if (map[item])
			{
				return item;
			}
		}

		return ' ';
	}
};