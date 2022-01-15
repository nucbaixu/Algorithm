//a = "11"
//b = "1"
//Return ”100”.
#pragma once
#include "string.h"
#include "string"
#include <algorithm>
using namespace std;

class AddBinay
{
public:
	std::string addBinary(string a, string b)
	{
		string result;
		const size_t n = a.size() > b.size() ? a.size() : b.size();

		//因为相加从低位开始，所以逆序方便操作
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int carry = 0;
		for (size_t i = 0; i < n; i++)
		{
			const int ai = i < a.size() ? a[i] - '0' : 0;
			const int bi = i < b.size() ? b[i] - '0' : 0;
			const int val = (ai + bi + carry) % 2;
			carry = (ai + bi + carry) / 2;

			result.insert(result.begin(), val + '0');
		}

		if (carry == 1) 
		{
			result.insert(result.begin(), '1');
		}
		return result;
	}
private:

};

