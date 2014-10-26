#include <stdio.h>
#include <Windows.h>

int main(void)
{
#ifdef __cplusplus
    printf("当前编译器是C++编译\n");
#else
    printf("当前编译器是C编译\n");
#endif

    printf("hello world\n");

    system( "pause" );
    return 0;
}