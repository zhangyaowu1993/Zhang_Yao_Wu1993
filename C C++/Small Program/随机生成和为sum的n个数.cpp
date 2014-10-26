#include <stdio.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <Windows.h>

void Swap( int * a, int * b )
{
	int temp;
	temp = * a;
	* a = * b;
	* b = temp;
}

//随机生成和为sum的n个数 ( Sum > n ) //
//投影法 简述如下:如果要生成和为sum的n个数 则可以随机生成3个数 然后最后一个数为sum
//然后结果即为排序后的数列 后一个数减去前一个数

int * GetRandomNum( int sum, int n )
{
	int * Num = new int[n];
	srand( ( unsigned ) time( NULL ) );

	for( int i = 0; i < n; i++ )												//产生随机数
	{
		Num[i] = ( int ) ( ( double )rand() / RAND_MAX * sum );
		if( i == n - 1 )
		{
			Num[i] = sum;
		}
	}

/**********************************************************************///InsertSort 插入排序
	for( int i = 1; i < n; i++ )												//从第一个数字开始比
	{
		for( int j = i - 1; j >= 0 && Num[j] > Num[j + 1]; j-- )		//每次往前比一个位置 然后如果Str[i]数字大 则交换他和他前一个数据
		{																			//如果这个数字小 排序结束
			Swap( & Num[j], & Num[j + 1] );			
		}
	}
/**********************************************************************///InsertSort 插入排序

	for( int i = n - 1; i > 0; i-- )
	{
		Num[i] = Num[i] - Num[i-1];
	}

	return Num;
}

int main()
{
	int sum, n;
	printf( "请输入随机生成数字的和: " );
	scanf_s( "%d", & sum );
	printf( "请输入随机生成数字的个数: " );
	scanf_s( "%d", & n );
	for( int i = 0; i < n; i++ )
	{
		printf( "%d\t", GetRandomNum( sum, n )[i] );
	}

	system( "pause" );
	return 0;
}
