#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<char>> matrix{
	{'A', 'B', 'C', 'D'},
	{'S', 'F', 'C', 'S'},
	{'A', 'D', 'E', 'F'},
	};

std::string route("ABCDSFEDAS");

std::vector<std::vector<bool>> sign(matrix.size(), 
									std::vector<bool>(matrix[0].size(), false));

void dfs(int i, int j, bool& flag, int k)
{
	if (k == route.size()) {
		flag = true;
		return;
	}
	
	if (matrix[i][j] == route[k]) {
		sign[i][j] = true;
		if (i - 1 >= 0 && sign[i - 1][j] == false) {
			dfs(i - 1, j, flag, k + 1);
		}
		if (i + 1 < matrix.size() && sign[i + 1][j] == false) {
			dfs(i + 1, j, flag, k + 1);
		}
		if (j - 1 >= 0 && sign[i][j - 1] == false) {
			dfs(i, j - 1, flag, k + 1);
		}
		if (j + 1 < matrix[0].size() && sign[i][j + 1] == false) {
			dfs(i, j + 1, flag, k + 1);
		}
		sign[i][j] = false;
	}
}
bool find_route()
{
	int i, j;
	bool flag = false;
 	for (i = 0; i < matrix.size(); ++i) {
 		for (j = 0; j < matrix[i].size(); ++j) {
 			dfs(i, j, flag, 0);
 			if (flag == true) {
 				return true;
			 }
		}
	}
	return false;
}

int main()
{
	std::cout << find_route();
	return 0;
}