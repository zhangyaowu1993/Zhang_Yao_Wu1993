//
//  algorithms - remove.cpp
//  remove
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool IsEven(int elem)
{
    if(elem % 2 == 0)
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
    }
    copy(arr1.begin(), arr1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // remove the elem equl 3, but the size of vector does not change
    // remove let the unmoved elem left shift, and return a logital end
    remove(arr1.begin(), arr1.end(), 3);
    copy(arr1.begin(), arr1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // remove the elem which make op true, but the size of vector does not change
    // remove let the unmoved elem left shift, and return a logital end
    remove_if(arr1.begin(), arr1.end(), IsEven);
    copy(arr1.begin(), arr1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    
    
    // remove src [) to dest [) and delete elem value equl 1
    remove_copy(arr1.begin(), arr1.end(), ostream_iterator<int>(cout, " "), 1);
    cout << endl;
    
    // remove src [) to dest [) and delete elem make op true
    remove_copy_if(arr1.begin(), arr1.end(), ostream_iterator<int>(cout, " "), not1(ptr_fun(IsEven)));
    cout << endl;
    
    return 0;
}

