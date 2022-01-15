#pragma once
#include <string>
#include "vector"
using namespace std;

//Given an integer, convert it to a roman numeral.
//Input is guaranteed to be within the range from 1 to 3999.
class IntegerToRoman
{
public:
	string intToRoman(int num)
	{
		const int radix[] = 
		{ 
			               1000,
			900, 500, 400, 100, 
			90,   50,  40,  10,
			9,     5,   4,   1 
		};

		const string symbol[] = { "M", "CM", "D", "CD", "C", "XC",
			"L", "XL", "X", "IX", "V", "IV", "I" };
		string roman;
		for (size_t i = 0; num > 0; ++i) 
		{
			int count = num / radix[i];
			num %= radix[i];
			for (; count > 0; --count) roman += symbol[i];
		}
		return roman;
	}
};


class RomanToInteger
{
public:

	inline int map(const char c) 
	{
		switch (c) 
		{
			case 'I': return 1;
			case 'V': return 5;
			case 'X': return 10;
			case 'L': return 50;
			case 'C': return 100;
			case 'D': return 500;
			case 'M': return 1000;
			default: return 0;
		}
	}

	//从前往后扫描，用一个临时变量记录分段数字。
	/*如果当前比前一个大，说明这一段的值应该是当前这个值减去上一个值。比如 IV = 5 – 1；否
	则，将当前值加入到结果中，然后开始下一段记录。比如 VI = 5 + 1, II = 1 + 1*/
	int RomanToint(string Roman)
	{
		int result;

		for (size_t i = 0; i < Roman.size(); i++) 
		{
			if (i > 0 && map(Roman[i]) > map(Roman[i - 1]))
			{
				result += (map(Roman[i]) - 2 * map(Roman[i - 1]));
			}
			else 
			{
				result += map(Roman[i]);
			}
		}
	}
private:
};

