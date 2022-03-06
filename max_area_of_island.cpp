#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& matrix, int i, int j, int& max_area, int& area)
{
	matrix[i][j] = -1;
	area++;
	if (max_area < area)	max_area = area;
	if (i - 1 >= 0 && matrix[i - 1][j] == 1) {
		dfs(matrix, i - 1, j, max_area, area);
	}
	if (i + 1 < matrix.size() && matrix[i + 1][j] == 1) {
		dfs(matrix, i + 1, j, max_area, area);
	}
	if (j - 1 >= 0 && matrix[i][j - 1] == 1) {
		dfs(matrix, i, j - 1, max_area, area);
	}
	if (j + 1 < matrix[0].size() && matrix[i][j + 1] == 1) {
		dfs(matrix, i, j + 1, max_area, area);
	}
}

void find_max_area(std::vector<std::vector<int>>& matrix, int& max_area)
{
	int i, j;
	int row = matrix.size(), col = matrix[0].size();
	int area;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (matrix[i][j] == 1) {
				area = 0;	
				dfs(matrix, i, j, max_area, area);
			}
		}
	}
}

int main()
{
	std::vector<std::vector<int>> matrix{{1, 0, 1, 1, 0, 1, 0, 1},
										 {1, 0, 1, 1, 0, 1, 1, 1},
										 {0, 0, 0, 0, 0, 0, 0, 1}};
	int max_area = 0;
	find_max_area(matrix, max_area);
	std::cout << max_area;
	return 0;
}
