//
//  algorithms - includes.cpp
//  includes
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
    vector<int> table2;
    for(int i = 0; i < 6; i++)
    {
        table1.push_back(i);
    }
    for(int i = 0; i < 3; i++)
    {
        table2.push_back(i);
    }
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(table2.begin(), table2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    
    // is every elem in table2 is find in table1
    if(includes(table1.begin(), table1.end(), table2.begin(), table2.end()))
    {
        cout << "table1 is include table2" << endl;
    }
    else
    {
        cout << "table1 is not include table2" << endl;
    }
    
    
    return 0;
}

