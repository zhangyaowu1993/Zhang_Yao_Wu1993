//
//  algorithms - find_first_of.cpp
//  find_first_of
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

bool func3(int elem1, int elem2)
{
    if(elem1 < elem2)
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
    
    // return first elem iterator that appear in [list1.begin(), list1.end()) and [list2.begin(), list2.end())
    list<int>::iterator it_list;
    it_list = find_first_of(list1.begin(), list1.end(), list2.begin(), list2.end());
    if(it_list != list1.end())
    {
        cout << *it_list << " " << distance(list1.begin(), it_list) << endl;
    }
    
    // return first elem that make all elem in [list2.begin(), list2.end()) make op true
    it_list = find_first_of(list1.begin(), list1.end(), list2.begin(), list2.end(), func3);
    if(it_list != list1.end())
    {
        cout << *it_list << " " << distance(list1.begin(), it_list) << endl;
    }

    

    return 0;
}

