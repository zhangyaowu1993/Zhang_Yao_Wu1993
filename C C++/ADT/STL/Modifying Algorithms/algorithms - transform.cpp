//
//  algorithms - transform.cpp
//  transform
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

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
    
    // transform src [) every elem call op and put result into dest [)  (alert it)
    transform(que1.begin(), --que1.end(), que2.begin(), negate<int>());
    
    copy(que1.begin(), que1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(que2.begin(), que2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // transform src [) and dest [) every pair elem call op , then put result into iterator
    transform(que1.begin(), que1.end(), que2.begin(), ostream_iterator<int>(cout, " "), minus<int>());
    
    return 0;
}

