#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix{
{0, 0, 1, 0},
{0, 1, 1, 1},
{1, 1, 1, 1},
{0, 1, 1, 1}
};

vector<vector<int>> measure(matrix.size(), vector<int>(matrix[0].size(), 0));

int min_3(int x, int y, int z) 
{
	int min = x;
	if (y < min) min = y;
	if (z < min) min = z;
	return min;
}

int sqrt(int x)
{
	if (x == 0) return 0;
	int res;
	for(res = 1; res <= x; ++res) {
		if (x / res == res)
			return res;
	}
	return -1;
}

int main()
{
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[i].size(); ++j) {
			if (i == 0 || j == 0) {
				if (matrix[i][j] == 1) {
					measure[i][j] = 1;
				} else {
					measure[i][j] = 0;
				}
			} else {
				if (matrix[i][j] == 1) {
					int min = min_3(measure[i - 1][j], measure[i - 1][j - 1], measure[i][j - 1]);
					min = sqrt(min);
					measure[i][j] = (min + 1) * (min + 1);
				} else {
					measure[i][j] = 0;
				}
			}
		}
	}
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[i].size(); ++j) {
			cout << measure[i][j] << " ";
		}
		cout <<endl;
	}
	return 0;
}