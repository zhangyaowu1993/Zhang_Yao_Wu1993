//
//  algorithms - search.cpp
//  search
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <stdlib.h>

using namespace std;

bool func1(int elem1, bool elem2)
{
    if((elem1 % 2 == 0) == elem2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool func2(int elem)
{
    if(elem %3 == 0)
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
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(4);
    arr1.push_back(4);
    arr1.push_back(5);
    arr1.push_back(2);
    arr1.push_back(4);
    arr1.push_back(3);
    
    vector<bool> arr2;
    arr2.push_back(true);
    arr2.push_back(true);
    arr2.push_back(false);
    
    // find first elem iterator of child section that
    // value of section [arr1.begin(), arr1.end()) full equal value of [arr2.begin(), arr2.end())
    vector<int>::iterator it_vect;
    it_vect = search(arr1.begin(), arr1.end(), arr2.begin(), arr2.end());
    if(it_vect != arr1.end())
    {
        cout << *it_vect << endl;
    }
    
    // find first elem iterator of first child section that
    // value of section [arr1.begin(), arr1.end()) and value of section [arr2.begin(), arr2.end()) make op true
    it_vect = search(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), func1);
    if(it_vect != arr1.end())
    {
        cout << *it_vect << " " << distance(arr1.begin(), it_vect) << endl;
    }
    
    
    
    
    // find first elem iterator of last child section that
    // value of section [arr1.begin(), arr1.end()) and value of section [arr2.begin(), arr2.end()) make op true
    it_vect = find_end(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), func1);
    if(it_vect != arr1.end())
    {
        cout << *it_vect << " " << distance(arr1.begin(), it_vect) << endl;
        
    }
    
    
    
    
    arr1.push_back(4);
    arr1.push_back(4);
    arr1.push_back(4);
    
    // return first elem iterator that value 4 appears 2 times
    it_vect = search_n(arr1.begin(), arr1.end(), 2, 4);
    if(it_vect != arr1.end())
    {
        cout << *(arr1.begin() + distance(arr1.begin(), it_vect)) << endl;
    }
    
    return 0;
}