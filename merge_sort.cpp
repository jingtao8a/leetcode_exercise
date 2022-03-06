#include <iostream>
#include <vector>

void merge(std::vector<int>& nums, int l, int mid, int r)
{
	int f1 = l, l1 = mid, f2 = mid + 1, l2 = r;
	std::vector<int> tmp(nums.size(), 0);
	int pos = l;
	while(f1 <= l1 && f2 <= l2) {
		if (nums[f1] < nums[f2]) {
			tmp[pos++] = nums[f1++];
		} else {
			tmp[pos++] = nums[f2++];
		}
	}
	while(f1 <= l1) {
		tmp[pos++] = nums[f1++];
	}
	while(f2 <= l2) {
		tmp[pos++] = nums[f2++];
	}
	for(int i = l; i <= r; i++) {
		nums[i] = tmp[i];
	}
}

void merge_sort(std::vector<int>& nums, int l, int r)
{
	if (l >= r) return;
	int mid = (l + r) / 2;
	merge_sort(nums, l, mid);
	merge_sort(nums, mid + 1, r);
	merge(nums, l, mid, r);
}

int main()
{
	std::vector<int> nums = {43, 23, 41, 90, 67, 52};
	merge_sort(nums, 0, 5);
	std::vector<int>::iterator begin  = nums.begin(), end = nums.end();
	while(begin != end) {
		std::cout << *begin << "\t";
		++begin;
	}
	return 0;
}
