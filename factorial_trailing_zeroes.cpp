#include <iostream>

using namespace std;

int find(int x, int y)
{
	int sum = 0;
	while (x % y == 0) {
		x /= y;
		++sum;
	}
	return sum;
}

int factorial_zeroes(int n)
{
	int count2 = 0, count5 = 0;
	for (int i = 2; i <= n; ++i) {
		count2 += find(i, 2);
		count5 += find(i, 5);
	}
	return count2 > count5 ? count5 : count2;
}

int main()
{
	int n = 12;
	cout << factorial_zeroes(n);
 	return 0;
}
