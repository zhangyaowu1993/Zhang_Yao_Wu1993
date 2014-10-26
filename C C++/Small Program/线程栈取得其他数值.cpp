// 关于获取栈中任意数据;

// #include <iostream>

// int main( int argc, char *argv[] )
// {
	// int iVar_1 = 200;
	// int iVar_2 = 100;
	// int iVar_3 = 50;

	// int *pDest_1 = &iVar_2;

	// std::cout << "iVar_1 = " << *( pDest_1 + 3 ) << std::endl;
	// std::cout << "iVar_2 = " << *pDest_1 << std::endl;
	// std::cout << "iVar_3 = " << *( pDest_1 - 3 ) << std::endl;

	// return 0;
// }

// 首先解释一下 在线程栈中 栈是从大到小分配的
// 相当于 一个竖着的栈 他从上面开始装东西 然后栈底在上头不动 栈顶往下走;
// 地址上大下小, 倒着分配;
// 首先取得了iVar_2的地址 然后根据栈分配规则取得了iVar_1和iVar_3的地址;

// 这个程序必须在"Debug"版本下测试;
// 在Debug版本下 线程栈未被优化 但是本来一个int类型占用4字节数据,被掺入了8字节的调试信息
// 所以在线程栈中要取得下一个或者上一个数据 需要 + 3; 一共是12字节;

// 如果是加法 则往上找 如果是减法 往下找;
// 对于Release版; 去除了调试信息 所以每个int占用4字节并且连续 
// 但是某些数据被移位;导致无法使用得到正确数值