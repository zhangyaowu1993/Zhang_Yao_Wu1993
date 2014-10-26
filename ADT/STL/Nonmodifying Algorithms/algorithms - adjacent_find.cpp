//
//  algorithms - adjacent_find.cpp
//  adjacent_find
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

bool func4(int elem1, int elem2)
{
    if(elem1 == elem2 + 2)
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
    list<int> list1;
    list<int> list2;
    list1.push_back(1);
    list1.push_back(1);
    list1.push_back(4);
    list1.push_back(2);
    list1.push_back(3);
    
    list2.push_back(3);
    list2.push_back(4);
    list<int>::iterator it_list;
    
    // return first two number equal
    it_list = adjacent_find(list1.begin(), list1.end());
    if(it_list != list1.end())
    {
        cout << *it_list << " " << distance(list1.begin(), it_list) << endl;
    }
    
    // return first two number make op true
    it_list = adjacent_find(list1.begin(), list1.end(), func4);
    if(it_list != list1.end())
    {
        cout << *it_list << " " << distance(list1.begin(), it_list) << endl;
    }


    return 0;
}

