//
//  algorithms - next_prev_permutation.cpp
//  next_prev_permutation
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> table;
    for(int i = 0; i < 3; i++)
    {
        table.push_back(i);
    }
    //random_shuffle(table.begin(), table.end());
    copy(table.begin(), table.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // next_permutation return false if elem sort descending 降序 123 -> 123
    while(next_permutation(table.begin(), table.end()))
    {
        copy(table.begin(), table.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    
    cout << endl;
    
    // reverse table
    reverse(table.begin(), table.end());
    
    // next_permutation return false if elem sort ascending 升序 321 -> 321
    while(prev_permutation(table.begin(), table.end()))
    {
        copy(table.begin(), table.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}

