#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& map, int i, int j, bool& pacific, bool& atlantic, std::vector<std::vector<int>>& sign)
{
	sign[i][j] = 1;
	
	if (i == 0 || j == 0) pacific = true;
	if (i == map.size() - 1|| j == map[i].size() - 1) atlantic = true;
	
	if (i - 1 >= 0 && sign[i - 1][j] == 0 && map[i - 1][j] <= map[i][j]) {
		dfs(map, i - 1, j, pacific, atlantic, sign);
	}
	if (i + 1 < map.size() && sign[i + 1][j] == 0 && map[i + 1][j] <= map[i][j]) {
		dfs(map, i + 1, j, pacific, atlantic, sign);
	}
	if (j - 1 >= 0 && sign[i][j - 1] == 0 && map[i][j - 1] <= map[i][j]) {
		dfs(map, i, j - 1, pacific, atlantic, sign);
	}
	if (j + 1 < map[i].size() && sign[i][j + 1] == 0 && map[i][j + 1] <= map[i][j]) {
		dfs(map, i, j + 1, pacific, atlantic, sign);
	}
}

bool judge(std::vector<std::vector<int>>& map, int i, int j)
{
	std::vector<std::vector<int>> sign(map.size(), std::vector<int>(map[0].size(), 0));
	bool pacific = false, atlantic = false;
	dfs(map, i, j, pacific, atlantic, sign);
	if (pacific == true && atlantic == true) 
		return true;
	else
		return false;
}

int main()
{
	std::vector<std::vector<int>> map{{1, 2, 2, 3, 5},
									  {3, 2, 3, 4, 4},
									  {2, 4, 5, 3, 1},
									  {6, 7, 1, 4, 5},
									  {5, 1, 1, 2, 4}};
	std::vector<std::vector<int>> ans;
	int i, j;
	for (i = 0; i < map.size(); i++) {
		for (j = 0; j < map[i].size(); j++) {
			if (judge(map, i, j) == true) {
				ans.push_back(std::vector<int>{i, j});
			}
		}
	}
	for (i = 0; i < ans.size(); i++) {
		for (j = 0; j < ans[i].size(); j++) {
			std::cout << ans[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	return 0;
}
