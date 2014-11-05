//
//  algorithms - find.cpp
//  find
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename TYPE>
bool EvenNum(TYPE num)
{
    if(num % 2 == 0)
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
    vector<int> arr;
    for(int i = 0; i < 13; i++)
    {
        arr.push_back(i);
    }
    random_shuffle(arr.begin(), arr.end());
    
    // return a iterator that item equl const value
    cout << *find(arr.begin(), arr.end(), 5) << endl;
    
    // print even number
    vector<int>::iterator it = arr.begin();
    while(it != arr.end())
    {
        it = find_if(it, arr.end(), EvenNum<int>);
        cout << *it << " ";
        it++;
    }

    return 0;
}