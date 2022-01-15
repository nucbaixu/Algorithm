#pragma once
#include "stdafx.h"
class Solution
{
public:
	std::vector<int> plausOne(std::vector<int> &digits)
	{
		const rsize_t iveclen = digits.size();

		// if digits is empty ,return digits
		if (iveclen == 0)
		{
			return digits;
		}

		// 1239  9321
		int digit = 1; 
		for (auto it = digits.rbegin(); it != digits.rend(); ++it)
		{
			*it += digit;
			digit = *it / 10;
			*it %= 10;
		}

		if (digit > 0)
		{
			digits.insert(digits.begin(), 1);
		}

		return digits;
	}
};


