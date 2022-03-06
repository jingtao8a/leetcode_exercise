#include <iostream>
#include <vector>

int partition(std::vector<int>& nums, int first, int last)
{
	int tmp = nums[first];
	int l = first, r = last;
	while(l < r) {
		while(l < r && nums[r] >= tmp) {
			r--;
		}
		nums[l] = nums[r];
		while(l < r && nums[l] <= tmp) {
			l++;
		}
		nums[r] = nums[l];
	}
	nums[l] = tmp;
	return l;
}

int findKthLargest(std::vector<int>& nums, int k)
{
	int l = 0, r = nums.size() - 1, target = nums.size() - k;
	int mid;
	while(l <= r) {
		mid = partition(nums, l, r);
		if (mid == target) {
			return nums[target];
		} else if (mid < target) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return -1;
}

int main()
{
	std::vector<int> nums = {3, 2, 1, 5, 6, 4};
	int k = -1;
	std::cout << findKthLargest(nums, k);
	return 0;
}
