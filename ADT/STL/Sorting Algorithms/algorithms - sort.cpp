//
//  algorithms - sort.cpp
//  sort
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
    vector<int> table2;
    vector<int> table3;
    for(int i = 0; i < 7; i++)
    {
        table1.push_back(i);
        table2.push_back(2 * i);
        table3.push_back(i % 2);
    }
    random_shuffle(table1.begin(), table1.end());
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(table2.begin(), table2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(table3.begin(), table3.end(), ostream_iterator<int>(cout, " "));
    
    // sort by less()
    sort(table1.begin(), table1.end());
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    
    // sort by op()
    sort(table2.begin(), table2.end(), IsGreater);
    copy(table2.begin(), table2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // sort by less(), and make the elem equal stay order
    stable_sort(table3.begin(), table3.end());
    copy(table3.begin(), table3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}

