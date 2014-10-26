// 0-9里面的数字 任意组合 组合成4个分别是 一位数 两位数 三位数 四位数 ( 1 + 2 + 3 + 4 = 10 )   四个数字
// 然后如果这一组数字里面4个数字都是完全平方数 则输出


#include <iostream>
#include <cmath>

using namespace std;

bool IsPrefectSquareGroup( int data1, int data2, int data3, int data4 )
{
	int check_prefect_square_group[10] = { 0 };
	check_prefect_square_group[data1] = 1;

	check_prefect_square_group[data2 / 10] = 1;
	check_prefect_square_group[data2 % 10] = 1;

	check_prefect_square_group[data3 / 100] = 1;
	check_prefect_square_group[data3 / 10 % 10] = 1;
	check_prefect_square_group[data3 % 10] = 1;

	check_prefect_square_group[data4 / 1000] = 1;
	check_prefect_square_group[data4 / 100 % 10] = 1;
	check_prefect_square_group[data4 / 10 % 10] = 1;
	check_prefect_square_group[data4 % 10] = 1;
	for( int i = 0; i < 10; i++ )
	{
		if( check_prefect_square_group[i] == 0 )
		{
			return false;
		}
	}
	return true;
}

int main( int argc, char *argv[] )
{
	for( int i = pow( 0, 0.5 ); i < pow( 10, 0.5 ); i++ )
	{
		for( int j = pow( 10, 0.5 ); j < pow( 100, 0.5 ); j++ )
		{
			for( int m = pow( 100, 0.5 ); m < pow( 1000, 0.5 ); m++ )
			{
				for( int n = pow( 1000, 0.5 ); n < pow( 10000, 0.5 ); n++ )
				{
					if( IsPrefectSquareGroup( pow( i, 2 ), pow( j, 2 ), pow( m, 2 ), pow( n, 2 ) ) )
					{
						cout << pow( i, 2 ) << " " << pow( j, 2 ) << " " << pow( m, 2 ) << " " << pow( n, 2 ) << endl;
					}
				}
			}
		}
	}
	return 0;
}