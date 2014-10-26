//
//  algorithms - bind2nd.cpp
//  bind2nd
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> arr;
    for(int i = 1; i < 13; i++)
    {
        arr.push_back(i);
    }
    //random_shuffle(arr.begin(), arr.end());
    
    // find first number greater than 3
    cout << *find_if(arr.begin(), arr.end(), bind2nd(greater<int>(), 3));
    
    // find first number div by 5 not equl 0
    cout << *find_if(arr.begin(), arr.end(), bind2nd(modulus<int>(), 5));
    
    // find first number full div by 3
    cout << *find_if(arr.begin(), arr.end(), not1(bind2nd(modulus<int>(), 3)));
    
    return 0;
}