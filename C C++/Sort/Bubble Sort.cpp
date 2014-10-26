#include <Windows.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int MAXNUMBER = 10;

template < typename TYPE >
void swap( TYPE * a, TYPE * b )
{
	TYPE temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

template < typename TYPE >
void sort( TYPE * number )
{
	for( int i = 0; i < MAXNUMBER; i++ )
	{
		for( int j = i + 1; j < MAXNUMBER; j++ )
		{
			if( number[i] < number [j] )
			{
				swap( & number[i], & number[j] );
			}
		}
	}
}

int main()
{
	int number[MAXNUMBER] = { 0 };
	int i = 0;
	while( i < MAXNUMBER )
	{
		cin >> number[i];
		i++;
	}

	sort( number );

	for( int i = 0; i < MAXNUMBER; i++ )
	{
		cout << number[i] << "\t";
	}

	system( "pause" );
	return 0;
 } 

