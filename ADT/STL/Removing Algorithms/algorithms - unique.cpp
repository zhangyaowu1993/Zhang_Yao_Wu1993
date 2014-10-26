//
//  algorithms - unique.cpp
//  unique
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool Check(int elem1, int elem2)
{
    if(elem1 == elem2 - 2)
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
    vector<int> arr1;
    for(int i = 0; i < 6; i++)
    {
        arr1.insert(arr1.begin(), i);
        arr1.insert(arr1.begin(), i);
    }
    copy(arr1.begin(), arr1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // remove two continued number which equal to each other, also don't change size of vector
    unique(arr1.begin(), arr1.end());
    copy(arr1.begin(), arr1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // remove two continued number which make op true, also don't change size of vector
    arr1.erase(unique(arr1.begin(), arr1.end(), Check), arr1.end());
    copy(arr1.begin(), arr1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    
    
    // copy src [) into dest [) and delete repeated elem
    unique_copy(arr1.begin(), arr1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // copy src [) into dest [) and delete elem which make op true
    arr1.push_back(7);
    unique_copy(arr1.begin(), arr1.end(), ostream_iterator<int>(cout, " "), not2(ptr_fun(Check)));
    
    return 0;
}

