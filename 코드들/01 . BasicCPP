#include <iostream>
using namespace std;

void func(int* m, int row, int col);	// function declaration
										// function prototype

int g_count = 0;
void func2()
{
	cout << "count = " << g_count << endl;
	g_count++;
	func2();					 
}

int main()
{
	func2();				// stack overflow
	// row, col
	const int row = 3;
	const int col = 5;
	int m[row][col];
	int* p = &(m[0][0]);
	func(p, row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			m[i][j] = i + j;
			p[i * col + j] = i + j;
		}
	for (int k = 0; k < row * col; k++)
	{
		p[k] = k;						// statements
		int i = k / col;
		int j = k % col; 
		m[i][j] = k;
	}

	int** darr = (int **)malloc(row*sizeof(int*));
	for(int i = 0; i<row; i++)
		darr[i] = (int*)malloc(col * sizeof(int));

	int** darr2 = new int* [row];
	for (int i = 0; i < row; i++)
		darr2[i] = new int[col];
	
	for (int i = 0; i < row; i++)
		free(darr[i]);
	free(darr);
	
	for (int i = 0; i < row; i++)
		delete[] darr2[i];
	delete[] darr2;

	return 0;
}

void func(int* m, int row, int col)
{										// function definition

}
