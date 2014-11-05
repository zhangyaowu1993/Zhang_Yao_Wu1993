//
//  algorithms - copy.cpp
//  copy
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
    
    // copy source [) into destbegin [) , return first elem iterator  after dest [)
    copy(que1.begin(), ++++que1.begin(), que2.begin());
    
    copy(que1.begin(), que1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(que2.begin(), que2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // copy source [) into destend (] , return first elem iterator before (]
    copy_backward(que1.begin(), ++++que1.begin(), que2.end());
    
    copy(que1.begin(), que1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(que2.begin(), que2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    return 0;
}

