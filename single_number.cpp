#include <iostream>
#include <vector>

using namespace std;

unsigned int single_num(vector<unsigned int>& num)
{
	unsigned int ans = 0;
	for (int i = 0; i < num.size(); ++i) {
		ans ^= num[i];
	}
	return ans;
}

int main()
{
	vector<unsigned int> num{4, 1, 2, 1, 2};
	cout << single_num(num);
 	return 0;
}
