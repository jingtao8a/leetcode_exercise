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

void quick_sort(std::vector<int>& nums, int first, int last)
{
	if (first >= last) {
		return;
	}
	int mid = partition(nums, first, last);
	quick_sort(nums, first, mid - 1);
	quick_sort(nums, mid + 1, last);
}

int main()
{
	std::vector<int> nums = {43, 23, 41, 90, 67, 52};
	quick_sort(nums, 0, 5);
	std::vector<int>::iterator begin  = nums.begin(), end = nums.end();
	while(begin != end) {
		std::cout << *begin << "\t";
		++begin;
	}
	return 0;
}