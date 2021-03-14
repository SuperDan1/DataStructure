/************************************************************/
/*                程序作者：SuperDan                        */
/*                程序完成时间：2019/4/16                   */
/*  Dijkstra最短路径算法实现，输入为有向图，输出为最短路径  */
/************************************************************/
#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 记录起点到每个顶点的最短路径的信息（最短路径值，最短路径，是否visit）
struct Dis
{
    string path;
    int value;
    bool visit; // visit=true表示已经找到最短路径，无需再次访问
    Dis()
    {
        visit = false;
        value = 0;
        path = "";
    }
};

class Dijkstra
{
private:
    int vexnum; // 图中顶点个数
    int edge;   // 图中边的个数
    int **arc;  // 邻接矩阵
    Dis *dis;   // 记录各个顶点最短路径的信息

public:
    // 构造函数
    Dijkstra(int vexnum, int edge);
    // 析构函数
    ~Dijkstra();
    // 判断每次输入的边的信息是否合法：编号从1开始
    bool check_edge_value(int start, int end, int weight);
    // 创建图
    void createGraph();
    // 打印邻接矩阵
    void print();
    // 求最短路径
    void Dijkstra_real(int begin);
    // 打印最短路径
    void print_path(int);
};