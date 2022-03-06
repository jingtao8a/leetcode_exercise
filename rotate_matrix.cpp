#include <cstdio>

void test(int n)
{
	int matrix[n][n];
	int index = 1;
	int row = 0, col = 0, row_center = (n - 1) / 2, col_center = (n - 1) / 2;
	int length;
	int i, j;
	while(row <= row_center && col <= col_center){
		length = n - 2 * row;
		for(j = col; j < col + length; j++){
			matrix[row][j] = index++;
		}
		if(length == 1) break;
		for(i = row + 1; i < row + length - 1; i++){
			matrix[i][col + length - 1] = index++;
		}
		for(j = col + length - 1; j >= col; j--){
			matrix[row + length - 1][j] = index++;
		}
		for(i = row + length - 2; i >= row + 1; i--){
			matrix[i][col] = index++;
		}
		++row;
		++col;
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			std::printf("%d\t", matrix[i][j]);
		}
		std::printf("\n");
	}
}
int main()
{
	int n = 5;
	test(n);
	return 0;
}