// 输出一个旋转矩阵 


#include <iostream>

using namespace std;

const int num = 5;

void FullRotationMatrix( int matrix[][num], int start_num, int arr_size, int loop )
{
	if( num / 2 < loop )
	{
		return;
	}

	matrix[loop][loop] = start_num;

	for( int i = loop + 1; i < num - loop; i++ )
	{
		matrix[i][loop] = matrix[i - 1][loop] + 1;
	}
	for( int j = loop + 1; j < num - loop; j++ )
	{
		matrix[num - loop - 1][j] = matrix[num - loop - 1][j - 1] + 1;
	}
	for( int i = num - loop - 2; i >= loop; i-- )
	{
		matrix[i][num - loop - 1] = matrix[i + 1][num - loop - 1] + 1;
	}
	for( int j = num - loop - 2; j > loop; j-- )
	{
		matrix[loop][j] = matrix[loop][j + 1] + 1;
	}
	int temp = loop + 1;

	FullRotationMatrix( matrix, matrix[loop][loop + 1] + 1, arr_size, temp );
}

void OutPutRotationMatrix()
{

	int rotation_matrix[num][num] = { 0 };

	FullRotationMatrix( rotation_matrix, 1, num, 0 );

	for( int i = 0; i < num; i++ )
	{
		for( int j = 0; j < num; j++ )
		{
			cout << rotation_matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int main( int argc, char *argv[] )
{
	OutPutRotationMatrix();

	return 0;
}