//
//  algorithms - equal.cpp
//  equal
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

bool func5(int elem1, int elem2)
{
    if(elem1 % 2 == elem2 % 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, const char *argv[])
{
    deque<int> deque1;
    deque<int> deque2;
    for(int i = 0; i < 5; i++)
    {
        deque1.push_back(i);
        deque2.push_back(i + 2);
    }
    
    // return true if every value in deque1 equal it match value in deque2
    if(equal(deque1.begin(), deque1.end(), deque2.begin()) == true)
    {
        cout << "deque1 == deque2" << endl;
    }
    
    // return true if everu value in deque1 and it match value in deque2 make op true
    if(equal(deque1.begin(), deque1.end(), deque2.begin(), func5))
    {
        cout << "deque1 and deque2 make func4 true" << endl;
    }



    return 0;
}

