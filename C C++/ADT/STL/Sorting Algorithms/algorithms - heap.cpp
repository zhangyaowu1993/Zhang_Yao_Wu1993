//
//  algorithms - heap.cpp
//  heap
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool IsGreater(int elem1, int elem2)
{
    if(elem1 > elem2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, const char *argv[])
{
    vector<int> table1;
    for(int i = 0; i < 4; i++)
    {
        table1.push_back(i);
        table1.push_back(i * i);
        table1.push_back(i * i * i);
    }
    random_shuffle(table1.begin(), table1.end());
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    make_heap(table1.begin(), table1.end());
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    pop_heap(table1.begin(), table1.end());
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    table1.pop_back();
    cout << endl;
    
    table1.push_back(15);
    push_heap(table1.begin(), table1.end());
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    sort_heap(table1.begin(), table1.end());
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}

