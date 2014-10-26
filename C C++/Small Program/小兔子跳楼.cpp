// 一只小兔子 一次可以跳 1 2 3 层楼 一共有十层的楼 有多少种跳法

#include <iostream>

int RabbitJump( int num )
{
	if( num == 1 )
	{
		return 1;
	}
	else if( num == 2 )
	{
		return 2;
	}
	else if( num == 3 )
	{
		return 4;
	}
	else
	{
		return RabbitJump( num - 1 ) + RabbitJump( num - 2 ) + RabbitJump( num - 3 );
	}
}

int main( int argc, char *argv[] )
{
	std::cout << RabbitJump( 10 );
	return 0;
}