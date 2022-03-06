#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(std::vector<int>& obj1, std::vector<int>& obj2)
{
	return (obj1[1] < obj2[1]);
}

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
{
	std::sort(intervals.begin(), intervals.end(), cmp);
	int i;
	/*for (i = 0; i < intervals.size(); i++) {
		std::cout << intervals[i][0] << "\t" << intervals[i][1];
		std::cout << "\n";
	}*/
	int total = 0, prev = intervals[0][1];
	for (i = 1; i < intervals.size(); i++) {
		if (intervals[i][0] < prev) {
			++total;
		} else {
			prev = intervals[i][1];
		}
	}
	return total;
}

int main()
{
	std::vector<std::vector<int>> intervals = {{1, 2}, {2, 4}, {1, 3}};
	std::cout << eraseOverlapIntervals(intervals);
	return 0;
}