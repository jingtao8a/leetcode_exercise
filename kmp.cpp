#include <iostream>
#include <string>
#include <vector>
using namespace std;

void get_next(string& b, vector<int>& next)
{
	next[0] = -1;
	next[1] = 0;
	for (int i = 2; i < next.size(); ++i) {
		int k = next[i - 1];
		bool flag = false;
		while (k != -1) {
			if (b[k] == b[i - 1]) {
				next[i] = next[i - 1] + 1;
				flag = true;
				break;
			}
			k = next[k];
		}
		if (flag == false) {
			next[i] = 0;
		}
	}
}

int kmp(string& a, string& b, vector<int>& next)
{
	get_next(b, next);
	int i = 0, j = 0;
	while ((int)i < (int)a.length() && (int)j < (int)b.length()) {
		if (j == -1) {
			++i;
			++j;	
		} else if (a[i] == b[j]) {
			++i;
			++j;
		} else {
			j = next[j];
		}
	}
	
	if (j == b.length())
		return i - j;
	else
		return -1;
}           
  
int main()
{
	string a("abcaabbc");
	string b("aabb");
	vector<int> next(b.size());
	int i = kmp(a, b, next);
 	cout << i;
	return 0;
}
