#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;

template< typename TYPE >
void Swap( TYPE * a, TYPE * b )
{
	TYPE temp = * a;
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

//分析: 全排列即把每一个数字移到最前 然后分别和他后面的数字交换;
// i == 0;代表Num[0]和Num[0]交换 为第一次进入
// j == 1;代表如果第一个数字和第二个数字相等;则输出一次 否则break;

template< typename TYPE >
void AllRange( TYPE * Num, int NumMaxLength )
{
	for( int i = 0; i < NumMaxLength; i++ )                             //按顺序把数字移动到最前
	{																	//比如123;移动第一次后是123 第二次是213 第三次是321
		if( Num[0] != Num[i] || i == 0 )                                //防止重数 比如当前为212 该交换第三个数字 则失败,当111的时候则可以进入
		{
			Swap( & Num[0], & Num[i] );                                 //按顺序把数字移动到最前;
			for( int j = 1; j < NumMaxLength; j++ )                     //分别与后面的每个数交换
			{
				if( Num[0] != Num[j] || j == 1 )                        //防止重复  如果交换的数字和自己相等则为重复;
				{
					Swap( & Num[0], & Num[j] );                         //交换
					OutPut( Num, NumMaxLength );
					Swap( & Num[j] , & Num[0] );                        //换回来
				}
			}
		}
	}
}

int main()
{
	int Num[4] = { 1, 6, 5, 3 };
	cout << "全排列如下:\n";
	AllRange( Num, 4 );
	system( "pause" );
	return 0;
}