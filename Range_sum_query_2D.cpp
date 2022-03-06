#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix{
{3, 0, 1, 4, 2},
{5, 6, 3, 2, 1},
{1, 2, 0, 1, 5},
{4, 1, 0, 1, 7},
{1, 0, 3, 0, 5}
};

class NumMatrix{
	vector<vector<int>> num_matrix;
	public:
		NumMatrix(vector<vector<int>>& matrix) : num_matrix(matrix.size(), vector<int>(matrix[0].size(), 0))
		{
			int row = num_matrix.size(), col = num_matrix[0].size();
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					num_matrix[i][j] = matrix[i][j];
					if (i - 1 >= 0) {
						num_matrix[i][j] += num_matrix[i - 1][j];
					}
					if (j - 1 >= 0) {
						num_matrix[i][j] += num_matrix[i][j - 1];
					}
					if (i - 1 >= 0 && j - 1 >= 0) {
						num_matrix[i][j] -= num_matrix[i - 1][j - 1];
					}
				}
			}
		}
		
		int sumRegion(int x1, int y1, int x2, int y2)
		{
			return num_matrix[x2][y2] - (num_matrix[x2][y1 - 1] + num_matrix[x1 - 1][y2] - num_matrix[x1 - 1][y1 - 1]);
		}
};

int main()
{
	NumMatrix num(matrix);
	cout << num.sumRegion(2, 1, 4, 3) << endl;
	cout << num.sumRegion(1, 1, 2, 2) << endl;
	return 0;
}
