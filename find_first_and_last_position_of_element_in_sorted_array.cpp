#include <vector>
#include <iostream>

int lower_bound(std::vector<int>& nums, int target)
{
	int l = 0, r = nums.size(), mid;//[ )
	while(l < r) {
		mid = l + (r - l) / 2;
		if (nums[mid] >= target) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return r;
}

int upper_bound(std::vector<int>& nums, int target)
{
	int l = -1, r = nums.size() - 1, mid;//( ]
	while(l < r) {
		mid = r - (r - l) / 2;
		if (nums[mid] <= target) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l;
}

std::vector<int> find_in_sorted_array(std::vector<int>& nums, int target)
{
	if (nums.empty()) return std::vector<int>{-1, -1};
	int lower = lower_bound(nums, target);
	int upper = upper_bound(nums, target);
	if (lower == nums.size() || nums[lower] != target) {
		return std::vector<int>{-1, -1};
	}
	return std::vector<int>{lower, upper};
}

int main()
{
	std::vector<int> nums = {5, 7, 7, 8, 8, 10};
	int target = 8;
	std::vector<int> res = find_in_sorted_array(nums, target);
	std::cout << res[0] << "\t" << res[1];
	return 0;
}
