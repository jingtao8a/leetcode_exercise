#include <iostream>
#include <vector>
using namespace std;
string convert(string s, int numRows) {
        int n = s.length();
        int col = n / (numRows + numRows - 2) * (1 + numRows - 2);
        int rest = n % (numRows + numRows - 2);
        if (rest <= numRows) {
            col = col + 1;
        } else {
            col  = col + rest - numRows + 1;
        }
        vector<vector<char>> matrix (numRows, vector<char>(col, -1));
        int i = 0, j = 0;
        int x = 0;
        while (x < s.length()) {
            int count = numRows;
            while (count-- && x < s.length()) {
                matrix[i][j] = s[x];
                ++x;
                ++i;
            }
            count = numRows - 2;
            i = i - 2;
            j++;
            while (count-- && x < s.length()) {
                matrix[i][j] = s[x];
                --i;
                ++j;
                ++x;
            }
        }
        string str;
        for (i = 0; i < matrix.size(); ++i) {
            for (j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] != -1) {
                    str += matrix[i][j];
                }
            }
        }
        return str;
    }
    
int main()
{
	string s("PAYPALISHIRING");
	string str = convert(s, 3);
	cout << str;
 	return 0;
}
