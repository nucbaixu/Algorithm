//Given an absolute path for a file(Unix - style), simplify it.
//For example,
//path = "/home/", = > "/home"
//path = "/a/./b/../../c/", = > "/c"
//Corner Cases :
//• Did you consider the case where path = "/../" ? In this case, you should return "/".
//• Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
//In this case, you should ignore redundant slashes and return "/home/foo".

#pragma once
#include "string.h"
#include "vector"
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;
class SimplifyPath
{
public:
	string simplifyPath(string const& path)
	{
		vector<string> dirs; // 当做栈
		for (auto i = path.begin(); i != path.end();) 
		{
			++i;
			auto j = find(i, path.end(), '/');
			auto dir = string(i, j);
			if (!dir.empty() && dir != ".") 
			{
				// 当有连续 '///' 时，dir 为空
				if (dir == "..") 
				{
					if (!dirs.empty())
						dirs.pop_back();
				}
				else
					dirs.push_back(dir);
			}
			i = j;
		}
		
		std::stringstream out;
		if (dirs.empty()) 
		{
			out << "/";
		}
		else 
		{
			for (auto dir : dirs)
				out << '/' << dir;
		}
		return out.str();
	}

private:

};

