#pragma once
#include <iostream>

template< typename TYPE >
class BinaryTreeNode
{
    public:
    BinaryTreeNode( TYPE element )
    {
        m_element = element;
        lChild = nullptr;
        rChild = nullptr;
    }
        TYPE m_element;
        BinaryTreeNode *lChild;
        BinaryTreeNode *rChild;
};

template< typename TYPE >
class BinaryTree
{
    public:
        bool InitTree();
        bool CreateTree( BinaryTreeNode< TYPE > &root_node );
        bool CreateTree( BinaryTreeNode< TYPE > &parent_node, BinaryTreeNode< TYPE > &node, bool is_left_child );
        bool ClearTree();
        bool TreeEmpty();
        bool DeleteChild( BinaryTreeNode< TYPE > &parent_node, bool is_left_child );
        bool PreOrderTraverse( BinaryTreeNode< TYPE > &node );
        bool InOrderTraverse( BinaryTreeNode< TYPE > &node );
        bool PostOrderTraverse( BinaryTreeNode< TYPE > &node );
    private:
        BinaryTreeNode< TYPE > *m_Root;
};

template< typename TYPE >
bool BinaryTree< TYPE >::InitTree()
{
    m_Root = nullptr;
}

template< typename TYPE >
bool BinaryTree< TYPE >::CreateTree( BinaryTreeNode< TYPE > &root_node )
{
    m_Root = &root_node;
    return true;
}

template< typename TYPE >
bool BinaryTree< TYPE >::CreateTree( BinaryTreeNode< TYPE > &parent_node, BinaryTreeNode< TYPE > &node, bool is_left_child )
{
    if( is_left_child == true )
    {
        parent_node.lChild = &node;
    }
    else
    {
        parent_node.rChild = &node;
    }
    return true;
}

template< typename TYPE >
bool BinaryTree< TYPE >::ClearTree()
{
    m_Root = nullptr;
}

template< typename TYPE >
bool BinaryTree< TYPE >::TreeEmpty()
{
    return m_Root == nullptr;
}

template< typename TYPE >
bool BinaryTree< TYPE >::DeleteChild( BinaryTreeNode< TYPE > &parent_node, bool is_left_child )
{
    if( is_left_child == true )
    {
        parent_node.lChild = nullptr;
    }
    else
    {
        parent_node.rChild = nullptr;
    }
    return true;
}

template< typename TYPE >
bool BinaryTree< TYPE >::PreOrderTraverse( BinaryTreeNode< TYPE > &node )
{
    std::cout << node.m_element << " ";
    if( node.lChild != nullptr )
    {
        PreOrderTraverse( *node.lChild );
    }
    if( node.rChild != nullptr )
    {
        PreOrderTraverse( *node.rChild );
    }
    return true;
}

template< typename TYPE >
bool BinaryTree< TYPE >::InOrderTraverse( BinaryTreeNode< TYPE > &node )
{
    if( node.lChild != nullptr )
    {
        InOrderTraverse( *node.lChild );
    }
    std::cout << node.m_element << " ";
    if( node.rChild != nullptr )
    {
        InOrderTraverse( *node.rChild );
    }
    return true;
}

template< typename TYPE >
bool BinaryTree< TYPE >::PostOrderTraverse( BinaryTreeNode< TYPE > &node )
{
    if( node.lChild != nullptr )
    {
        PostOrderTraverse( *node.lChild );
    }
    if( node.rChild != nullptr )
    {
        PostOrderTraverse( *node.rChild );
    }
    std::cout << node.m_element << " ";
    return true;
}