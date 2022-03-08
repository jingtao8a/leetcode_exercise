#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& num, int x, int y) {
	int tmp = num[x];
	num[x] = num[y];
	num[y] = tmp;
}

void permutation(vector<int>& num, int k)
{
	if (k == num.size()) {
		for (int i = 0; i < num.size(); ++i) {
			cout << num[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = k; i < num.size(); ++i) {
		swap(num, i, k);
		permutation(num, k + 1);
		swap(num, k, i);
	}
}

int main()
{
	vector<int> num{1, 2, 3};
	permutation(num, 0);
 	return 0;
}
