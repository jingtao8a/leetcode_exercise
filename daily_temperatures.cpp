#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	vector<int> temperature{73, 74, 75, 71, 69, 72, 76, 73};
	stack<int> s;
	vector<int> res(temperature.size(), 0);
	for (int i = 0; i < temperature.size(); ++i) {
		if (s.empty()) {
			s.push(i);
		} else {
			if (temperature[i] > temperature[s.top()]) {
				res[s.top()] = i - s.top();
				s.pop();
				--i;		
			} else {
				s.push(i);
			}
		}
	}
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
 	return 0;
}
