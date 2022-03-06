#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

vector<string> array{"10", "0001", "111001", "1", "0"};
vector<pair<int, int>> count;
const int m = 5, n = 3;
void find_0_1()
{
	int i, j;
	for (i = 0; i < array.size(); ++i) {
		pair<int, int> tmp(0, 0);
		for (j = 0; j < array[i].size(); ++j) {
			if (array[i][j] == '1')
				tmp.second++;
			else 
				tmp.first++;
		}
		count.push_back(tmp);
	}
}

vector<vector<vector<int>>> dp(array.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

int max(int x, int y)
{
	return x > y ? x : y;
}

int ones_zeros()
{
	int i, j, k;
	for (i = 1; i <= array.size(); ++i) {
		for (j = 1; j <= m; ++j) {
			for (k = 1; k <= n; ++k) {
				if (j >= count[i - 1].first && k >= count[i - 1].second) {
					dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - count[i - 1].first][k - count[i - 1].second] + 1);
				} else {
					dp[i][j][k] = dp[i - 1][j][k];
				}
			}
		}
	}
	return dp[array.size()][m][n];
}

int main()
{
	find_0_1();
	cout << ones_zeros();
 	return 0;
}
