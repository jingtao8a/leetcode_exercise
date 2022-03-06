#include <iostream>
#include <vector>

using namespace std;

constexpr int n = 13;
vector<int> dp(n + 1, 0);

int sqrt(int x)
{
	if (x == 0) return 0;
	for (int res = 1; res <= x; ++res) {
		if (res == x / res)
			return res;
	}
	return -1;
}

int main()
{
	dp[1] = 1;
	for (int i = 2; i < dp.size(); ++i) {
		if (i == sqrt(i) * sqrt(i)) {
			dp[i] = 1;
		} else {
			dp[i] = dp[i - 1] + 1;
			for (int j = 2; j <= i / 2; ++j) {
				dp[i] = dp[i] < dp[i -j] + dp[j] ? dp[i] : dp[i - j] + dp[j];
			}
		}
	}
	for (int i = 1; i < dp.size(); ++i) {
		cout << dp[i] << " ";
	}
	cout << endl;
	return 0;
}