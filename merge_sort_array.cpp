#include <iostream>
#include <vector>

void merge_sort(std::vector<int>& array1, int m, std::vector<int>& array2, int n)
{
	int pos = m + n - 1;
	m--, n--;
	while(m >= 0 && n >= 0) {
		if (array1[m] > array2[n]) {
			array1[pos--] = array1[m--];
		} else {
			array1[pos--] = array2[n--];
		}
	}
	while (n >= 0) {
		array1[pos--] = array2[n--];
	}
}

int main()
{
	std::vector<int> array1 = {1, 2, 3, 0, 0, 0}, array2 = {2, 5, 6};
	merge_sort(array1, 3, array2, 3);
	for (int i = 0; i < array1.size(); i++) {
		std::cout << array1[i] << "\t";
	}
	return 0;
}