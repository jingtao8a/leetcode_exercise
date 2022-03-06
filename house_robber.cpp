#include <iostream>
#include <vector>

using namespace std;

vector<int> money{2, 7, 9, 3, 1};
vector<int> dp(money.size(), 0);

int main()
{
	dp[0] = money[0];
	dp[1] = money[1] > dp[0] ? money[1] : dp[0];
	for (int i = 2; i < dp.size(); ++i) {
		dp[i] = dp[i - 1] > dp[i - 2] + money[i] ? dp[i - 1] : dp[i - 2] + money[i];
	}
	cout << dp.back();
	return 0;
}