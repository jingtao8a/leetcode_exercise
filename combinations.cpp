#include <iostream>
#include <vector>

void display(std::vector<int>& tmp)
{
	std::vector<int>::iterator it = tmp.begin();
	while (it != tmp.end()) {
		std::cout << *it << "\t";
		++it;
	}
	std::cout << std::endl;
}

int begin(int current, std::vector<int>& tmp)
{
	if (current == 0) return 1;
	else return tmp[current - 1] + 1;
}

void combinations(int n, int k, std::vector<int>& tmp, int current, std::vector<bool>& sign)
{
	if (current >= k) {
		display(tmp);
		return;
	}
	for (int i = begin(current, tmp); i <= n; ++i) {
		if (sign[i] == false) {
			tmp[current] = i;
			sign[i] = true;
			combinations(n, k, tmp, current + 1, sign);
			sign[i] = false;
		}
	}
}

int main()
{
	int n = 4, k = 3;
	std::vector<int> tmp(k, 0);
	std::vector<bool> sign(n, false);
	combinations(n, k, tmp, 0, sign);
	return 0;
}
