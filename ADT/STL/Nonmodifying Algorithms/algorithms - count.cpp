//
//  algorithms - count.cpp
//  count
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename TYPE>
class EvenNumber
{
public:
    bool operator()(TYPE elem)
    {
        return static_cast<int>(elem) % 2 == 0;
    }
};

int main(int argc, const char *argv[])
{
    vector<double> arr;
    for(int i = 0; i < 13; i++)
    {
        arr.push_back(1.2 * i);
    }
    random_shuffle(arr.begin(), arr.end());
    
    // return number of items match filiter
    cout << count(arr.begin(), arr.end(), 2.4) << endl;
    cout << count_if(arr.begin(), arr.end(), EvenNumber<double>());
    
    return 0;
}