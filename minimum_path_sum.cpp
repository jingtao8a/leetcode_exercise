#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map{
{1, 3, 1},
{1, 5, 1},
{4, 2, 1}
};

vector<vector<int>> dp(map.size(), vector<int>(map[0].size(), 0));

int main()
{
	dp[0][0] = map[0][0];
	for (int i = 1; i < map.size(); ++i) {
		dp[i][0] = dp[i -1][0] + map[i][0];
	}
	for (int j = 1; j < map[0].size(); ++j) {
		dp[0][j] = dp[0][j - 1] + map[0][j];
	}
	for (int i = 1; i < map.size(); ++i) {
		for (int j = 1; j < map[0].size(); ++j) {
			dp[i][j] = dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] + map[i][j] : dp[i][j - 1] + map[i][j];
		}
	}
	cout << dp.back().back();
	return 0;
}
