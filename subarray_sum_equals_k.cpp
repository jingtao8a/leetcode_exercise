#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& num, int k)
{
	int count = 0, psum = 0;
	unordered_map<int, int> hashmap;
	hashmap[0] = 1;
	for (int i : num) {
		psum += i;
		++hashmap[psum];
		if (psum >= k)
			count += hashmap[psum - k];
	}
	return count;
}

int main()
{
	vector<int> num{1, 1, 1};
	int k = 2;
	cout << subarraySum(num, k);
 	return 0;
}
