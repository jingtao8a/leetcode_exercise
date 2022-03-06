#include <iostream>
#include <stack>
using namespace std;

bool judge(string str)
{
	stack<char> s;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			s.push(str[i]);
		} else {
			if (s.empty()) return false;
			switch (str[i]) {
				case ']':
					if (s.top() == '[')
						s.pop();
					else
						return false;
					break;
				case '}':
					if (s.top() == '{')
						s.pop();
					else
						return false;
					break;
				case ')':
					if (s.top() == '(')
						s.pop();
					else
						return false;
					break;
			}
		}
	}
	return s.empty();
}

int main()
{
	string str("{[]}()");
 	cout << judge(str);
	return 0;
}
