//
//  main.cpp
//  vector
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> table;
    table.push_back(1);
    table.insert(table.end(), 2);
    
    istream_iterator<int> i_iter_eof;
    istream_iterator<int> i_iter(cin);
    while(i_iter != i_iter_eof)
    {
        table.push_back(*i_iter);
        i_iter++;
    }
    
    copy(table.begin(), table.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    if(find(table.begin(), table.end(), 5) != table.end())
    {
        cout << "find 5" << endl;
    }
    else
    {
        cout << "not find 5" << endl;
    }
    
    table.erase(table.begin());
    table.shrink_to_fit();
    
    copy(table.begin(), table.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}