#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix{
{1, 2, 3},
{4, 5, 6},
{7, 8, 9}
};

void rotate_matrix()
{
	int i, j, n = matrix.size() - 1;
	int tmp;
	for (i = 0; i <= n / 2; ++i ) {
		for (j = 0; j <= n - n / 2 - 1; ++j) {
			tmp = matrix[i][j];
			matrix[i][j] = matrix[n - j][i];
			matrix[n - j][i] = matrix[n - i][n - j];
			matrix[n - i][n - j] = matrix[j][n - i];
			matrix[j][n - i] = tmp;
		}
	}
}

int main()
{
	rotate_matrix();
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[i].size(); ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
 	return 0;
}
