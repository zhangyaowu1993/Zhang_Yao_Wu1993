#include <iostream>

int Add(int num1, int num2)
{
    // a + b = (a ^ b) + ((a & b) << 1);
    if(num2 == 0)
    {
        return num1;
    }
    return Add(num1 ^ num2, (num1 & num2) << 1);
}

int main()
{
    int num1 = 100;
    int num2 = 50;
    std::cout << Add(num1, num2) << std::endl;
    return 0;
}