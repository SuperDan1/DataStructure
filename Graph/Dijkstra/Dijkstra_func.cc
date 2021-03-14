#include "Dijkstra.h"

Dijkstra::Dijkstra(int vexnum, int edge)
{
    // 初始化顶点数和边数
    this->vexnum = vexnum;
    this->edge = edge;
    // 为邻接矩阵开辟空间和赋初值
    arc = new int *[this->vexnum];
    dis = new Dis[this->vexnum];
    for (int i = 0; i < this->vexnum; i++)
    {
        arc[i] = new int[this->vexnum];
        for (int j = 0; j < this->vexnum; j++)
            arc[i][j] = INT_MAX;
    }
}

Dijkstra::~Dijkstra()
{
    delete[] dis;
    for (int i = 0; i < this->vexnum; i++)
    {
        delete this->arc[i];
    }

    delete arc;
}

bool Dijkstra::check_edge_value(int start, int end, int weight)
{
    if (start < 1 || end < 1 || start > vexnum || end > vexnum || weight < 0)
        return false;
    return true;
}

void Dijkstra::createGraph()
{
    cout << "请输入每条边的起点和终点（顶点编号从1开始）以及其权重" << endl;
    int start;
    int end;
    int weight;
    int count = 0;
    while (count != this->edge)
    {
        cin >> start >> end >> weight;
        // 首先判断边的信息是否合法
        while (!this->check_edge_value(start, end, weight))
        {
            cout << "输入的边的信息不合法，请重新输入" << endl;
            cin >> start >> end >> weight;
        }
        // 对邻接矩阵对应上的点赋值
        arc[start - 1][end - 1] = weight;
        // 无向图添加下列代码
        // arc[end - 1][start - 1] = weight;
        ++count;
    }
}

void Dijkstra::print()
{
    cout << "图的邻接矩阵为：" << endl;
    for (int i = 0; i < vexnum; i++)
    {
        for (int j = 0; j < vexnum; j++)
        {
            if (arc[i][j] == INT_MAX)
                cout << "∞"
                     << " ";
            else
                cout << arc[i][j] << " ";
        }
        cout << endl;
    }
}

void Dijkstra::Dijkstra_real(int begin)
{
    // 初始化dis数组
    for (int i = 0; i < this->vexnum; i++)
    {
        // 设置当前的路径
        dis[i].path = "v" + to_string(begin) + "-->v" + to_string(i + 1);
        dis[i].value = arc[begin - 1][i];
    }
    // 设置起点到起点的路径为0
    dis[begin - 1].value = 0;
    dis[begin - 1].visit = true;
    int count = 1;
    // 计算剩余顶点的最短路径
    while (count != this->vexnum - 1)
    {
        // temp保存当前最短路径的下标
        // min保存最短路径值
        int temp = 0;
        int min = INT_MAX;
        for (int i = 0; i < this->vexnum; i++)
        {
            if (!dis[i].visit && dis[i].value < min)
            {
                temp = i;
                min = dis[i].value;
            }
        }
        // 把temp对应的顶点加入到已知的最短路径集合
        dis[temp].visit = true;
        ++count;
        for (int i = 0; i < this->vexnum; i++)
        {
            if (!dis[i].visit && arc[temp][i] != INT_MAX && (dis[temp].value + arc[temp][i]) < dis[i].value)
            {
                //如果新得到的边可以影响其他为访问的顶点，那就就更新它的最短路径和长度
                dis[i].value = dis[temp].value + arc[temp][i];
                dis[i].path = dis[temp].path + "-->v" + to_string(i + 1);
            }
        }
    }
}

void Dijkstra::print_path(int begin)
{
    string s;
    s = "v" + to_string(begin);
    cout << "以" << s << "为起点的图的最短路径为：" << endl;
    for (int i = 0; i < vexnum; i++)
    {
        if (dis[i].value != INT_MAX)
            cout << dis[i].path << "=" << dis[i].value << endl;
        else
            cout << dis[i].path << "是无最短路径的" << endl;
    }
}
