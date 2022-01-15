#pragma once
#include "stdafx.h"
#include "stdio.h"
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;


namespace BubbleSort
{
	/*
	 *  time - O(N*N)
	 */
	void BubbleSort_V0(int * array, int length)
	{
		if (array == nullptr) return;

		for (int i = 0; i < length - 1; i++)
		{
			for (int j = 0; j < length - 1 - i; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(array[j], array[j + 1]);
				}
			}
		}
	}

	/*
	 *  if iteration is already sorted break
	 */
	void BubbleSort_V1(int * array, int length)
	{
		if (array == nullptr) return;

		bool isSorted = true;

		for (int i = 0; i < length - 1; i++)
		{
			/*set not sorted*/
			isSorted = true;
			for (int j = 0; j < length - 1 - i; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(array[j], array[j + 1]);

					/*if has item change means not sorted*/
					isSorted = false;
				}
			}

			/*if is sorted break */
			if (isSorted)
			{
				break;
			}
		}
	}

	/*
	 * set sorted right border
	 */
	void BubbleSort_V2(int * array, int length)
	{
		if (array == nullptr) return;

		bool isSorted = true;
		int rightOrder = length - 1;

		for (int i = 0; i < length - 1; i++)
		{
			/*set not sorted*/
			isSorted = true;

			for (int j = 0; j < rightOrder - i; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(array[j], array[j + 1]);

					/*if has item change means not sorted*/
					isSorted = false;
					rightOrder = j;
				}
			}

			/*if is sorted break */
			if (isSorted)
			{
				break;
			}
		}
	}

	/*
	 *
	 */
	void BubbleSort_V3(int * array, int length)
	{
		if (array == nullptr) return;

		bool isSorted = true;

		for (int i = 0; i < length >> 1; i++)
		{
			/*set not sorted*/
			isSorted = true;

			/*left -> right*/
			for (int j = 0; j < length - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(array[j], array[j + 1]);

					/*if has item change means not sorted*/
					isSorted = false;
				}
			}

			/*if is sorted break */
			if (isSorted) break;

			/*right -> left*/
			isSorted = true;
			for (int j = length - i - 1; j > i; j--)
			{
				if (array[j - 1] > array[j])
				{
					swap(array[j - 1], array[j]);
					isSorted = false;
				}
			}

			if (isSorted) break;
		}
	}
}


namespace quic_sort
{
	/*
	 * O(N*log(N))
	 * 递归
	 * 双边循环法
	 */
	void quicksort_V1(int * array, int startindex,int endindex)
	{
		if (startindex >= endindex) return;


		auto fun_partition = [](int * array, int start,int end)
		{
			//取第一个位置作为基准元素
			int base = array[start];

			int left = start;
			int right = end;

			while (left != end)
			{
				while (right >left && array[right] > base)
				{
					right--;
				}

				while (left < right && array[left] <= base)
				{
					left++;
				}

				if (left < right)
				{
					swap(array[left], array[right]);
				}
			}

			array[start] = array[left];
			array[left] = base;

			return left;
		};
		
		//得到基准元素的位置
		int baseIndex = fun_partition(array, startindex,endindex);
		quicksort_V1(array, startindex, baseIndex - 1);
		quicksort_V1(array, baseIndex + 1, endindex);
	}

	/*
	 * O(N*log(N))
	 * 递归
	 * 单边循环法
	 */
	void quicksort_V2(int * array, int startindex, int endindex)
	{
		if (startindex >= endindex) return;


		auto fun_partition = [](int * array, int start, int end)
		{
			//取第一个位置作为基准元素
			int base = array[start];

			int mark = start;

			for (int i = start + 1; i <= end;i++)
			{
				if (array[i] < base)
				{
					mark++;
					swap(array[mark], array[i]);
				}
			}

			swap(array[mark], array[start]);
			return mark;
		};

		//得到基准元素的位置
		int baseIndex = fun_partition(array, startindex, endindex);
		quicksort_V2(array, startindex, baseIndex - 1);
		quicksort_V2(array, baseIndex + 1, endindex);
	}

	/*
	 * O(N*log(N))
	 * 非递归
	 * 双边循环法
	 */
	void quicksort_V2_NoRescue(int * array, int startindex, int endindex)
	{
		auto fun_partition = [](int * array, int start, int end)
		{
			//取第一个位置作为基准元素
			int base = array[start];

			int mark = start;

			for (int i = start + 1; i <= end; i++)
			{
				if (array[i] < base)
				{
					mark++;
					swap(array[mark], array[i]);
				}
			}

			swap(array[mark], array[start]);
			return mark;
		};

		std::unordered_map<std::string, int> map;
		map["startindex"] = startindex;
		map["endindex"] = endindex;

		std::stack< std::unordered_map<std::string, int> > stacks;
		stacks.emplace(map);
		

		while (!stacks.empty())
		{
			std::unordered_map<std::string, int> item = stacks.top();
			stacks.pop();

			int pavotindex = fun_partition(array,item["startindex"],item["endindex"]);

			if (item["startindex"] < pavotindex - 1)
			{
				std::unordered_map<std::string, int> tmpmap;
				tmpmap["startindex"] = item["startindex"];
				tmpmap["endindex"] = pavotindex - 1;
				stacks.emplace(tmpmap);
			}

			if (pavotindex + 1 < item["endindex"])
			{
				std::unordered_map<std::string, int> tmpmap;
				tmpmap["startindex"] = pavotindex + 1;  
				tmpmap["endindex"] = item["endindex"];
				stacks.emplace(tmpmap);
			}
		}
	}
}