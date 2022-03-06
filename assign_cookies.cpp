#include <vector>
#include <algorithm>
#include <iostream>

int findContentChildren(std::vector<int>& children, std::vector<int>& cookies)
{
	std::sort(children.begin(), children.end());
	std::sort(cookies.begin(), cookies.end());
	int child = 0, cookie = 0;
	while (child < children.size() && cookie < cookies.size()) {
		if (children[child] <= cookies[cookie]) {
			child++;
			cookie++;
		} else {
			cookie++;
		}
	}
	return child;
}

int main()
{
	std::vector<int> children = {1, 2}, cookies = {1, 2, 3};
	std::cout << findContentChildren(children, cookies);
	return 0;
}