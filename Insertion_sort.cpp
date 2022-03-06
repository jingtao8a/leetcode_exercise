#include <iostream>
#include <vector>

void insert_sort(std::vector<int>& nums)
{
	int size = nums.size();
	int tmp, i, j;
	for(i = 1; i < size; i++) {
		tmp = nums[i];
		for(j = i - 1; j >= 0; j--) {
			if (nums[j] > tmp) nums[j + 1] = nums[j];
			else break;
		}
		nums[j + 1] = tmp;
	}
}

int main()
{
	std::vector<int> nums = {43, 23, 41, 90, 67, 52};
	insert_sort(nums);
	std::vector<int>::iterator begin  = nums.begin(), end = nums.end();
	while(begin != end) {
		std::cout << *begin << "\t";
		++begin;
	}
	return 0;
}