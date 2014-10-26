#pragma once
#include <iostream>

const int ARR_LINEAR_LIST_MAX_NUM = 1024;

template< typename TYPE >
class ArrayLinearList
{
    public:
        bool InitList();
        bool IsEmpty();
        bool ClearList();
        bool GetElem( int locate, TYPE &element );
        bool LocateElem( TYPE element, int &locate );
        bool Insert( int locate, TYPE element );
        bool Delete( int locate, TYPE &element );
        bool OutPut();
        int Length();
    private:
        int m_ListLength;
        TYPE m_LinearList[ARR_LINEAR_LIST_MAX_NUM];
};


template< typename TYPE >
bool ArrayLinearList< TYPE >::InitList()
{
	m_ListLength = 0;
	return true;
}

template< typename TYPE >
bool ArrayLinearList< TYPE >::IsEmpty()
{
	return m_ListLength == 0;
}

template< typename TYPE >
bool ArrayLinearList< TYPE >::ClearList()
{
	m_ListLength = 0;
	return true;
}

template< typename TYPE >
bool ArrayLinearList< TYPE >::GetElem( int locate, TYPE &element )
{
	if( locate < 1 || locate > m_ListLength )
	{
		std::cout << "Out Of Bound" << std::endl;
		return false;
	}
	else
	{
		element = m_LinearList[locate - 1];
		return true;
	}
}

template< typename TYPE >
bool ArrayLinearList< TYPE >::LocateElem( TYPE element, int &locate )
{
	int search_temp = 1;
	for( auto temp : m_LinearList )
	{
		if( element == temp )
		{
			locate = search_temp;
			return true;
		}
		search_temp++;
	}
	locate = 0;
	return false;
}

template< typename TYPE >
bool ArrayLinearList< TYPE >::Insert( int locate, TYPE element )
{
	if( locate < 1 || locate > m_ListLength + 1 || m_ListLength + 1 > ARR_LINEAR_LIST_MAX_NUM )
	{
		std::cout << "Out Of Bound" << std::endl;
		return false;
	}
	else
	{
		for( int i = m_ListLength; i > locate - 1; i-- )
		{
			m_LinearList[i] = m_LinearList[i - 1];
		}
		m_LinearList[locate - 1] = element;
		m_ListLength++;
		return true;
	}
}

template< typename TYPE >
bool ArrayLinearList< TYPE >::Delete( int locate, TYPE &element )
{
	if( locate < 1 || locate > m_ListLength )
	{
		std::cout << "Out Of Bound" << std::endl;
		return false;
	}
	else
	{
		element = m_LinearList[locate - 1];
		for( int i = locate - 1; i < m_ListLength; i++ )
		{
			m_LinearList[i] = m_LinearList[i + 1];
		}
		m_ListLength--;
		return true;
	}
}

template< typename TYPE >
bool ArrayLinearList< TYPE >::OutPut()
{
	for( int i = 0; i < m_ListLength; i++ )
	{
		std::cout << m_LinearList[i] << " ";
	}
	return true;
}

template< typename TYPE >
int ArrayLinearList< TYPE >::Length()
{
	return m_ListLength;
}