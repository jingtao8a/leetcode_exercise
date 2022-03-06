#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target)
{
	int start = 0, end = nums.size() - 1, mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (nums[mid] == target) {
			return mid + 1;
		} else if (nums[mid] <= nums[start]) {
			//right interval
			if (target > nums[mid] && target <= nums[end]) {
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		} else {
			//left interval
			if (target >= nums[start] && target < nums[mid]) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}
	}
	return -1;
}

int main()
{
	std::vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
	int target = 2;
	std::cout << search(nums, target);
	return 0;
}
