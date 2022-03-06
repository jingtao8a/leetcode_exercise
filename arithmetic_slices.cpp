#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> nums{1, 2, 3, 4};
vector<int> dp(nums.size(), 0);

int main()
{
	for (int i = 2; i < dp.size(); ++i) {
		if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
			dp[i] = dp[i - 1] + 1;
		}
	}
	cout << accumulate(dp.begin(), dp.end(), 0);	
	return 0;
}