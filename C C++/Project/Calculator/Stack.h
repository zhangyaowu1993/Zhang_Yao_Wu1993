#pragma once
#include <iostream>

template< typename TYPE >
struct SingleLinkListStackNode
{
	TYPE element;
	SingleLinkListStackNode *link;
};

template< typename TYPE >
class SingleLinkListStack
{
	public:
	bool InitStack();
	bool ClearStack();
	bool IsEmtpy();
	bool GetTop( TYPE &element );
	bool Push( TYPE element );
	bool Pop( TYPE &element );
	bool OutPut();
	int Length();
	private:
	int m_StackLength;
	SingleLinkListStackNode< TYPE > *m_StackHead;
	SingleLinkListStackNode< TYPE > *m_StackTail;
};

template< typename TYPE >
bool SingleLinkListStack< TYPE >::InitStack()
{
	m_StackHead = nullptr;
	m_StackTail = nullptr;
	m_StackLength = 0;
	return true;
}

template< typename TYPE >
bool SingleLinkListStack< TYPE >::ClearStack()
{
	SingleLinkListStackNode< TYPE > *clear_temp_1 = m_StackHead;
	SingleLinkListStackNode< TYPE > *clear_temp_2 = m_StackHead->link;
	while( clear_temp_1->link != nullptr )
	{
		delete clear_temp_1;
		clear_temp_1 = clear_temp_2;
		clear_temp_2 = clear_temp_2->link;
	}
	delete clear_temp_1;
	m_StackHead = nullptr;
	m_StackTail = nullptr;
	m_StackLength = 0;
	return true;
}

template< typename TYPE >
bool SingleLinkListStack< TYPE >::IsEmtpy()
{
	return m_StackLength == 0;
}

template< typename TYPE >
bool SingleLinkListStack< TYPE >::GetTop( TYPE &element )
{
	if( m_StackLength == 0 )
	{
		std::cout << "Stack Empty" << std::endl;
		element = 0;
		return false;
	}
	else
	{
		element = m_StackTail->element;
		return true;
	}
}

template< typename TYPE >
bool SingleLinkListStack< TYPE >::Push( TYPE element )
{
	SingleLinkListStackNode< TYPE > *NewNode = new SingleLinkListStackNode < TYPE >;
	if( NewNode == nullptr )
	{
		std::cout << "Fail New Heap" << std::endl;
		return false;
	}

	NewNode->element = element;
	NewNode->link = nullptr;

	if( m_StackLength == 0 )
	{
		m_StackHead = NewNode;
		m_StackTail = NewNode;
	}
	else
	{
		m_StackTail->link = NewNode;
		m_StackTail = NewNode;
	}
	m_StackLength++;
	return true;
}

template< typename TYPE >
bool SingleLinkListStack< TYPE >::Pop( TYPE &element )
{
	SingleLinkListStackNode< TYPE > *pop_temp = m_StackHead;
	if( m_StackLength == 1 )
	{
		element = pop_temp->element;
		delete m_StackHead;
		m_StackHead = nullptr;
		m_StackTail = nullptr;
	}
	else
	{
		for( int i = 0; i < m_StackLength - 2; i++ )
		{
			pop_temp = pop_temp->link;
		}
		element = pop_temp->link->element;
		delete pop_temp->link->link;
		m_StackTail = pop_temp;
	}
	m_StackLength--;
	return true;
}

template< typename TYPE >
bool SingleLinkListStack< TYPE >::OutPut()
{
	SingleLinkListStackNode< TYPE > *output_temp = m_StackHead;
	for( int i = 0; i < m_StackLength; i++ )
	{
		std::cout << output_temp->element << " ";
		output_temp = output_temp->link;
	}
	std::cout << std::endl;
	return true;
}

template< typename TYPE >
int SingleLinkListStack< TYPE >::Length()
{
	return m_StackLength;
}