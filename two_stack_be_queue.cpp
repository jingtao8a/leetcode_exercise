#include <iostream>
#include <vector>
std::vector<int> stack1, stack2;

void push(int x)
{
	stack1.push_back(x);
}

int pop()
{
	for (int i = stack1.size() - 1; i >= 0; i--) {
		stack2.push_back(stack1[i]);
		stack1.pop_back();
	}
	int tmp = stack2[stack2.size() - 1];
	stack2.pop_back();
	for (int i = stack2.size() - 1; i >= 0; i--) {
		stack1.push_back(stack2[i]);
		stack2.pop_back();
	}
	return tmp;
}

int main()
{
	std::vector<int> nums{1, 3, 4, 5};
	for (int i = 0; i < nums.size(); i++) {
		push(nums[i]);
	}
	for (int i = 0; i < nums.size(); i++) {
		std::cout << pop() << std::endl;
	}
	return 0;	
}