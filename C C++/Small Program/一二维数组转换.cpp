#include <iostream>
#include <limits.h>
const int MAX = 3;

int main()
{
	int arr1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	int arr2[MAX][MAX] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

	/***************************///一维转二维

	typedef int( *pointer )[MAX];
	pointer arr_1 = ( pointer ) arr1;
	for( int i = 0; i < MAX; i++ )
	{
		for( int j = 0; j < MAX; j++ )
		{
			std::cout << *( *( arr_1 + i ) + j ) << " ";
		}
	}
	std::cout << std::endl;
	/***************************///二维转一维
	/*********************///转一行

	for( auto temp : arr2[0] )
	{
		std::cout << temp << " ";
	}
	std::cout << std::endl;
	/*********************///转全部

	int arr_2[MAX*MAX];
	for( int i = 0; i < MAX; i++ )
	{
		for( int j = 0; j < MAX; j++ )
		{
			arr_2[i*3+j] = arr2[i][j];
		}
	}
	for( auto temp : arr_2 )
	{
		std::cout << temp << " ";
	}
	std::cout << std::endl;

	return 0;
}