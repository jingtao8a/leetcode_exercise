#include <iostream>
#include <vector>
#include <string>

std::string minWindow(std::string S, std::string T)
{
	std::vector<int> chars(128, 0);
	std::vector<bool> flag(128, false);
	for (int i = 0; i < T.size(); i++) {
		flag[T[i]] = true;
		++chars[T[i]];
	}
	int min_l = 0, min_size = S.size() + 1;
	int cnt = 0, l = 0;
	for (int r = 0; r < S.size(); ++r) {
		if (flag[S[r]]) {
			--chars[S[r]];
			if (chars[S[r]] >= 0) {
				++cnt;
			}
			while (cnt == T.size()) {
				if (r - l + 1 < min_size) {
					min_size = r - l + 1;
					min_l = l;
				}
				if (flag[S[l]] && ++chars[S[l]] > 0) {
					--cnt;
				}
				++l;
			}
		}
	}
	return S.substr(min_l, min_size);
}

int main()
{
	std::string S = "ADOBECODEBANC", T = "ABC";	
	std:: string res = minWindow(S, T);
	std::cout << res;
	return 0;
}