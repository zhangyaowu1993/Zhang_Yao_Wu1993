//
//  algorithms - reverse.cpp
//  reverse
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
    for(int i = 0; i < 6; i++)
    {
        table.push_back(i);
    }
    random_shuffle(table.begin(), table.end());
    copy(table.begin(), table.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // reverse elem
    reverse(table.begin(), table.end());
    copy(table.begin(), table.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // copy elem into dest [) and reverse elem
    reverse_copy(table.begin(), table.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}

