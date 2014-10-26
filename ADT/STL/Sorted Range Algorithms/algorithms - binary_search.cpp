//
//  algorightms - binary_search.cpp
//  binary_search
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
    for(int i = 0; i < 4; i++)
    {
        table1.push_back(i);
    }
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    if(binary_search(table1.begin(), table1.end(), 3) == true)
    {
        cout << "3 Is In table1" << endl;
    }
    else
    {
        cout << "3 Is not in table1" << endl;
    }
    
    return 0;
}

