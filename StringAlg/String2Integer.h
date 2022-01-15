#pragma once
#include "string.h"
#include <algorithm>
using namespace std;

class StringToInteger
{
public:
	int atoi(const char *str)
	{
		long long num = 0;
		int sign = 1;

		const int n = strlen(str);

		int i = 0;

		while (i < n && str[i] == ' ') i++;
		
		if (str[i] == '+') i++;
		else if (str[i] == '-')
		{
			sign = -1, 
			i++;
		}
		
		const int val1 = INT_MAX / 10;
		const int val2 = INT_MAX % 10;

		for (; i < n; i++)
		{
			if (str[i] > '9' || str[i] < '0') break;

			if (num > val1 || (num == val1 &&
				(str[i] - '0') > val2))
			{
				return sign == -1 ? INT_MIN : INT_MAX;
			}

			num = num * 10 + str[i] - '0';
		}

		return sign * num;

	}
private:
};

//int main()
//{
//	char * src = "4193 with words";
//	StringToInteger s;
//	int sint = s.atoi(src);
//	return 0;
//}