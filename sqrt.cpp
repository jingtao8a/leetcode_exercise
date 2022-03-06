#include <iostream>

int sqrt(int x)
{
	if (x == 0) return 0;
	int l = 1, r = x, mid, rest;
	while(l <= r) {
		mid = (l + r) / 2;
		rest = x / mid;
		if (rest == mid) {
			return mid;
		} else if (mid > rest) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return -1;
}

int main()
{
	std::cout << sqrt(1);
	return 0;
}