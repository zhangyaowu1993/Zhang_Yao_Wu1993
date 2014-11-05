#pragma once
#include <iostream>

template< typename TYPE >
struct SingleLinkListNode
{
    TYPE element;
    SingleLinkListNode *link;
};

template< typename TYPE >
class SingleLinkLinearList
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
        SingleLinkListNode< TYPE > *m_ListHead;
};


template< typename TYPE >
bool SingleLinkLinearList< TYPE >::InitList()
{
    m_ListLength = 0;
    m_ListHead = nullptr;
    return true;
}

template< typename TYPE >
bool SingleLinkLinearList< TYPE >::IsEmpty()
{
    return m_ListLength == 0;
}

template< typename TYPE >
bool SingleLinkLinearList< TYPE >::ClearList()
{
    SingleLinkListNode< TYPE > *clear_temp_1 = m_ListHead;
    SingleLinkListNode< TYPE > *clear_temp_2 = m_ListHead->link;
    while( clear_temp_1->link != nullptr )
    {
        delete clear_temp_1;
        clear_temp_1 = clear_temp_2;
        clear_temp_2 = clear_temp_2->link;
    }
    delete clear_temp_1;
    m_ListLength = 0;
    m_ListHead = nullptr;
    return true;
}

template< typename TYPE >
bool SingleLinkLinearList< TYPE >::GetElem( int locate, TYPE &element )
{
    if( locate < 1 || locate > m_ListLength )
    {
        std::cout << "Out Of Bound" << std::endl;
    }
    else
    {
        SingleLinkListNode< TYPE > *get_elem_temp = m_ListHead;
        for( int i = 0; i < locate - 1; i++ )
        {
            get_elem_temp = get_elem_temp->link;
        }
        element = get_elem_temp->element;
        return true;
    }
}

template< typename TYPE >
bool SingleLinkLinearList< TYPE >::LocateElem( TYPE element, int &locate )
{
    int search_temp = 1;
    SingleLinkListNode< TYPE > *search_node_temp = m_ListHead;
    while( search_node_temp != nullptr )
    {
        if( search_node_temp->element == element )
        {
            locate = search_temp;
            return true;
        }
        search_node_temp = search_node_temp->link;
        search_temp++;
    }
    locate = 0;
    return false;
}

template< typename TYPE >
bool SingleLinkLinearList< TYPE >::Insert( int locate, TYPE element )
{
    if( locate < 1 || locate > m_ListLength + 1 )
    {
        std::cout << "Out Of Bound" << std::endl;
        return false;
    }
    else
    {
        SingleLinkListNode< TYPE > *NewNode = new SingleLinkListNode< TYPE >;
        if( NewNode == nullptr )
        {
            std::cout << "Fail New Heap" << std::endl;
            return false;
        }

        NewNode->element = element;

        if( locate == 1 )                                                                          // 分为 在头结点插入, 在尾部插入, 在中间插入    
        {
            NewNode->link = m_ListHead;
            m_ListHead = NewNode;
        }
        else if( locate == m_ListLength + 1 )                                               // 在尾部插入
        {
            NewNode->link = nullptr;

            SingleLinkListNode< TYPE > *insert_temp = m_ListHead;
            while( insert_temp->link != nullptr )
            {
                insert_temp = insert_temp->link;
            }
            insert_temp->link = NewNode;
        }
        else                                                                                           // 在中间插入
        {
            SingleLinkListNode< TYPE > *insert_temp = m_ListHead;
            for( int i = 0; i < locate - 2; i++ )
            {
                insert_temp = insert_temp->link;
            }
            NewNode->link = insert_temp->link;
            insert_temp->link = NewNode;
        }
        m_ListLength++;
        return true;
    }
}

template< typename TYPE >
bool SingleLinkLinearList< TYPE >::Delete( int locate, TYPE &element )
{
    if( locate < 1 || locate > m_ListLength )
    {
        std::cout << "Out Of Bound" << std::endl;
        return false;
    }
    else
    {
        if( locate == 1 )                                                                           // 分为删除头结点 尾节点 中间节点
        {
            SingleLinkListNode< TYPE > *delete_temp = m_ListHead;
            element = delete_temp->element;
            m_ListHead = delete_temp->link;
            delete delete_temp;
            m_ListLength--;
        }
        else if( locate == m_ListLength )                                                      // 删除尾节点
        {
            SingleLinkListNode< TYPE > *delete_temp = m_ListHead;
            while( delete_temp->link->link != nullptr )
            {
                delete_temp = delete_temp->link;
            }
            element = delete_temp->link->element;
            delete delete_temp->link;
            delete_temp->link = nullptr;
        }
        else                                                                                            // 删除中间节点
        {
            SingleLinkListNode< TYPE > *delete_temp_1 = m_ListHead;
            SingleLinkListNode< TYPE > *delete_temp_2 = m_ListHead->link;
            for( int i = 0; i < locate - 2; i++ )
            {
                delete_temp_1 = delete_temp_1->link;
                delete_temp_2 = delete_temp_2->link;
            }
            delete_temp_1->link = delete_temp_1->link->link;
            element = delete_temp_2->element;
            delete delete_temp_2;
        }
        return true;
    }
}

template< typename TYPE >
bool SingleLinkLinearList< TYPE >::OutPut()
{
    SingleLinkListNode< TYPE > *output_temp = m_ListHead;
    while( output_temp != nullptr )
    {
        std::cout << output_temp->element << " ";
        output_temp = output_temp->link;
    }
    std::cout << std::endl;
    return true;
}

template< typename TYPE >
int SingleLinkLinearList< TYPE >::Length()
{
    return m_ListLength;
}
