#include <iostream>

using namespace std;

int reverse_bits(int val)
{
	int ans = 0;
	int tmp;
	for (int i = 0; i < 32; ++i)
	{
		tmp = val & 1;
		ans = ans << 1;
		ans = ans + tmp;
		val = val >> 1;
	}
	return ans;
}

int main()
{
	int value = 43261596;
	cout << reverse_bits(value);
 	return 0;
}
