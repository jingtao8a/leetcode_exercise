#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str("92426");


vector<int> decode()
{
	vector<int> dp(str.size(), 0);
	dp[0] = 1;
	int tmp = (str[0] - '0') * 10 + (str[1] - '0');
	if (tmp > 0 & tmp <= 26) {
		dp[1] = 2;
	} else {
		dp[1] = 1;
	}
	
	for (int i = 2; i < dp.size(); ++i) {
		tmp = (str[i - 1] - '0') * 10 + (str[i] - '0');
		if (tmp > 0 && tmp <= 26) {
			dp[i] = dp[i - 2] + dp[i - 1];
		} else {
			dp[i] = dp[i - 1];
		}
	}
	return dp;
}

int main()
{
	vector<int> ans = decode();
	cout << ans.back();
	return 0;
}