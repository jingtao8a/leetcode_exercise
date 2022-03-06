#include <iostream>
#include <stack>

using namespace std;

class myqueue{
	stack<int> s1;
	stack<int> s2;
	public:
		void push_que(int val)
		{
			s1.push(val);
		}
		int pop_que()
		{
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			int tmp = s2.top();
			s2.pop();
			while (!s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
			return tmp;
		}
};

int main()
{
	myqueue q;
	q.push_que(1);
	q.push_que(2);
	q.push_que(3);
	cout << q.pop_que() << " " << q.pop_que() << " " << q.pop_que() << endl;
 	return 0;
}
