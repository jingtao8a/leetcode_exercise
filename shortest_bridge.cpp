#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> map{
{1, 1, 1, 1, 1},
{1, 0, 0, 0, 1},
{1, 0, 1, 0, 1},
{1, 0, 0, 0, 1},
{1, 1, 1, 1, 1}
};

int minpath = 0;
queue<pair<int, int>> q;

void dfs(int i, int j)
{
	map[i][j] = 2;
	q.push(pair<int, int>(i, j));
	if (i - 1 >= 0 && map[i - 1][j] == 1) {
		dfs(i - 1, j);
	}
	if (i + 1 < map.size() && map[i + 1][j] == 1) {
		dfs(i + 1, j);
	}
	if (j - 1 >= 0 && map[i][j - 1] == 1) {
		dfs(i, j - 1);
	}
	if (j + 1 < map[0].size() && map[i][j + 1] == 1) {
		dfs(i, j + 1);
	}
}

vector<int> dir{-1, 0, 1, 0, -1};

void shortest_bridge()
{
	pair<int, int> tmp;
	int x, y;
	int path = 0;
	int width;
	while (!q.empty()) {
		width = q.size();
		while (width--) {
			tmp = q.front(), q.pop();
			x = tmp.first, y = tmp.second;
			for (int i = 0; i < 4; ++i) {
				if (x + dir[i] >= 0 && y + dir[i + 1] >= 0 && x + dir[i] < map.size() && y + dir[i + 1] < map[0].size() &&
					map[x + dir[i]][y + dir[i + 1]] != 2) {
						
					if (map[x + dir[i]][y + dir[i + 1]] == 1) {
						minpath = path;
						return;
					}
					map[x + dir[i]][y + dir[i + 1]] = 2;
					q.push(pair<int, int>(x + dir[i], y + dir[i + 1]));
				}
			}
		}
		path++;
	}
}

int main()
{
	int i, j;
	bool flag = false;
	for (i = 0; i < map.size(); ++i) {
		for (j = 0; j < map[i].size(); ++j) {
			if (map[i][j] == 1) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	dfs(i, j);
	shortest_bridge();
	cout << minpath;
	return 0;
}
