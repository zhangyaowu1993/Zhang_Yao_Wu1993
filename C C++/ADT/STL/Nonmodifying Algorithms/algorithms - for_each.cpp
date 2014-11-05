//
//  algorithms - for_each.cpp
//  for_each
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename TYPE>
class MeanValue
{
public:
    void operator()(TYPE &elem)
    {
        elem += 5;
        cout << elem << " ";
        value += elem;
    }
    int value;
};

int main(int argc, const char *argv[])
{
    vector<double> arr;
    for(int i = 0; i < 13; i++)
    {
        arr.push_back(1.2 * i);
    }
    random_shuffle(arr.begin(), arr.end());
    
    auto temp = for_each(arr.begin(), arr.end(), MeanValue<double>());
    cout << endl << temp.value;
    
    return 0;
}