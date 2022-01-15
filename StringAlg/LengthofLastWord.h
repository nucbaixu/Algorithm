//Given a string s consists of upper / lower - case alphabets and empty space characters ' ', return the length
//of last word in the string.
//If the last word does not exist, return 0.
//Note: A word is defined as a character sequence consists of non - space characters only.
//	For example, Given s = "Hello World", return 5.
#pragma once
#include <string>
#include <algorithm>
using namespace std;


class LenthofLastWord
{
public:
	int lengthOfLastWord1(const char *s) 
	{
		int len = 0;
		while (*s) 
		{
			if (*s++ != ' ')
				++len;
			else if (*s && *s != ' ')
				len = 0;
		}
		return len;
	}

	int lengthOfLastWord2(const char *s) 
	{
		const string str(s);
		auto first = find_if(str.rbegin(), str.rend(), ::isalpha);
		auto last = find_if_not(first, str.rend(), ::isalpha);
		return distance(first, last);
	}
};

