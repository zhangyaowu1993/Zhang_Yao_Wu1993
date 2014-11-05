//
//  algorithms - nth_element.cpp
//  nth_element
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
    for(int i = 0; i < 7; i++)
    {
        table1.push_back(i);
        table2.push_back(2 * i);

    }
    random_shuffle(table1.begin(), table1.end());
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    random_shuffle(table2.begin(), table2.end());
    copy(table2.begin(), table2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // divide by middle elem, left string all less than it, right string all greater than it
    nth_element(table1.begin(), ++++table1.begin(), table1.end());
    copy(table1.begin(), table1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // divede by middle elem, left string all greater than it, right string all less than it, it use op
    nth_element(table2.begin(), ++++table2.begin(), table2.end(), IsGreater);
    copy(table2.begin(), table2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}

