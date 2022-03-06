#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string s("applepenapple");
unordered_set<string> wordDict{"apple", "pen"};

vector<bool> dp(s.size(), false);

bool work_break()
{
	string sub;
	sub = s.substr(0, 1);
	if (wordDict.count(sub)) {
		dp[0] = true;
	}
	for (int i = 1; i < dp.size(); ++i) {
		sub = s.substr(0, i + 1);
		if (wordDict.count(sub)){
			dp[i] = true;
			continue;
		}
		
		for (int j = 0; j < i; ++j) {
			if (dp[j] == true) {
				sub = s.substr(j + 1, i - j);
				if (wordDict.count(sub)) {
					dp[i] = true;
					break; 
				}
			}
		}
	}
	for (int i = 0; i < dp.size(); ++i) {
		cout << dp[i] << " ";
	}
	cout << endl;
	return dp.back();
}

int main()
{
	cout << work_break();	
	return 0;
}