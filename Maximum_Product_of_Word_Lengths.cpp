#include <iostream>
#include <vector>
#include <string>

using namespace std;
int max(int x, int y)
{
	return x > y ? x : y;
}
int maximum_product(vector<string>& wordlist)
{
	vector<int> sign(wordlist.size(), 0);
	for (int i = 0; i < wordlist.size(); ++i) {
		for (int j = 0; j < wordlist[i].length(); ++j) {
			sign[i] |= 1 << (wordlist[i][j] - 'a');
		}
	}
	int ans = 0;
	for (int i = 0; i < wordlist.size() - 1; ++i) {
		for (int j = i + 1; j < wordlist.size(); ++j) {
			if ((sign[i] & sign[j]) == 0) {
				ans = max(ans, wordlist[i].length() * wordlist[j].length());
			}
		}
	}
	return ans;
}

int main()
{
	vector<string> worldlist{"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
	cout << maximum_product(worldlist);	
 	return 0;
}
