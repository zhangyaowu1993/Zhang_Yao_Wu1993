#pragma once
#include <iostream>

const int ARR_LOOP_QUEUE_MAX_NUM = 1024;

template< typename TYPE >
class ArrayLoopQueue
{
    public:
        bool InitQueue();
        bool ClearQueue();
        bool IsEmpty();
        bool GetHead( TYPE &element );
        bool EnQueue( TYPE element );
        bool DeQueue( TYPE &element );
        bool OutPut();
        int Length();
    private:
        int m_QueueLength;
        int m_QueueHead;
        TYPE m_Queue[ARR_LOOP_QUEUE_MAX_NUM];
};

template< typename TYPE >
bool ArrayLoopQueue< TYPE >::InitQueue()
{
    m_QueueLength = 0;
    m_QueueHead = 0;
    return true;
}

template< typename TYPE >
bool ArrayLoopQueue< TYPE >::ClearQueue()
{
    m_QueueLength = 0;
    m_QueueHead = 0;
    return true;
}

template< typename TYPE >
bool ArrayLoopQueue< TYPE >::IsEmpty()
{
    return m_QueueLength == 0;
}

template< typename TYPE >
bool ArrayLoopQueue< TYPE >::GetHead( TYPE &element )
{
    element = m_Queue[m_QueueHead];
    return true;
}

template< typename TYPE >
bool ArrayLoopQueue< TYPE >::EnQueue( TYPE element )
{
    if( m_QueueLength >= ARR_LOOP_QUEUE_MAX_NUM - 1 )
    {
        std::cout << "Over Flow" << std::endl;
        return false;
    }
    else
    {
        m_Queue[( m_QueueHead + m_QueueLength ) % ARR_LOOP_QUEUE_MAX_NUM] = element;
        m_QueueLength++;
        return true;
    }
}

template< typename TYPE >
bool ArrayLoopQueue< TYPE >::DeQueue( TYPE &element )
{
    if( m_QueueLength < 1 )
    {
        std::cout << "Stack Empty" << std::endl;
        return false;
    }
    else
    {
        element = m_Queue[m_QueueHead];
        m_QueueHead = ( m_QueueHead + 1 ) % ARR_LOOP_QUEUE_MAX_NUM;
        m_QueueLength--;
        return true;
    }
}

template< typename TYPE >
bool ArrayLoopQueue< TYPE >::OutPut()
{
    for( int i = 0; i < m_QueueLength; i++ )
    {
        std::cout << m_Queue[( m_QueueHead + i ) % ARR_LOOP_QUEUE_MAX_NUM] << " ";
    }
    std::cout << std::endl;
    return true;
}

template< typename TYPE >
int ArrayLoopQueue< TYPE >::Length()
{
    return m_QueueLength;
}