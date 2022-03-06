#include <iostream>

using namespace std;

const int tmp = 0B01010101010101010101010101010101;

bool is_power_of_four(int val)
{
	return (val > 0) && (((val - 1) & val) == 0) && (tmp & val);
}

int main()
{	
	cout << is_power_of_four(63);
 	return 0;
}
