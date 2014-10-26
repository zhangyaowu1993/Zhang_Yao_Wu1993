#pragma once
#include <iostream>

template< typename TYPE >
struct DoubleLinkListNode
{
    TYPE element;
    DoubleLinkListNode *backlink;
    DoubleLinkListNode *nextlink;
};

template< typename TYPE >
class DoubleLinkLinearList
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
        DoubleLinkListNode< TYPE > *m_ListHead;
};


template< typename TYPE >
bool DoubleLinkLinearList< TYPE >::InitList()
{
    m_ListLength = 0;
    m_ListHead = nullptr;
    return true;
}

template< typename TYPE >
bool DoubleLinkLinearList< TYPE >::IsEmpty()
{
    return m_ListLength == 0;
}

template< typename TYPE >
bool DoubleLinkLinearList< TYPE >::ClearList()
{
    DoubleLinkListNode< TYPE > *clear_temp_1 = m_ListHead;
    DoubleLinkListNode< TYPE > *clear_temp_2 = m_ListHead->nextlink;
    while( clear_temp_1->nextlink != nullptr )
    {
        delete clear_temp_1;
        clear_temp_1 = clear_temp_2;
        clear_temp_2 = clear_temp_2->nextlink;
    }
    delete clear_temp_1;
    m_ListLength = 0;
    m_ListHead = nullptr;
    return true;
}

template< typename TYPE >
bool DoubleLinkLinearList< TYPE >::GetElem( int locate, TYPE &element )
{
    if( locate < 1 || locate > m_ListLength )
    {
        std::cout << "Out Of Bound" << std::endl;
        element = 0;
        return false;
    }
    else
    {
        DoubleLinkListNode< TYPE > *get_elem_temp = m_ListHead;
        for( int i = 0; i < locate - 1; i++ )
        {
            get_elem_temp = get_elem_temp->nextlink;
        }
        element = get_elem_temp->element;
        return true;
    }
}

template< typename TYPE >
bool DoubleLinkLinearList< TYPE >::LocateElem( TYPE element, int &locate )
{
    int search_temp = 1;
    DoubleLinkListNode< TYPE > *search_node_temp = m_ListHead;
    while( search_node_temp != nullptr )
    {
        if( search_node_temp->element == element )
        {
            locate = search_temp;
            return true;
        }
        search_node_temp = search_node_temp->nextlink;
        search_temp++;
    }
    locate = 0;
    return false;
}

template< typename TYPE >
bool DoubleLinkLinearList< TYPE >::Insert( int locate, TYPE element )
{
    if( locate < 1 || locate > m_ListLength + 1 )
    {
        std::cout << "Out Of Bound" << std::endl;
        return false;
    }
    else
    {
        DoubleLinkListNode< TYPE > *NewNode = new DoubleLinkListNode< TYPE >;
        if( NewNode == nullptr )
        {
            std::cout << "Fail New Heap" << std::endl;
            return false;
        }

        NewNode->element = element;

        if( locate == 1 )                                                                          // 分为 在头结点插入, 在尾部插入, 在中间插入
        {
            NewNode->nextlink = m_ListHead;
            m_ListHead = NewNode;
            m_ListLength++;
        }
        else if( locate == m_ListLength + 1 )                                               // 在尾部插入
        {
            NewNode->nextlink = nullptr;

            DoubleLinkListNode< TYPE > *insert_temp = m_ListHead;
            while( insert_temp->nextlink != nullptr )
            {
                insert_temp = insert_temp->nextlink;
            }
            insert_temp->nextlink = NewNode;
            NewNode->backlink = insert_temp;
            m_ListLength++;
        }
        else                                                                                           // 在中间插入
        {
            DoubleLinkListNode< TYPE > *insert_temp = m_ListHead;
            for( int i = 0; i < locate - 2; i++ )
            {
                insert_temp = insert_temp->nextlink;
            }
            NewNode->nextlink = insert_temp->nextlink;
            insert_temp->nextlink = NewNode;
            NewNode->backlink = insert_temp;
            m_ListLength++;
        }
        return true;
    }
}

template< typename TYPE >
bool DoubleLinkLinearList< TYPE >::Delete( int locate, TYPE &element )
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
            DoubleLinkListNode< TYPE > *delete_temp = m_ListHead;
            element = delete_temp->element;
            m_ListHead = delete_temp->nextlink;
            delete delete_temp;
            m_ListLength--;
        }
        else if( locate == m_ListLength )                                                      // 删除尾节点
        {
            DoubleLinkListNode< TYPE > *delete_temp = m_ListHead;
            while( delete_temp->nextlink->nextlink != nullptr )
            {
                delete_temp = delete_temp->nextlink;
            }
            element = delete_temp->nextlink->element;
            delete delete_temp->nextlink;
            delete_temp->nextlink = nullptr;
        }
        else                                                                                            // 删除中间节点
        {
            DoubleLinkListNode< TYPE > *delete_temp_1 = m_ListHead;
            DoubleLinkListNode< TYPE > *delete_temp_2 = m_ListHead->nextlink;
            for( int i = 0; i < locate - 2; i++ )
            {
                delete_temp_1 = delete_temp_1->nextlink;
                delete_temp_2 = delete_temp_2->nextlink;
            }
            delete_temp_1->nextlink = delete_temp_1->nextlink->nextlink;
            delete_temp_1->nextlink->backlink = delete_temp_1;
            element = delete_temp_2->element;
            delete delete_temp_2;
        }
        return true;
    }
}

template< typename TYPE >
bool DoubleLinkLinearList< TYPE >::OutPut()
{
    DoubleLinkListNode< TYPE > *output_temp = m_ListHead;
    while( output_temp != nullptr )
    {
        std::cout << output_temp->element << " ";
        output_temp = output_temp->nextlink;
    }
    std::cout << std::endl;
    return true;
}

template< typename TYPE >
int DoubleLinkLinearList< TYPE >::Length()
{
    return m_ListLength;
}
