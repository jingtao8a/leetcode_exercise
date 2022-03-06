#include <vector>
#include <iostream>

bool search(std::vector<std::vector<int>> matrix, int target)
{
	int i = 0, j = matrix.size() - 1;
	while (i < matrix.size() && j >= 0) {
		if (matrix[i][j] == target) return true;
		if (matrix[i][j] < target) 
			i++;
		else
			j--;
	}
	return false;
}

int main()
{
	std::vector<std::vector<int>> matrix{
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};
	int target = 11;
	std::cout << search(matrix, target);
	return 0;
}