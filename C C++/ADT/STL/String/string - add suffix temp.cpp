//
//  string - add suffix temp.cpp
//  add suffix temp
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main( int argc, const char *argv[] )
{
    string filename("runbat");
    
    string::size_type idx = filename.find(".");
    if(idx == string::npos)
    {
        filename += ".temp";
    }
    else
    {
        string basename;
        string suffix;
        
        basename = filename.substr(0, idx);
        suffix = filename.substr(idx, string::npos);
        if(suffix.empty() == true)
        {
            filename += "temp";
        }
        else
        {
            filename.replace(idx + 1, suffix.size(), "temp");
        }
    }
    
    cout << filename << endl;
    
    return 0;
}
