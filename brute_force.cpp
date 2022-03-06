#include <iostream>
#include <string>
using namespace std;

string a("abcabc");
string b("cab");
int brute_force(string& a, string& b)
{
	int i = 0, j = 0;
	while (i < a.length() && j < b.length()) {
		if (a[i] == b[j]) {
			++i;
			++j;
		} else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == b.length()) 
		return i - j;
	else 
		return -1;
}
int main()
{
	int i = brute_force(a, b);
 	cout << i;
	 return 0;
}
