#include "Dijkstra.h"

/*
测试数据
6 8
1 3 10
1 5 30
1 6 100
2 3 5
3 4 50
4 6 10
5 6 60
5 4 20
*/
int main()
{
    int vexnum, edge;
    cout << "输入图的顶点个数和边的条数" << endl;
    cin >> vexnum >> edge;
    Dijkstra graph(vexnum, edge);
    graph.createGraph();
    graph.print();
    graph.Dijkstra_real(2);
    graph.print_path(2);
    system("pause");
    return 0;
}
