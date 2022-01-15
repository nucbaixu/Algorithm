#pragma once
#include "stdafx.h"
class Solution
{
public:
	void roteimage(std::vector<std::vector<int> > &matrix)
	{
		size_t rows = matrix.size();
		if (rows <= 1)
		{
			return;
		}
		
		size_t cols = matrix[0].size();

		//对角线交换
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols - i; j++)
			{
				std::swap(matrix[i][j],matrix[cols - j - 1][rows - i - 1]);
			}
		}

		//垂直交换
		for (size_t i = 0; i < rows / 2; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				std::swap(matrix[i][j],matrix[rows - i - 1][j]);
			}
		}
	}
};

