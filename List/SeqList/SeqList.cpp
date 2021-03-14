#include "SeqList.h"

int main()
{
    int arry[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 三种创建类对象的方法
    SeqList<int> seqlist;
    SeqList<int> seqlist1(arry, 10);
    SeqList<int> *seqlist2 = new SeqList<int>(arry, 10);
    cout << seqlist1.get(5) << endl;
    cout << seqlist2->get(5) << endl;
    cout << seqlist1.locate(10) << endl;
    cout << seqlist2->locate(10) << endl;
    seqlist1.insert(3, 11);
    seqlist2->insert(4, 12);
    seqlist1.Delete(1);
    seqlist2->Delete(1);
    seqlist1.printList();
    seqlist2->printList();
    system("pause");
    return 0;
}