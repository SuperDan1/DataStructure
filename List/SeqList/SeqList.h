#ifndef _Seq_List_H
#define _Seq_List_H

#include <iostream>
using namespace std;
const int MaxSize = 100;

template <typename T>
class SeqList
{
public:
    SeqList() { Length = 0; }    // 无参构造函数，建立一个空的顺序表
    SeqList(T a[], int n);       // 有参构造函数，建立一个长度为n的顺序表
    ~SeqList(){};                // 空的析构函数
    int len() { return Length; } // 返回线性表长度
    T get(int i);                // 查找第i个元素
    int locate(int value);       // 查找值为value的元素序号
    void insert(int i, T value); // 在第i个位置插入值为x的元素
    T Delete(int i);             // 删除第i个元素
    void printList();            // 打印线性表
private:
    T data[MaxSize]; // 线性表最大容量
    int Length;      // 线性表元素个数
};

template <typename T>
inline SeqList<T>::SeqList(T a[], int n)
{
    if (n > MaxSize)
        throw "n大于线性表容量";
    for (int i = 0; i < n; i++)
        data[i] = a[i];
    Length = n;
}

template <typename T>
inline T SeqList<T>::get(int i)
{
    if (i < 0 || i > Length - 1)
        throw "查找位置非法";
    else
        return data[i];
}

template <typename T>
inline int SeqList<T>::locate(int value)
{
    for (int i = 0; i < Length; i++)
    {
        if (data[i] == value)
            return i;
    }
    cout << "查找值不存在";
    return -1;
}

template <typename T>
inline void SeqList<T>::insert(int i, T value)
{
    if (i < 0 || i > Length)
        throw "插入位置非法";

    for (int j = Length - 1; j >= i; j--)
        data[j + 1] = data[j];
    data[i] = value;
    Length++;
}

template <typename T>
inline T SeqList<T>::Delete(int i)
{
    return T();
}

template <typename T>
inline void SeqList<T>::printList()
{
    for (int i = 0; i < Length; i++)
        cout << data[i] << endl;
}

#endif