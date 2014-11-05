//
//  main.cpp
//  zhangyaowu
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <limits>

using namespace std;

int main( int argc, const char *argv[] )
{
    // use bitset manage a group variable
    enum Color
    {
        red,
        black,
        yello,
        white,
    };
    
    string ColorString[] =
    {
        "red",
        "black",
        "yello",
        "white",
    };
    
    bitset<white + 1> col;
    col.set(red);
    col.set(yello);
    
    cout << col << endl;
    cout << col.count() << endl;
    cout << ~col << endl;
    
    if(col.any())
    {
        for(int i = 0; i < white + 1; i++)
        {
            if(col[i])
            {
                cout << ColorString[i] << " ";
            }
        }
    }
    
    cout << endl;
    
    
    // use bitset translate hex to binary
    cout << bitset<numeric_limits<unsigned short>::digits>(15) << endl;
    cout << bitset<8>(15) << endl;
    cout << bitset<16>(string("1001")).to_ullong() << endl;
    
    
    // use bitset manage a group true or false
    bitset<5> bit1(3);
    bitset<5> bit2(5);
    cout << bit1 << endl;
    cout << bit2 << endl;
    for(int i = 4; i >= 0; i--)
    {
        bit1[i] = bit1[i] & bit2[i];
    }
    cout << bit1 << endl;
    
    return 0;
}
