#include <iostream>

using namespace std;

bool power_of_three(int n)
{
	while (n % 3 == 0) {
		n /= 3;
	}
	if (n == 1) {
		return true;
	} else {
		return false;
	}
}

int main()
{
	cout << power_of_three(26);
 	return 0;
}
