//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring
//cases.
//For example,
//”A man, a plan, a canal : Panama” is a palindrome.
//”race a car” is not a palindrome.
//Note : Have you consider that the string might be empty ? This is a good question to ask during an
//	interview.
//	For the purpose of this problem, we define empty string as valid palindrome.
#pragma once
#include "string"
#include <algorithm>


class CValidPalingdrome
{
public:
	bool isPalindrome(std::string s);

private:

};

bool CValidPalingdrome::isPalindrome(std::string s)
{
	//转化为小写
	std::transform(s.begin(), s.end(), s.begin(), ::towlower);

	auto lelf = s.begin();
	auto right = prev(s.end());

	while (lelf < right)
	{
		//isalnum:字母数字返回非0
		if (!::isalnum(*lelf))++lelf;	
		else if (!::isalnum(*right))--right;	
		else if (*lelf++ != *right--)return false;
	}
}

