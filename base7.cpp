#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

string base7(ll num)
{
	vector<char> tmp1, tmp2;
	while (num) {
		tmp1.push_back(num % 7 + '0');
		num = num / 7;
	}
	while (!tmp1.empty()){
		tmp2.push_back(tmp1.back());
		tmp1.pop_back();
	}
	return string(tmp2.begin(), tmp2.end());
}
int main()
{
	ll num = 100;
	string ans = base7(num);
	cout << ans;	
 	return 0;
}
