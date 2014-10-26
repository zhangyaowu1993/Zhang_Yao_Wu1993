//
//  algorithms - replace.cpp
//  replace
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

bool func1(int elem)
{
    if(elem % 2 == 1)
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
    deque<int> que1;
    deque<int> que2;
    for(int i = 0; i < 6; i++)
    {
        que1.push_back(i);
        que2.push_back(i + 2);
    }
    
    copy(que1.begin(), que1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(que2.begin(), que2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // replace src [) every elem which equal 4 into 9
    replace(que1.begin(), que1.end(), 4, 9);
    
    // replace src [) every elem which make op true into 10
    replace_if(que2.begin(), que2.end(), func1, 10);
    
    copy(que1.begin(), que1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(que2.begin(), que2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    
    // copy src [) every elem into dest section , and replace every elem which equal 5 into 11
    replace_copy(que1.begin(), que1.end(), ostream_iterator<int>(cout, " "), 5, 11);
    cout << endl;
    
    // copy src [) every elem into dest section , and replace every elem which make op true
    replace_copy_if(que2.begin(), que2.end(), ostream_iterator<int>(cout, " "), func1, 19);
    cout << endl;
    
    return 0;
}

