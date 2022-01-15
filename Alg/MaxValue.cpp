#pragma  once
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxValue(std::vector<std::vector<int>> &grid)
	{
		if (grid.empty() || grid[0].empty()) return -1;
		
		int rows = grid.size();
		int cols = grid[0].size();

		for (int j = 0; j < rows;j++)
		{
			for (int i = 0; i <  cols;i++)
			{
				if (i == 0  && j == 0)
				{
					continue;
				}
				else if (i == 0 && j != 0)
				{
					grid[j][i] += grid[j - 1][i];
				}
				else if (i != 0 && j == 0)
				{
					grid[j][i] += grid[j][i-1];
				}
				else
				{
					grid[j][i] += std::max(grid[j][i - 1], grid[j - 1][i]);
				}
			}
		}

		return grid[rows-1][cols -1];

	}

private:

};

