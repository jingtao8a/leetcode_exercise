#include <iostream>

using namespace std;
int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int xgcd(int a, int b, int& x, int& y)
{
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int x1, y1;
	int gcd = xgcd(b, a % b, x1, y1);
	x = y1, y = x1 - a / b * y1;
	return gcd;
}
int main()
{
	int s, t;
	cout << xgcd(15, 5, s, t) << "\n";
	cout << s << " " << t << endl;
 	return 0;
}
