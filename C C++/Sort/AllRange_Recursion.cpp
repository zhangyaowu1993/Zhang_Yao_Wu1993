#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;

template < typename TYPE >
void Swap( TYPE * a, TYPE * b )
{
	TYPE temp = * a;
	* a = * b;
	* b = temp;
}

template < typename TYPE >
void OutPut( int s_i, TYPE Num, int n )
{
	if( s_i == 0 )
	{
		cout << "原数列 : ";
	}
	else
	{
		cout << "第 " << s_i << " 个全排列 : ";
	}
	for( int i = 0; i < n; i++ )
	{
		cout << Num[i];
	}
	cout << endl;
}


//在Num数组中，[nBegin,nEnd)中是否有数字与下标为nEnd的数字相等
template < typename TYPE >
bool IsSwap( TYPE * Num, int nBegin, int nEnd )
{
	for( int i = nBegin; i < nEnd; i++ )
	{
		if( Num[i] ==  Num[nEnd] )
		{
			return false;
		}
	}
	return true;
}

template < typename TYPE >
void AllRange( TYPE * Num, int k, int m )
{
	if( k == m )
	{
		static int s_i = 1;
		OutPut( s_i++,Num, m );
	}
	else
	{
		for(int i = k; i < m; i++) 
		{
			if( IsSwap( Num, k, i ) )
			{
				Swap( Num + k, Num + i );
				AllRange( Num, k + 1, m );
				Swap( Num + k, Num + i );
			}
		}
	}
}

template < typename TYPE >
void Foo( TYPE * Num, int n )
{
	AllRange( Num, 0, n );
}

int main()
{
	int Num[] = { 1, 2, 3 };
	OutPut( 0, Num, 3 );
	Foo( Num, 3 );
	system( "pause" );
	return 0;
}