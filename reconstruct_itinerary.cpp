#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

vector<string> findItinerary(vector<vector<string>>& input)
{
	vector<string> ans;
	if (input.empty()) return ans;
	unordered_map<string, set<string>> hash;
	for (vector<string>& it : input) {
		hash[it[0]].insert(it[1]);
	}
	stack<string> s;
	s.push("JFK");
	while (!s.empty()) {
		string next = s.top();
		if (hash[next].empty()) {
			ans.push_back(next);
			s.pop();
		} else {
			s.push(*hash[next].begin());
			hash[next].erase(hash[next].begin());
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	vector<vector<string>> input{{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
	vector<string> output = findItinerary(input);
	for (auto& it : output) {
		cout << it << " ";
	}
	cout << endl;
 	return 0;
}
