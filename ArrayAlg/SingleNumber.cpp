/******************************************************
 @ function : 剑指 Offer 56 - II. 数组中数字出现的次数 II	
 @ Access 	:	
 @ Parameter:	
 @ Returns  :	
 @ Remarks 	:   
 @ author   :   
******************************************************/

/* 从二进制的角度来看，int 类型占 32 个 bit 位，并且每个位，只可能是 1 或 0。
	那么从 二进制 角度来看相同的数，二进制的 bit 位也是一样的，如：


 7 : 0B0111
 7 : 0B0111
 7 : 0B0111
		^^^
		|||
 出现数  333 // 从上向下，可以发现[3个7]每位都出次了 3 次

那这样时再增加一个数。
 7 : 0B0111
 7 : 0B0111
 7 : 0B0111
 4 : 0B0100
		^^^
		|||
 出现数  433 // 从上向下，只有第 3位bit 出现了 4次
		%%%
		333 // 接下来，把现各个位出现的次数，按 3取余
		‖‖‖
		100 // 取余结果

 */

#pragma once
#include <vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) 
	{
		int res = 0;

		for (int i = 0 ; i < 32; i++)
		{
			//计算二进制每位的和
			int sum = 0;
			for (auto item : nums)
			{
				sum += (item >> i) & 1;
			}

			sum %= 3;
			res |= sum << i;
			//res += std::pow(2, sum);
		}

		return res;
	}
}；