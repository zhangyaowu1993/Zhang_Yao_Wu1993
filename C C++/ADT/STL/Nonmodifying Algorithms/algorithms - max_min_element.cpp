//
//  algorithms - max_min_element.cpp
//  max_element min_element
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename TYPE>
class Compare
{
public:
    bool operator()(TYPE elem1, TYPE elem2)
    {
        // orignal compare function is less<TYPE>
        // now reverse the compare function
        if(elem1 > elem2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(int argc, const char *argv[])
{
    vector<int> arr;
    for(int i = 0; i < 13; i++)
    {
        arr.push_back(i);
    }
    random_shuffle(arr.begin(), arr.end());
    
    // return the maximum number belong [begin(), end())
    cout << *max_element(arr.begin(), arr.end()) << endl;
    cout << *max_element(arr.begin(), arr.end(), Compare<int>()) << endl;
    
    // return the minimum number belong [begin(), end())
    cout << *min_element(arr.begin(), arr.end()) << endl;
    cout << *min_element(arr.begin(), arr.end(), Compare<int>()) << endl;
    
    return 0;
}