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

//快速排序: 假设取第一个数作为分界, 进行一趟快速排序后,小于分界的数字位于分解左边 大于分界的数字位于分界右边
//			然后对分界左边的和右边的数组在进行快速排序 直到数组被分割为只剩下一个数字

template< typename TYPE >
void QuickSort1( TYPE * Num, int left, int right )		//left和right为数组的上界和下界( left即为0,right为数组的长度 )
{														//此时 Num[right]为\0;
	int i, j;	
	if( left < right )									//若数组的下界小于上界 代表数组至少还有两个元素 继续排序
	{
		i = left;										//使i成为指向下界位置的指针 现在指向了Num[0] - 分界元素
		j = right;										//使j成为指向上界位置的指针 现在指向了Num[n] - 数组\0
		do												//当 i < j 时继续循环, i >= j时 数组已经满足要求
		{
			do i++;
			while( Num[i] < Num[left] );                //从左往右 找到第一个小于分界的数字;
			do j--;
			while( Num[j] > Num[left] );                //从右往左 找到第一个大于分界的数字
			if( i < j )									//如果此时 i < j 则交换两个数字
			{
				Swap( & Num[i], & Num[j] );
			}
		}
		while( i < j );									//当i < j时 结束循环 此时 j + 1 = i; 
                                                        //( i != j; 因为这个数字不可能又比分界大 又比分界小 )
                                                        // 此时j的位置为最小组的最后一位,i的位置为最大组的第一位
		Swap( & Num[left], & Num[j] );                  // 交换分界和最小组的最后一位
                                                        //分为最小组和最大组 left -> Num[j-1] -> Num[j] -> Num[j+1] -> right
		QuickSort1( Num, left, j - 1 );                 //Num[j]现在即为分界元素
		QuickSort1( Num, j + 1, right );                //分别对最大组和最小组进行快速排序
	}
}


int main()
{
	int Num[] = { 5, 8, 9, 5, 1, 5 };

	QuickSort1( Num, 0, 6 );
	OutPut( Num, 6 );

	system( "pause" );
	return 0;
}