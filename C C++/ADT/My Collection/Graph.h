#pragma once
#include <iostream>
#include <string>
#include "ArrayLoopQueue.h"

typedef int EDGE_TYPE;
const int GRAPH_VEX_MAX_NUM = 10;                                                  // 最大顶点数
const int GRAPH_INFINITY = INT_MAX;                                                 // 图权值, 数字代表权, 0代表自己连接自己, GRAPH_INFINITY代表没有边
const std::string NO_NAME_NODE = "NULL";

class GraphNode
{
    public:
        GraphNode()
        {
            m_graph_node = NO_NAME_NODE;
        }
        GraphNode( std::string graph_node )
        {
            m_graph_node = graph_node;
        }
        std::string m_graph_node;
};

class Graph
{
    public:
        bool InitGraph();
        bool CreateGraph( GraphNode &begin_vex, GraphNode &end_vex, int weight );
        bool ClearGraph();
        bool LocateVex( GraphNode &vex );
        bool DeleteGraph( GraphNode &begin_vex, GraphNode &end_vex );
        bool OutPutVex();
        bool DFSTraverse();
        bool HFSTraverse();
    private:
        GraphNode *m_vex[GRAPH_VEX_MAX_NUM];                                  	 // 顶点数组
        int m_arc[GRAPH_VEX_MAX_NUM][GRAPH_VEX_MAX_NUM];               	 // 边数组
        int m_vex_num;
        int m_arc_num;
        bool m_dfs_has_visited[GRAPH_VEX_MAX_NUM];                          		// DFS遍历记录表
        bool DFS( int temp );                                                               		// 遍历递归函数
        bool m_hfs_has_visited[GRAPH_VEX_MAX_NUM];                          		// HFS遍历记录表
};


bool Graph::InitGraph()
{
    for( int i = 0; i < GRAPH_VEX_MAX_NUM; i++ )                                  	// 初始化边数组
    {
        for( int j = 0; j < GRAPH_VEX_MAX_NUM; j++ )
        {
            if( i == j )
            {
                m_arc[i][j] = 0;
            }
            else
            {
                m_arc[i][j] = GRAPH_INFINITY;
            }
        }
    }

    m_vex_num = 0;
    m_arc_num = 0;
    
    return true;
}

bool Graph::CreateGraph( GraphNode &begin_vex, GraphNode &end_vex, int weight )
{
    if( &begin_vex == &end_vex || begin_vex.m_graph_node == NO_NAME_NODE || end_vex.m_graph_node == NO_NAME_NODE )
    {
        std::cout << "Wrong Node" << std::endl;
        return false;
    }


    int create_graph_temp_1 = m_vex_num;                                            // 寻找起始点在数组中的位置 否则新建;
    for( int i = 0; i < GRAPH_VEX_MAX_NUM; i++ )
    {
        if( &begin_vex == m_vex[i] )
        {
            create_graph_temp_1 = i;
            break;
        }
    }
    if( create_graph_temp_1 == m_vex_num )
    {
        m_vex[create_graph_temp_1] = &begin_vex;
        m_vex_num++;
    }


    int create_graph_temp_2 = m_vex_num;                                            // 寻找结束点在数组中的位置 否则新建;
    for( int i = 0; i < GRAPH_VEX_MAX_NUM; i++ )
    {
        if( &end_vex == m_vex[i] )
        {
            create_graph_temp_2 = i;
            break;
        }
    }
    if( create_graph_temp_2 == m_vex_num )
    {
        m_vex[create_graph_temp_2] = &end_vex;
        m_vex_num++;
    }

    m_arc[create_graph_temp_1][create_graph_temp_2] = weight;
    m_arc[create_graph_temp_2][create_graph_temp_1] = weight;

    m_arc_num++;
    return true;
}

bool Graph::ClearGraph()
{
    InitGraph();
    return true;
}

bool Graph::LocateVex( GraphNode &vex )
{
    for( int i = 0; i < m_vex_num; i++ )
    {
        if( &vex == m_vex[i] )
        {
            vex.m_graph_node = m_vex[i]->m_graph_node;
            return true;
        }
    }
    return false;
}

bool Graph::DeleteGraph( GraphNode &begin_vex, GraphNode &end_vex )
{
    if( &begin_vex == &end_vex || begin_vex.m_graph_node == NO_NAME_NODE || end_vex.m_graph_node == NO_NAME_NODE )
    {
        std::cout << "Wrong Node" << std::endl;
        return false;
    }


    int delete_graph_temp_1 = m_vex_num;                                            // 寻找起始点在数组中的位置 否则新建;
    for( int i = 0; i < GRAPH_VEX_MAX_NUM; i++ )
    {
        if( &begin_vex == m_vex[i] )
        {
            delete_graph_temp_1 = i;
            break;
        }
    }
    if( delete_graph_temp_1 == m_vex_num )
    {
        std::cout << "Wrong Node" << std::endl;
        return false;
    }


    int delete_graph_temp_2 = m_vex_num;                                            // 寻找结束点在数组中的位置 否则新建;
    for( int i = 0; i < GRAPH_VEX_MAX_NUM; i++ )
    {
        if( &end_vex == m_vex[i] )
        {
            delete_graph_temp_2 = i;
            break;
        }
    }
    if( delete_graph_temp_2 == m_vex_num )
    {
        std::cout << "Wrong Node" << std::endl;
    }


    m_arc[delete_graph_temp_1][delete_graph_temp_2] = GRAPH_INFINITY;   // 完成边数组;
    m_arc[delete_graph_temp_2][delete_graph_temp_1] = GRAPH_INFINITY;   // 完成边数组;

    m_arc_num--;
    return true;
}

bool Graph::OutPutVex()
{
    for( int i = 0; i < GRAPH_VEX_MAX_NUM; i++ )
    {
        for( int j = 0; j < GRAPH_VEX_MAX_NUM; j++ )
        {
            if( m_arc[i][j] == INT_MAX )
            {
                std::cout << "*" << " ";
            }
            else
            {
                std::cout << m_arc[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    return true;
}

bool Graph::DFS( int i )
{
    m_dfs_has_visited[i] = true;
    std::cout << m_vex[i]->m_graph_node << std::endl;
    for( int j = 0; j < m_vex_num; j++ )
    {
        if( m_dfs_has_visited[j] == false && m_arc[i][j] != GRAPH_INFINITY && m_arc[i][j] != 0 )
        {
            DFS( j );
        }
    }
    return true;
}

bool Graph::DFSTraverse()
{
    for( int i = 0; i < GRAPH_VEX_MAX_NUM; i++ )                                    // 初始化遍历数组
    {
        m_dfs_has_visited[i] = false;
    }

    DFS( 0 );

    return true;
}

bool Graph::HFSTraverse()
{
    for( int i = 0; i < GRAPH_VEX_MAX_NUM; i++ )                                    // 初始化遍历数组
    {
        m_hfs_has_visited[i] = false;
    }

    for( int i = 0; i < m_vex_num; i++ )
    {
        if( m_hfs_has_visited[i] == false )
        {
            m_hfs_has_visited[i] = true;
            std::cout << m_vex[i]->m_graph_node << std::endl;

            ArrayLoopQueue< int > hfs_temp_queue;
            hfs_temp_queue.InitQueue();
            hfs_temp_queue.EnQueue( i );
            while( hfs_temp_queue.IsEmpty() == false )
            {
                int hfs_now_node;
                hfs_temp_queue.DeQueue( hfs_now_node );
                for( int j = 0; j < m_vex_num; j++ )
                {
                    if( m_hfs_has_visited[j] == false && m_arc[i][j] != GRAPH_INFINITY && m_arc[i][j] != 0 )
                    {
                        m_hfs_has_visited[j] = true;
                        std::cout << m_vex[j]->m_graph_node << std::endl;
                        hfs_temp_queue.EnQueue( j );
                    }
                }
            }
        }
    }
    return true;
}
