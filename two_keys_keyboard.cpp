#include <iostream>
#include <vector>

using namespace std;

const int n = 6;
vector<int> dp(n + 1);

int min(int x, int y)
{
	return x < y ? x : y;
}

int solve()
{
	int i, k;
	dp[0] = dp[1] = 0;
	for (i = 2; i <= n; ++i)
		dp[i] = i;
	for (i = 2; i <= n; ++i) {
		for (k = 1; k <= i / 2; ++k) {
			if (i % k == 0)
				dp[i] = min(dp[i], dp[k] + dp[i / k]);
		}
	}
	return dp[n];
}
int main()
{
	cout << solve();
 	return 0;
}
