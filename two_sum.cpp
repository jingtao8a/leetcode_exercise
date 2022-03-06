#include <vector>
#include <iostream>

std::vector<int> find_target(int target, std::vector<int>& array)
{
	int i = 0, j = array.size() - 1;
	std::vector<int> ans(2, 0);
	while (i < j) {
		if (array[i] + array[j] == target) {
			ans[0] = i + 1;
			ans[1] = j + 1;
			break;
		} else if (array[i] + array[j] > target) {
			j--;
		} else {
			i++;
		}
	}
	return ans;
}

int main()
{
	std::vector<int> array = {2, 7, 11, 15};
	std::vector<int> res = find_target(9, array);
	std::cout << res[0] << "\t" << res[1];
	return 0;
}