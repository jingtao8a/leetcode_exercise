#include <iostream>
#include <vector>
#include <numeric>

int Candy(std::vector<int>& ratings)
{
	int size = ratings.size();
	if (size == 1) {
		return 1;
	}
	int i;
	std::vector<int> num(size, 1);
	for (i = 1; i < size; i++) {
		if (ratings[i] > ratings[i - 1]) {
			num[i] = num[i - 1] + 1;
		}
	}
	for (i = size - 2; i >= 0; i--) {
		if (ratings[i] > ratings[i + 1] && num[i] <= num[i + 1]) {
			num[i] = num[i + 1] + 1;
		}
	}
	return std::accumulate(num.begin(), num.end(), 0);
}

int main()
{
	std::vector<int> ratings{1, 0, 2};
	std::cout << Candy(ratings);
	return 0;
}