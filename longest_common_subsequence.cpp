#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s1("abcde"), s2("ace");
vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

int max(int x, int y)
{
	return x > y ? x : y;
}

void longest_common_subsequence()
{
	int i, j;
	for (i = 1; i < dp.size(); ++i) {
		for (j = 1; j < dp[i].size(); ++j) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
		}
	}
}
int main()
{
	longest_common_subsequence();
	int i, j;
	for (i = 0; i < dp.size(); ++i) {
		for (j = 0; j < dp[i].size(); ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}