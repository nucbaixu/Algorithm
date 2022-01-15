//Find the contiguous subarray within an array(containing at least one number) which has the largest sum.
//For example, given the array[−2, 1, −3, 4, −1, 2, 1, −5, 4], the contiguous subarray[4, −1, 2, 1] has
//the largest sum = 6.

//最大连续子序列和，非常经典的题。
//当我们从头到尾遍历这个数组的时候，对于数组里的一个整数，它有几种选择呢？它只有两种
//选择：1、加入之前的 SubArray；2.自己另起一个 SubArray。那什么时候会出现这两种情况呢？
//如果之前 SubArray 的总体和大于 0 的话，我们认为其对后续结果是有贡献的。这种情况下我们
//选择加入之前的 SubArray
//如果之前 SubArray 的总体和为 0 或者小于 0 的话，我们认为其对后续结果是没有贡献，甚至是
//有害的（小于 0 时）。这种情况下我们选择以这个数字开始，另起一个 SubArray

//设状态为 f[j]，表示以 S[j] 结尾的最大连续子序列和，则状态转移方程如下：
//f[j] = max{ f[j - 1] + S[j], S[j] }, 其中1 ≤ j ≤ n
//target = max{ f[j] }, 其中1 ≤ j ≤ n
#pragma once
#include <algorithm>
#include <math.h>
using namespace std;

class Solution 
{
public:
	int maxSubArray(int A[], int n) 
	{
		int result = INT_MIN, f = 0;
		for (int i = 0; i < n; ++i) 
		{
			f = max(f + A[i], A[i]);
			result = max(result, f);
		}
		return result;
	}
};
