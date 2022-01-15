#pragma once
#include "string.h"
#include <algorithm>
#include <string>
using namespace std;

//https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/solution/dai-ma-sui-xiang-lu-dai-ni-gao-ding-zuo-vs2oc/
class Solution {
public:
	string reverseLeftWords(string s, int n) {
		reverse(s.begin(), s.begin() + n);
		reverse(s.begin() + n, s.end());
		reverse(s.begin(), s.end());
		return s;
	}
};