#include <iostream>
#include <vector>
using namespace std;
void swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}

int partition(vector<int>& num, int low, int high) {
	int pre = low, cur = low;
	int key = num[high];
	while (cur < high) {
		if (num[cur] < key) {
			swap(num[cur], num[pre]);
			++pre;
		}
		++cur;
	}
	swap(num[cur], num[pre]);
	return pre;
}

void qsort(vector<int>& num, int low, int high) {
	if (low >= high) return;
	int mid = partition(num, low, high);
	qsort(num, low, mid - 1);
	qsort(num, mid + 1, high);
}

int main()
{
	vector<int> num{887, 32, 2, 1, 0, 83};
	qsort(num, 0, num.size() - 1);
 	for (int i : num) {
 		cout << i << " ";
	}
	cout << endl;
	return 0;
}
