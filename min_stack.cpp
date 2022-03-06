#include <iostream>
#include <stack>
using namespace std;

class minstack{
	stack<int> s;
	stack<int> s_min;
	public:
		void push(int val)
		{
			s.push(val);
			if (s_min.empty()) {
				s_min.push(val);	
			} else {
				if (s_min.top() > val)
					s_min.push(val);
			}
		}
		
		int pop()
		{
			int tmp = s.top();
			if (tmp == s_min.top())
				s_min.pop();
			s.pop();
			return tmp;
		}
		
		int getmin()
		{
			return s_min.top();
		}
		
};

int main()
{
	minstack s;
	s.push(-2);
	s.push(0);
	s.push(-3);
	cout << s.getmin();
	s.pop();
	cout << s.getmin();
 	return 0;
}
