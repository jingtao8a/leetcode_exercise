#include <iostream>
#include <vector>
#define MINUS_INF -9999
using namespace std;

vector<int> stock{7, 1, 5, 3, 6, 4};
vector<int> dp(stock.size(), MINUS_INF);

int min_all(int i)
{
	int min = stock[0];
	for (int k = 1; k < i; ++k) {
		if (stock[k] < min) 
			min = stock[k];
	}
	return min;
}

int max(int x, int y) 
{
	return x > y ? x : y;
}

int solve()
{
	dp[1] = stock[1] - stock[0];
	for (int i = 2; i < dp.size(); ++i) {
		dp[i] = stock[i] - min_all(i);
		for (int j = 1; j < i; ++j)
			dp[i] = max(dp[i], dp[j]);
	}
	return dp.back();
}

int main()
{
	cout << solve();
 	return 0;
}
