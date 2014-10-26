//
//  special container priority_queue.cpp
//  priority_queue
//
//  Created by zhang_yao_wu1993 on 14/10/21.
//  Copyright (c) 2014年 zhang_yao_wu1993. All rights reserved.
//

#include <iostream>
#include <queue>

#include <string>

using namespace std;

struct Person
{
    Person(string name, int priority)
    {
        m_name = name;
        m_priority = priority;
    }
    string m_name;
    int m_priority;
};

class PersonCompare
{
public:
    bool operator()(Person p1, Person p2)
    {
        if(p1.m_priority > p2.m_priority)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main( int argc, const char *argv[] )
{
    priority_queue<Person, deque<Person>, PersonCompare> table;

    table.push(Person("小李", 5));
    table.push(Person("小王", 3));
    table.push(Person("小张", 2));
    table.push(Person("小孙", 3));
    table.push(Person("小周", 1));
    
    while(table.empty() != true)
    {
        cout << table.top().m_priority << " " << table.top().m_name << endl;
        table.pop();
    }
    
    return 0;
}
