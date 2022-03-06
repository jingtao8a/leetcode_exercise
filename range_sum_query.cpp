#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class NumArray{
	vector<int> psum;
	public:
		NumArray(vector<int>& nums) : psum(nums.size() + 1, 0)
		{
			partial_sum(nums.begin(), nums.end(), psum.begin() + 1);
		}
		
		int sumRange(int i, int j)
		{
			return psum[j + 1] - psum[i];
		}
};

int main()
{
	vector<int> nums{-2, 0, 3, -5, 2, -1};
	NumArray* num_array = new NumArray(nums);
	cout << num_array->sumRange(0, 2);
	cout << num_array->sumRange(1, 5);
 	return 0;
}
