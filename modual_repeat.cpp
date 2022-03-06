#include <iostream>

using namespace std;

int main()
{
	long a = 5, b = 8, m = 10;
	long tmp = a % m;
	long ans = 1;
	while(b) {
		if (b & 1) {
			ans = (ans * tmp) % m;
		}
		b = b >> 1;
		tmp = (tmp * tmp) % m; 
	}
	cout << ans;
 	return 0;
}
