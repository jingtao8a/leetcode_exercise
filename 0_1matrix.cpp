#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point{
	int x, y;
	point(int x_, int y_) : x(x_), y(y_) {}
};

vector<vector<int>> map{
{0, 0, 0},
{0, 1, 0},
{1, 1, 1}
};

vector<vector<bool>> sign(map.size(), vector<bool>(map[0].size(), false));

vector<int> dir = {-1, 0, 1, 0, -1};

void bfs(int i, int j)
{
	for (int row = 0; row < sign.size(); ++row) {
		for (int col = 0; col < sign[row].size(); ++col) {
			sign[row][col] = false;
		}
	}
	queue<point> q;
	
	sign[i][j] = true;
	q.push(point(i, j));
	
	int level = 0, width;
	int x, y;
	while (!q.empty()) {
		width = q.size();
		while (width--) {
			point tmp = q.front();
			q.pop();
			x = tmp.x;
			y = tmp.y;
			for (int c = 0; c < 4; ++c) {
				if (x + dir[c] >= 0 && y + dir[c + 1] >= 0 && 
				x +dir[c] < map.size() && y + dir[c + 1] < map[0].size() && 
				sign[x + dir[c]][y + dir[c + 1]] == false) {
					
					if (map[x + dir[c]][y + dir[c + 1]] == 0) {
						map[i][j] = level + 1;
						return;
					}
					sign[x + dir[c]][y + dir[c + 1]] = true;
					q.push(point(x + dir[c], y + dir[c + 1]));
				}
			}
		}
		level++;
	}
}

int main()
{
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j) {
			if (map[i][j] != 0) {
				bfs(i, j);
			}
		}
	}
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}