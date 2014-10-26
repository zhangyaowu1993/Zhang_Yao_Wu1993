//
//  algorithms - numberic.cpp
//  numberic
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>

using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> table1;
    for(int i = 1; i < 6; i++)
    {
        table1.push_back(i);
    }
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // sim sum of value and [) elem
    cout << accumulate(table1.begin(), table1.end(), 0) << endl;
    
    // sim value op elem1 op elem2 ...
    cout << accumulate(table1.begin(), table1.end(), 3, multiplies<int>()) << endl;
    
    
    vector<int> table2;
    vector<int> table3;
    for(int i = 1; i < 4; i++)
    {
        table2.push_back(i);
        table3.push_back(i + 1);
    }
    
    // sim value + tb2.elem1 * tb3.elem1 + tb2.elem2 * tb3.elem2 ...
    cout << inner_product(table2.begin(), table2.end(), table3.begin(), 0) << endl;
    
    // sim value * (tb2.elem1 + tb3.elem1) * (tb2.elem2 + tb3.elem2) * ...
    cout << inner_product(table2.begin(), table2.end(), table3.begin(), 1, multiplies<int>(), plus<int>()) << endl;
    
    
    vector<int> table4;
    for(int i = 1; i < 5; i++)
    {
        table4.push_back(i);
    }
    
    // sim 1 1+2 1+2+3 1+2+3+4
    partial_sum(table4.begin(), table4.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // sim 1 1*2 1*2*3 1*2*3*4
    partial_sum(table4.begin(), table4.end(), ostream_iterator<int>(cout, " "), multiplies<int>());
    cout << endl;
    
    
    vector<int> table5;
    for(int i = 0; i < 6; i++)
    {
        table5.push_back(i);
    }
    
    // sim 0 1-0 2-1 3-2 4-3 ...
    adjacent_difference(table5.begin(), table5.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // sim 0 1*0 2*1 3*2 4*3 ...
    adjacent_difference(table5.begin(), table5.end(), ostream_iterator<int>(cout, " "), multiplies<int>());
    cout << endl;
    
    return 0;
}

