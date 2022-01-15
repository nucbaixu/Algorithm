#pragma once
#include "string"
#include <stack>
// Alg Describtion : Given a string containing just the characters ¡¯(¡¯, ¡¯)¡¯, ¡¯{ ¡¯, ¡¯ }¡¯, ¡¯[¡¯ and ¡¯]¡¯, 
//                   determine if the string is valid

//                   The brackets must close in the correct order, ¡±()¡± and ¡±()[]¡± are all valid 
//                   but ¡±(]¡± and ¡±([)]¡±  are not


class Slution {
public:
	bool isValid(const std::string  & str);

};

bool Slution::isValid(const std::string  & str)
{
	if (str.empty()) return false;
	
	const std::string stringleft = "([{";
	const std::string stringright = ")]}";

	std::stack<char> stk;

	for (auto s:str)
	{
		if (stringleft.find(s) != std::string::npos)
		{
			stk.emplace(s);
		}
		else
		{
			if (stk.empty() || stk.top != stringleft[stringright.find(s)] )
			{
				return false;
			}
			else
			{
				stk.pop();
			}
		}
	}
}
