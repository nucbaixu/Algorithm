#pragma once
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;


class Solution
{
public:
	int lastRemaining(int n,int m)
	{
		return dfs(n,m);
	}

private:
	int dfs(int n, int m)
	{
		if (n == 1)
		{
			return 0;
		}

		int  x = dfs(n-1,m);
		return (m + x) % n;
	}
};

