#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solve_exp(string input)
{
	vector<int> ans;
	for (int i = 0; i < input.size(); ++i) {
		char ch = input[i];
		if (ch == '+' || ch == '-' || ch == '*') {
			vector<int> left = solve_exp(input.substr(0, i));
			vector<int> right = solve_exp(input.substr(i + 1));
			for (int j = 0; j < left.size(); ++j) {
				for (int k = 0; k < right.size(); ++k) {
					switch(ch) {
						case '+':
							ans.push_back(left[j] + right[k]);
							break;
						case '-':
							ans.push_back(left[j] - right[k]);
							break;
						case '*':
							ans.push_back(left[j] * right[k]);
							break;
					}
				}
			}
		}
	}
	if (ans.empty()) ans.push_back(stoi(input));
	return ans;
}

int main()
{
	string input("2-1-1");
	vector<int> ans = solve_exp(input);	
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
 	return 0;
}
