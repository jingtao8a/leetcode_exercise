#include <iostream>
#include <vector>
using namespace std;

int low_bound(vector<int>& num, int key)
{
	int start = 0, end = num.size();
	int mid;
	while (start < end) {
		mid = (end - start) / 2 + start;
		if (num[mid] >= key) 
			end = mid;
		else
			start++;
	}
	return end;
}

int upper_bound(vector<int>& num, int key)
{
	int start = num.size() - 1, end = -1;
	int mid;
	while (start > end) {
		mid = start - (start - end) / 2;
		if (num[mid] <= key)
			end = mid;
		else
			start--;
	}
	return end;
}

int main()
{
	vector<int> num{1, 2, 4, 5, 5, 5, 5, 7, 8, 9};
	cout << low_bound(num, 5) << " " << upper_bound(num, 5);
 	return 0;
}
