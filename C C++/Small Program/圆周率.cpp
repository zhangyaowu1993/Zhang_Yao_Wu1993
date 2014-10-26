#include <iostream>
#include <cstdlib>
#include <ctime>

double SimPi( int num )
{
	int sign = 1;
	double pi = 0;
	for( int i = 0; i < num; i++ )
	{
		pi += static_cast< double > ( sign ) / static_cast< double > ( 2 * i + 1 );
		sign = -sign;
	}
	return 4 * pi;
}

int main( int argc, char *argv[] )
{
	const int MAX_NUM = 100000000;
	int count = 0;
	srand( time( 0 ) );
	for( int i = 0; i < MAX_NUM; i++ )
	{
		double x = static_cast< double > ( rand() ) / static_cast< double > ( RAND_MAX );
		double y = static_cast< double > ( rand() ) / static_cast< double > ( RAND_MAX );
		if( x * x + y * y <= 1 )
		{
			count++;
		}
	}
	std::cout << 4 * static_cast< double > ( count ) / static_cast< double > ( MAX_NUM ) << std::endl;
	std::cout << SimPi( 10000000 ) << std::endl;
	return 0;
}
