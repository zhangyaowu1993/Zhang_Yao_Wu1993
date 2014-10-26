#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;

//分析: 插入排序就是从第一个元素开始 来和前面的元素比较 如果找到合适的位置 则插入 否则比较下一个元素

template < typename TYPE >
void Swap( TYPE * a, TYPE * b )
{
	TYPE temp;
	temp = *a;
	*a = *b;
	*b = temp;
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

template < typename TYPE >
void Insertsort1( TYPE Num[], int n )
{
	int i, j, k;
	for( i = 1; i < n; i++ )					//从第一个元素开始比 一直比到最后一个
	{
		for( j = 0; j < i; j++ )				//用Num[i]和他前面的每一个元素比较
		{
			if( Num[i] < Num[j] )				//如果Num[i]比他前面的某一个元素小 则当前j的位置为合适位置
			{
				break;							//然后Num会break掉 此时j < i;
			}
		}										//如果一直找到i - 1;没有找到合适的位置;则j++ 此时j == i;for循环结束

		if( j != i )							//如找到了一个合适的位置
		{
			int temp = Num[i];                  //保存下Num[i]位置数据
			for( k = i - 1; k >= j; k-- )       //从Num[j]到Num[i-1]所有数据往后移动一位
			{
				Num[k + 1] = Num[k];
			}
			Num[k + 1] = temp;                  //将Num[i]放到Num[j]位置上
		}
	}											//下一轮
}

template < typename TYPE >
void Insertsort2( TYPE Num[], int n )
{
	int i, j;
	for( i = 1; i < n; i++ )										//从第一个数字开始比
	{
		if( Num[i] < Num[i - 1] )								//如果这个数字比他前一个数字大 则他们是有序的 不用移动 否则进入
		{
			int temp = Num[i];									//保留Num[i]
			for( j = i - 1; j >= 0 && Num[j] > temp; j-- )	//从Num[i-1]开始往前逐个与temp比较 如果temp小 继续 如果大 则j + 1为合适位置
			{
				Num[j + 1] = Num[j];							//比较过程中,逐个后移
			}
			Num[j + 1] = temp;									//把temp放在合适位置
		}
	}
}


template < typename TYPE >
void Insertsort3( TYPE Num[], int n )
{
	for( int i = 1; i < n; i++ )									//从第一个数字开始比
	{
		for( int j = i - 1; j >= 0 && Num[j] > Num[j + 1]; j-- )		//每次往前比一个位置 然后如果Num[i]数字大 则交换他和他前一个数据
		{																//如果这个数字小 排序结束
			Swap( &Num[j], &Num[j + 1] );
		}
	}
}


int main()
{
	int Num[] = { 5, 8, 9, 5, 1, 5 };
	Insertsort1( Num, 6 );
	OutPut( Num, 6 );

	Insertsort2( Num, 6 );
	OutPut( Num, 6 );

	Insertsort3( Num, 6 );
	OutPut( Num, 6 );

	system( "pause" );
	return 0;
}