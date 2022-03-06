#include <iostream>
#include <vector>

void dfs(std::vector<int>& nums, std::vector<bool>& sign, int k, std::vector<int>& stack)
{
	if (k == nums.size()) {
		for(int j = 0; j < stack.size(); j++) {
			std::cout << stack[j] << "\t";
		}
		std::cout << std::endl; 
		return;
	}
	for (int i = 0; i < sign.size(); i++) {
		if (sign[i] == false) {
			sign[i] = true;
			stack.push_back(nums[i]);
			dfs(nums, sign, k + 1, stack);
			sign[i] = false;
			stack.pop_back();
		}
	}
}

int main()
{
	std::vector<int> nums{1, 2, 3};
	std::vector<bool> sign(nums.size(), false);
	std::vector<int> stack;
	dfs(nums, sign, 0, stack);
	return 0;
}