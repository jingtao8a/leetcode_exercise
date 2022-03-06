#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& friends, int i, std::vector<bool>& visited)
{
	visited[i] = true;;
	int col = friends.size();
	for (int k = 0; k < col; k++) {
		if (friends[i][k] == 1 && visited[k] == false) {
			dfs(friends, k, visited);
		}
	}
}

int findCircleNum(std::vector<std::vector<int>>& friends) 
{
	int count = 0;
	int n = friends.size();
	std::vector<bool> visited(n, false);
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			dfs(friends, i, visited);
			++count;
		}
	}
	return count;
}

int main()
{
	std::vector<std::vector<int>> friends{{1, 1, 1},
										  {1, 1, 0},
										  {1, 0, 1}};
	std::cout << findCircleNum(friends);
	return 0;
}
