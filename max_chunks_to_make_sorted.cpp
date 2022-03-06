#include <iostream>
#include <vector>
#define MINUS_INF -99999
using namespace std;

int max_chunk(vector<int>& num)
{
	int count = 0, max_n = MINUS_INF;
	for (int i = 0; i < num.size(); ++i) {
		max_n = max(max_n, num[i]);
		if (max_n == i) {
			count++;
			max_n = MINUS_INF;
		} 
	}
	return count;
}

int main()
{
	vector<int> num{1, 0, 2, 3, 4};
 	cout << max_chunk(num);
	return 0;
}
