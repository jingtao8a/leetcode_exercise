#include <iostream>
#include <vector>

using namespace std;

vector<int> coins{1, 2, 5};
const int amount = 11;
vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));

int min(int x, int y)
{
	return x < y ? x : y;
}

int coin_change()
{
	int i, j;
	for (j = 0; j < dp[0].size(); ++j) {
		dp[0][j] = j;
	}
	for (i = 0; i < dp.size(); ++i) {
		dp[i][0] = 0;
	}

	for (i = 1; i < dp.size(); ++i) {
		for (j = 1; j < dp[0].size(); ++j) {
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k * coins[i] <= j; ++k) {
				dp[i][j] = min(dp[i][j], k + dp[i - 1][j - k * coins[i]]); 
			}
		}
	}
	return dp[coins.size() - 1][amount];
}

int main()
{
	cout << coin_change();
 	return 0;
}
