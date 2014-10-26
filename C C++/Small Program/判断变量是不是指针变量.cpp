// 测试一个变量是不是指针变量
// C++对于函数调用的优先级是 普通函数 -> 模版函数 -> 可变参数函数

#include <iostream>

using namespace std;

template< typename TYPE >
void IsPointer( TYPE )
{
	cout << "Not AAAA Pointer" << endl;
}

template< typename TYPE >
void IsPointer( TYPE * v )
{
	cout << "A Pointer" << endl;
}

void IsPointer( ... )
{
	cout << "Not A Pointer" << endl;
}

int main( int argc, char *argv[] )
{
	int p = 1;
	int *k = nullptr;
	IsPointer( p );
	IsPointer( k );
	return 0;
}