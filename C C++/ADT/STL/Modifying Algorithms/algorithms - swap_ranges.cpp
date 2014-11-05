//
//  algorithms - swap_ranges.cpp
//  swap_ranges
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
    
    // swap src [) every elem with dest [) every elem
    swap_ranges(que1.begin(), ++++que1.begin(), que2.begin());
    
    copy(que1.begin(), que1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(que2.begin(), que2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}

