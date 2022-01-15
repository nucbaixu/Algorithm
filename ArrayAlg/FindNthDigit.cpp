#pragma once
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
	int FindNthDigit(int n)
	{
		if (n == 0) return 0;
		
		//
		int digit = 1;
		long count = 9;
		long start = 1;

		while (n > count)
		{
			n -= count;
			digit += 1;
			start *= 10;
			count = digit * 9 * start;
		}

		//
		long num = start + (n - 1) / digit;
		int remain = (n - 1) % digit;
		string s_num = std::to_string(num);
		return int(s_num[remain] - '0');
	}
private:

};
