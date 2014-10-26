#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;

template< typename TYPE >
void Swap( TYPE * a, TYPE * b )
{
	TYPE temp;
	temp = * a;
	* a = * b;
	* b = temp;
}

template< typename TYPE >
void OutPut( TYPE * Num, int NumMaxLength )
{
	for( int i = 0; i < NumMaxLength; i++ )
	{
		cout << Num[i] << "\t";
	}
	cout << endl;
}

//希尔排序 即把一个数组按照步长gap进行分组 一开始步长为n/2 然后随着排序进行步长缩短
//然后对每一组分别进行插入排序,最后当步长为1的时候 对整个数组进行一次插入排序
//希尔排序对于数组混乱时效率高于插入排序;插入排序在数组基本有序的时候效率最高;

template< typename TYPE >
void ShellSort1( TYPE * Num, int n )
{
	int i, j, gap;
	for( gap = n / 2; gap > 0; gap /= 2 )
	{
		for( i = gap; i < n; i++ )
		{
			for( j = i - gap; j >= 0 && Num[j] > Num[j + gap]; j -= gap )
			{
				Swap( & Num[j], & Num[j+gap] );
			}
		}
	}
}

int main()
{
	int Num[] = { 5, 8, 9, 5, 1, 5 };

	ShellSort1( Num, 6 );
	OutPut( Num, 6 );

	system( "pause" );
	return 0;
}