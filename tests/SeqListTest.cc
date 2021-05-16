#include "List.h"
#include "gtest/gtest.h"
using namespace yftSTL;

TEST(List, test001)
{
    int arry[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 三种创建类对象的方法
    yftSTL::linearList<int> linearList;
    yftSTL::linearList<int> linearList1(arry, 10);
    yftSTL::linearList<int> *linearList2 = new yftSTL::linearList<int>(arry, 10);
    ASSERT_EQ(linearList1.get(5), 5);
    ASSERT_EQ(linearList2->get(5), 5);
    ASSERT_EQ(linearList1.locate(5), 5);
    ASSERT_EQ(linearList2->locate(5), 5);
    linearList1.insert(3, 11);
    linearList2->insert(4, 12);
    linearList1.Delete(1);
    linearList2->Delete(1);
}
