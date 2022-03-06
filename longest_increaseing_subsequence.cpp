#include <iostream>
#include <vector>
using namespace std;

vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
vector<int> dp(nums.size(), 1);

int max(int x, int y)
{
	return x > y ? x : y;
}

void longest_increasing()
{
	for (int i = 1; i < dp.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (nums[i] > nums[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
}

int main()
{
	longest_increasing();
	for (int i = 0; i < dp.size(); ++i) {
		cout << dp[i] << " ";
	}
	return 0;
}