#include <iostream>
#include <bitset>
#include <Windows.h>

using namespace std;

int main()
{
	int a = 100;
	cout << "十进制    " << dec << a << endl;
	cout << "十六进制  " << hex << a << endl;
	cout << "八进制    " << oct << a << endl;
	cout << "二进制    " << bitset< 8 >( a ) << endl;  // bitset< bit > ( a ); bit表示要输出的二进制位数,a就是要输出的数

	cout << "--------------------------------" << endl;

	printf( "十进制    %d\n", a );
	printf( "十六进制  %x\n", a );
	printf( "八进制    %o\n", a );

	char binary_text[100];  
	_itoa_s( a, binary_text, 2 );
	printf( "二进制    %s\n", binary_text );

	system( "pause" );
	return 0;
}