//
//  algorithms - equal_range.cpp
//  equal_range
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
    vector<int> table1;
    vector<int>::iterator it;
    for(int i = 0; i < 6; i++)
    {
        table1.push_back(i);
        table1.push_back(i);
    }
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // return first elem iterator value can be insert that do not break sort
    it = lower_bound(table1.begin(), table1.end(), 2);
    if(it != table1.end())
    {
        cout << distance(table1.begin(), it) << endl;
    }
    
    // return last elem iterator value can be insert that do not break sort
    it = upper_bound(table1.begin(), table1.end(), 2);
    if(it != table1.end())
    {
        cout << distance(table1.begin(), it) << endl;
    }
    
    // return a pair that elem iterator value can be inser tahta do not break sort
    pair<vector<int>::iterator, vector<int>::iterator> pa;
    pa = equal_range(table1.begin(), table1.end(), 4);
    cout << distance(table1.begin(), pa.first) << " " << distance(table1.begin(), pa.second) << endl;
    
    return 0;
}

