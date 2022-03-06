#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> divide(vector<int>& num)
{
	int sum = accumulate(num.begin(), num.end(), 0);
	if (sum % 2 != 0) return vector<int>();
	
	int half = sum / 2, n = num.size();
	vector<vector<bool>> dp(n + 1, vector<bool>(half + 1, false));
	
	int i, j;
	for (i = 0; i <= n; ++i) {
		dp[i][0] = true;
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= half; ++j) {
			if (j >= num[i - 1]) {
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num[i - 1]];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	vector<int> ans;
	if (dp[n][half]) {
		while (half) {
			if (half >= num[n - 1] && dp[n - 1][half - num[n - 1]]) {
				ans.push_back(num[n - 1]);
				half -= num[n - 1];
			}
			n--;
		}
		return ans;
	} else {
		return vector<int>();
	}
}
int main()
{
	vector<int> num{1, 5, 11, 5};
	vector<int> ans = divide(num);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
 	return 0;
}
