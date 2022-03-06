#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int max(int x, int y) 
{
	return x > y ? x : y;
}
int add_string(string num1, string num2)
{
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	vector<char> tmp;
	
	int n = max(num1.length(), num2.length());
	int carry = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (i < num1.length()) {
			sum += num1[i] - '0';
		} 
		if (i < num2.length()) {
			sum += num2[i] - '0';
		}
		sum += carry;
		if (sum >= 10) {
			carry = 1;
			tmp.push_back(sum % 10 + '0');
		} else {
			carry = 0;
			tmp.push_back(sum + '0');
		}
		sum = 0;
	}
	if (carry) {
		tmp.push_back('1');
	}
	string ans(tmp.begin(), tmp.end());
	reverse(ans.begin(), ans.end());
	return stoi(ans);
}

int main()
{
	string num1("99"), num2("1");
	int ans = add_string(num1, num2);
	cout << ans;
 	return 0;
}
