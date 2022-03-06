#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

const int n = 8;

vector<bool> col_sign(n, false);
vector<bool> minus_sign(n * 2 - 1, false);
vector<bool> plus_sign(n * 2 - 1, false);

vector<pair<int, int>> tmp(n);

int count = 0;

void dfs(int k)
{
	if (k == n) {
		std::cout << "NO " << ++count << "\n";
		vector<vector<string>> map(n, std::vector<string>(n, ". "));
		for (int i = 0; i < tmp.size(); ++i) {
			map[tmp[i].first][tmp[i].second] = "Q ";
		}
		for (int i = 0; i < map.size(); ++i) {
			for (int j = 0; j < map[i].size(); ++j) {
				std::cout << map[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "NO " << count << " END" << "\n" << std::endl;
		return;	
	}
	for (int col = 0; col < n; ++col) {
		if (col_sign[col] == false && minus_sign[k + col] == false && plus_sign[col - k + n - 1] == false) {
			col_sign[col] = true;
			minus_sign[k + col] = true;
			plus_sign[col - k + n - 1] = true;
			tmp[k] = std::pair<int, int>(k, col);
			
			dfs(k + 1);
			
			col_sign[col] = false;
			minus_sign[k + col] = false;
			plus_sign[col - k + n - 1] = false;
		}
	}
}

void n_queue()
{
	dfs(0);
}

int main()
{
	n_queue();
	return 0;
}