#include <iostream>
#include <vector>

using namespace std;

int count_primes(int n)
{
	vector<bool> num(n + 1, true);
	num[0] = num[1] =false;
	for (int i = 2; i <= n; ++i ) {
		for (int k = 2; k * i <= n; ++k) {
			num[k * i] = false;
		}
	}
	int sum = 0;
	for (int i = 0; i <= n; ++i) {
		if (num[i]) 
			++sum;
	}
	return sum;
}

int main()
{
	int n = 10;
	cout << count_primes(n);
 	return 0;
}
