#pragma once
#include <iostream>

const int ARR_SHARED_STACK_MAX_NUM = 1024;

template< typename TYPE >
class ArraySharedStack
{
    public:
        bool InitStack();
        bool ClearStack();
        bool IsLeftStackEmpty();
        bool IsRightStackEmpty();
        bool LeftStackGetTop( TYPE &element );
        bool RightStackGetTop( TYPE &element );
        bool LeftStackPush( TYPE element );
        bool RightStackPush( TYPE element );
        bool LeftStackPop( TYPE &element );
        bool RightStackPop( TYPE &element );
        bool LeftStackOutPut();
        bool RightStatckOutPut();
        int LeftStackLength();
        int RightStackLength();
    private:
        int m_LeftStackLength;
        int m_RightStackLength;
        TYPE m_SharedStack[ARR_SHARED_STACK_MAX_NUM];
};

template< typename TYPE >
bool ArraySharedStack< TYPE >::InitStack()
{
    m_LeftStackLength = 0;
    m_RightStackLength = 0;
    return true;
}

template< typename TYPE >
bool ArraySharedStack< TYPE >::ClearStack()
{
    m_LeftStackLength = 0;
    m_RightStackLength = 0;
    for( auto clear_temp : m_SharedStack )
    {
        clear_temp = 0;
    }
    return true;
}

template< typename TYPE >
bool ArraySharedStack< TYPE >::IsLeftStackEmpty()
{
    return m_LeftStackLength == 0;
}

template< typename TYPE >
bool ArraySharedStack< TYPE >::IsRightStackEmpty()
{
    return m_RightStackLength == 0;
}

template< typename TYPE >
bool ArraySharedStack< TYPE >::LeftStackGetTop( TYPE &element )
{
    if( m_LeftStackLength == 0 )
    {
        std::cout << "Out Of Bound" << std::endl;
        return false;
    }
    else
    {
        element = m_SharedStack[m_LeftStackLength - 1];
        return true;
    }
}

template< typename TYPE >
bool ArraySharedStack< TYPE >::RightStackGetTop( TYPE &element )
{
    if( m_RightStackLength == 0 )
    {
        std::cout << "Out Of Bound" << std::endl;
        return false;
    }
    else
    {
        element = m_SharedStack[ARR_SHARED_STACK_MAX_NUM - m_RightStackLength];
        return true;
    }
}

template< typename TYPE >
bool ArraySharedStack< TYPE >::LeftStackPush( TYPE element )
{
    if( m_LeftStackLength + m_RightStackLength >= ARR_SHARED_STACK_MAX_NUM )
    {
        std::cout << "Over Flow" << std::endl;
        return false;
    }
    else
    {
        m_SharedStack[m_LeftStackLength] = element;
        m_LeftStackLength++;
        return true;
    }
}

template< typename TYPE >
bool ArraySharedStack< TYPE >::RightStackPush( TYPE element )
{
    if( m_LeftStackLength + m_RightStackLength >= ARR_SHARED_STACK_MAX_NUM )
    {
        std::cout << "Over Flow" << std::endl;
        return false;
    }
    else
    {

        m_SharedStack[ARR_SHARED_STACK_MAX_NUM - m_RightStackLength - 1] = element;
        m_RightStackLength++;
        return true;
    }
}

template< typename TYPE >
bool ArraySharedStack< TYPE >::LeftStackPop( TYPE &element )
{
    if( m_LeftStackLength == 0 )
    {
        std::cout << "Over Flow" << std::endl;
        return false;
    }
    else
    {
        element = m_SharedStack[m_LeftStackLength - 1];
        m_LeftStackLength--;
        return true;
    }
}

template< typename TYPE >
bool ArraySharedStack< TYPE >::RightStackPop( TYPE &element )
{
    if( m_RightStackLength == 0 )
    {
        std::cout << "Over Flow" << std::endl;
        return false;
    }
    else
    {
        element = m_SharedStack[ARR_SHARED_STACK_MAX_NUM - m_RightStackLength];
        m_RightStackLength--;
        return true;
    }
}

template< typename TYPE >
bool ArraySharedStack< TYPE >::LeftStackOutPut()
{
    for( int i = 0; i < m_LeftStackLength; i++ )
    {
        std::cout << m_SharedStack[i] << " ";
    }
    std::cout << std::endl;
    return true;
}

template< typename TYPE >
bool ArraySharedStack< TYPE >::RightStatckOutPut()
{
    for( int i = 0; i < m_RightStackLength; i++ )
    {
        std::cout << m_SharedStack[ARR_SHARED_STACK_MAX_NUM - 1 - i] << " ";
    }
    std::cout << std::endl;
    return true;
}

template< typename TYPE >
int ArraySharedStack< TYPE >::LeftStackLength()
{
    return m_LeftStackLength;
}

template< typename TYPE >
int ArraySharedStack< TYPE >::RightStackLength()
{
    return m_RightStackLength;
}