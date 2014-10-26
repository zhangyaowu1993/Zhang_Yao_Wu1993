//
//  algorithms - merging.cpp
//  merging
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> table1;
    vector<int> table2;
    vector<int> table3;
    vector<int> table4;
    vector<int> table5;
    vector<int> table6;
    back_insert_iterator<vector<int>> it1(table3);
    back_insert_iterator<vector<int>> it2(table4);
    back_insert_iterator<vector<int>> it3(table5);
    back_insert_iterator<vector<int>> it4(table6);
    for(int i = 0; i < 6; i++)
    {
        table1.push_back(i);
        table2.push_back(i * i);
    }
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(table2.begin(), table2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // sim sum of two string
    merge(table1.begin(), table1.end(), table2.begin(), table2.end(), it1);
    copy(table3.begin(), table3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // sim union of two string
    set_union(table1.begin(), table1.end(), table2.begin(), table2.end(), it2);
    copy(table4.begin(), table4.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // sim intersection of two string
    set_intersection(table1.begin(), table1.end(), table2.begin(), table2.end(), it3);
    copy(table5.begin(), table5.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // sim difference of two string
    set_difference(table1.begin(), table1.end(), table2.begin(), table2.end(), it4);
    copy(table6.begin(), table6.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}

