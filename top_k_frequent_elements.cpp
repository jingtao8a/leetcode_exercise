#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

std::vector<int> topFrequent(std::vector<int>& nums, int k)
{
	std::unordered_map<int, int> counts;
	std::priority_queue<std::pair<int, int>> pr_que;
	for (int& i : nums) ++counts[i];
	std::unordered_map<int, int>::iterator it = counts.begin();
	while (it != counts.end()) {
		pr_que.push(std::pair<int, int>((*it).second, (*it).first));
		++it;
	}
	std::vector<int> ans;
	for (int i = 1; i <= k; ++i) {
		ans.push_back(pr_que.top().second);
		pr_que.pop();
	}
	return ans;
}

int main()
{
	std::vector<int> nums{1, 1, 1, 1, 2, 2, 3, 4};
	int k = 2;
	std::vector <int> ans(topFrequent(nums, k));
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << "\t";
	}
	std::cout << std::endl;
	return 0;
}