//
//  algorithms - random_shuffle.cpp
//  random_shuffle
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Random
{
public:
    int operator()(double max)
    {
        double temp = static_cast<double>(rand()) / RAND_MAX;
        return temp * max;
    }
};

int main(int argc, const char *argv[])
{
    vector<int> table;
    for(int i = 0; i < 7; i++)
    {
        table.push_back(i);
    }
    copy(table.begin(), table.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // fill with random number
    random_shuffle(table.begin(), table.end());
    copy(table.begin(), table.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // better for multithread
    Random rd;
    random_shuffle(table.begin(), table.end(), rd);
    copy(table.begin(), table.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

