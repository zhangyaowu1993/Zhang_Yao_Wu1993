#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;

template< typename TYPE >
void OutPut( TYPE * Num, int NumMaxLength )
{
	for( int i = 0; i < NumMaxLength; i++ )
	{
		cout << Num[i] << "\t";
	}
	cout << endl;
}

template < typename TYPE >
void MergeArray( TYPE * Num, int first, int mid, int last, TYPE * Temp )	//把前后两路有序数组合并成有序数组
{
	int i = first;															//i指向前一段
	int j = mid + 1;														//j指向后一段
	int k = 0;																//k为Temp的指针
	int m = mid;															
	int n = last;
	while( i <= m && j <= n )                                               //其中任意一个到头了 则结束
	{
		if( Num[i] < Num[j] )												//Num[i] Num[j] 小的先进Temp[];
		{
			Temp[k++] = Num[i++];
		}
		else																
		{
			Temp[k++] = Num[j++];
		}
	}

	while( i <= m )															//后一段到头了 前一段没到
	{
		Temp[k++] = Num[i++];                                               //把前一段多出来的进Temp
	}

	while( j <= n )															//前一段到头了 后一段没到
	{
		Temp[k++] = Num[j++];                                               //把后一段多出来的进Temp
	}

	for( int i = 0; i < k; i++ )											//把中间变量的数组放会Num
	{																		//Temp[]里是合并排序好的数组
		Num[first+i] = Temp[i];                                             //***把排序好的放在进来的位置***//
	}
}

template < typename TYPE >
void MergeSort( TYPE * Num, int first, int last, TYPE * Temp )  
{  
    if ( first < last )														//如果每个组的元素只剩1个 则无法进入
    {  
        int mid = ( first + last ) / 2;                                     //表示数组分割的中间点
		MergeSort( Num, first, mid, Temp );                                 //左边 first -> mid 有序
        MergeSort( Num, mid + 1, last, Temp );                              //右边 mid + 1 -> last有序
        MergeArray( Num, first, mid, last, Temp );                          //再将二个有序数列合并
    } 
}  

template < typename TYPE >
bool _MergeSort( TYPE * Num, int n )  
{  
    TYPE * p = new TYPE[n];  
    if ( p == NULL )  
	{
        return false;  
	}
    MergeSort( Num, 0, n - 1, p );  
    delete [] p;  
    return true;  
}  


int main()
{
	int Num[] = { 5, 8, 9, 5, 1, 5 };
	
	_MergeSort( Num, 6 );
	OutPut( Num, 6 );

	system( "pause" );
	return 0;
}
