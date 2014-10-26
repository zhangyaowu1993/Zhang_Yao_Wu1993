// 计数排序 只能排序整数 而且排序和序列最大值和最小值之差有关系

#include <iostream>
#define ResultLength 200

void CountSort( int *sort, int size, int max_number, int min_number )
{
	int result[ResultLength] = { 0 };
	for( int i = 0; i < size; i++ )
	{
		result[sort[i] - min_number]++;
	}

	for( int i = 0; i < ResultLength; i++ )
	{
		for( ; result[i] != 0; result[i]-- )
		{
			std::cout << i + min_number << " ";
		}
	}
}

int FindMaxNumber( int *sort, int size )
{
	int max_number = sort[0];

	for( int i = 0; i < size; i++ )
	{
		if( sort[i] > max_number )
		{
			max_number = sort[i];
		}
	}
	return max_number;
}

int FindMinNumber( int *sort, int size )
{
	int min_number = sort[0];

	for( int i = 0; i < size; i++ )
	{
		if( sort[i] < min_number )
		{
			min_number = sort[i];
		}
	}
	return min_number;
}

int main()
{
	int p[] = { 0, 1, 2, 8, 5, 6, 10, 8, 100 };
	int size = sizeof( p ) / sizeof( p[0] );
	int max = FindMaxNumber( p, size );
	int min = FindMinNumber( p, size );
	CountSort( p, size, max, min );

	return 0;
}