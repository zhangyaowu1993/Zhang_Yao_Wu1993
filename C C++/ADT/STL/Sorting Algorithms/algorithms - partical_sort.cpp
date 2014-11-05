//
//  algotithms - partical_sort.cpp
//  partical_sort
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
    vector<int> table4;
    for(int i = 0; i < 7; i++)
    {
        table1.push_back(i);
        table2.push_back(2 * i);
        table3.push_back(3 * i);
        table4.push_back(4 * i);
    }
    random_shuffle(table1.begin(), table1.end());
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(table2.begin(), table2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(table3.begin(), table3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(table4.begin(), table4.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // sort [begin(), end()), but only make sure [begin(), middle()) is sorted
    partial_sort(table1.begin(), ++table1.begin(), table1.end());
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // sort [begin(), end()), but only make sure [begin(), middle()) is sorted
    partial_sort(table2.begin(), ++table2.begin(), ----table2.end(), IsGreater);
    copy(table2.begin(), table2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // sort and copy
    partial_sort_copy(table3.begin(), table3.end(), table3.begin(), table3.end());
    copy(table3.begin(), table3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // sort and copy use op
    partial_sort_copy(table4.begin(), table4.end(), table4.begin(), table4.end(), IsGreater);
    copy(table4.begin(), table4.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}

