#include <iostream>
#include <vector>

using namespace std;

vector<int> count_bits(int num)
{
	vector<int> dp(num + 1, 0);
	dp[1] = 1;
	for (int i = 2; i < dp.size(); ++i) {
		if (i & 1) {
			dp[i] = dp[i - 1] + 1;
		} else {
			dp[i] = dp[i >> 1];
		}
	}
	return dp;
}

int main()
{
	vector<int> res = count_bits(8);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
 	return 0;
}
