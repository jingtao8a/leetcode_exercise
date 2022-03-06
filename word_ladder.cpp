#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

string beginword("hit"), endword("cog");
vector<string> wordlist{"hit", "hot", "dot", "dog", "lot", "log", "cog"};
unordered_map<string, bool> sign;

int bfs()
{
	for (int i = 0; i < wordlist.size(); ++i) {
		sign[wordlist[i]] = false;
	}
	queue<string> q;
	
	sign[beginword] = true;
	q.push(beginword);
	int level = 0, width;
	while (!q.empty()) {
		width = q.size();
		while (width--) {
			string word = q.front(); 
			q.pop();
			string newword;
			for (int i = 0; i < word.size(); ++i) {
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					if (word[i] != ch) {
						newword = word;
						newword[i] = ch;
						if (newword == endword) {
							return level + 1;		
						}
						if (sign.find(newword) != sign.end() && sign[newword] == false) {
							sign[newword] = true;
							q.push(newword);
						}
					}
				}
			}
		}
		++level;
	}
	return -1;
}

vector<string> path;

//deep search find all route
void dfs(int length, string word, vector<vector<string>>& ans)
{
	if (word == endword) {
		ans.push_back(path);
		return;
	}
	
	for (int i = 0; i < word.size(); ++i) {
		for (char ch = 'a'; ch <= 'z'; ++ch) {
			if (word[i] != ch) {
				string newword = word;
				newword[i] = ch;
				if (sign.find(newword) != sign.end() && sign[newword] == false) {
					sign[newword] = true;
					path.push_back(newword);
					dfs(length, newword, ans);
					sign[newword] = false;
					path.pop_back();
				}
			}
		}
	}
}

void find_all_path(int length)
{
	for (int i = 0; i < wordlist.size(); ++i) {
		sign[wordlist[i]] = false;
	}
	vector<vector<string>> ans;
	
	sign[beginword] = false;
	path.push_back(beginword);
	dfs(length, beginword, ans);
	
	for (int i = 0; i < ans.size(); ++i) {
		if (ans[i].size() == length + 1) {
			for (int j = 0; j < ans[i].size(); ++j) {
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
	}
}

int main()
{
	int length = bfs();
	find_all_path(length);
	return 0;
}