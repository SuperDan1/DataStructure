#ifndef _Linear_List_H
#define _Linear_List_H
/*
 * ADT linearList
 * {
 *   instance
 *     有限个元素的有序集合
 *   operation
 *     empty(): 若表空，返回true，否则返回false
 *     size():  返回线性表的大小（表的元素个数）
 *     get(index): 返回线性表中索引为index的元素
 *     indexOf(x): 返回线性表中第一次出现的x的索引。若x不存在，则返回-1
 *     erase(index): 删除索引为index的元素，索引大于index的元素其索引减1
 *     insert(index, x): 把x插入线性表中索引为index的位置上
 *     output(): 从左到右输出表元素
 * }
 */

#include <iostream>
using namespace std;
const int MaxSize = 100;
namespace yftSTL
{
    template <typename T>
    class linearList
    {
    public:
        linearList() { Length = 0; } // 无参构造函数，建立一个空的顺序表
        linearList(T a[], int n);    // 有参构造函数，建立一个长度为n的顺序表
        ~linearList(){};             // 空的析构函数
        int len() { return Length; } // 返回线性表长度
        T get(int i);                // 查找第i个元素
        int locate(int value);       // 查找值为value的元素序号
        void insert(int i, T value); // 在第i个位置插入值为x的元素
        T Delete(int i);             // 删除第i个元素
        void printList();            // 打印线性表
    private:
        T data[MaxSize];             // 线性表最大容量
        int Length;                  // 线性表元素个数
    };

    template <typename T>
    inline linearList<T>::linearList(T a[], int n)
    {
        if (n > MaxSize)
            throw "n大于线性表容量";
        for (int i = 0; i < n; i++)
            data[i] = a[i];
        Length = n;
    }

    template <typename T>
    inline T linearList<T>::get(int i)
    {
        if (i < 0 || i > Length - 1)
            throw "查找位置非法";
        else
            return data[i];
    }

    template <typename T>
    inline int linearList<T>::locate(int value)
    {
        for (int i = 0; i < Length; i++)
        {
            if (data[i] == value)
                return i;
        }
        // cout << "查找值不存在";
        return -1;
    }

    template <typename T>
    inline void linearList<T>::insert(int i, T value)
    {
        if (i < 0 || i > Length)
            throw "插入位置非法";

        for (int j = Length - 1; j >= i; j--)
            data[j + 1] = data[j];
        data[i] = value;
        Length++;
    }

    template <typename T>
    inline T linearList<T>::Delete(int i)
    {
        return T();
    }

    template <typename T>
    inline void linearList<T>::printList()
    {
        for (int i = 0; i < Length; i++)
            cout << data[i] << endl;
    }
}
#endif