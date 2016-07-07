//
//  Solution.cpp
//  调整数组顺序使奇数位于偶数前面
//
//  Created by JacobLan on 16/7/2.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#include "Solution.hpp"
#include <iostream>
using namespace std;

void Solution::order_odd_even(int *array, int size,int* tmp)
{
    order_with_merge_sort(array, 0, size-1, tmp);
}

//传入两个已经排好序的有序表,合并为一个
void Solution::merge_odd_even(int* array, int head, int mid, int tail, int* tmp)
{
    int first = head;
    int second = mid;
    //前一部分的奇数部分进入 tmp 数组
    int i = 0;
    for (; i < mid; i++) {
        if (is_odd(array[first]))
        {
            tmp[i] = array[first];
            first++;
        }
        else
        {
            break;
        }
    }
    //后一部分的奇数部分进入 tmp数组
    for (; second <= tail; i++) {
        if (is_odd(array[second]))
        {
            tmp[i] = array[second];
            second++;
        }
        else
        {
            break;
        }
    }
    //前一部分的偶数部分进入 tmp 数组
    while (first <= mid-1) {
        tmp[i] = array[first];
        i++;
        first++;
    }
    //后一部分的偶数部分进入 tmp 数组
    while (second <= tail) {
        tmp[i] = array[second];
        i++;
        second++;
    }
    //将 tmp 中的数据复制到 array 中
    int equal_head = head;
    for (int j = 0; j <= tail - head ; j++) {
        array[equal_head++] = tmp[j];
    }
}

//奇数 1   偶数 0
bool Solution::is_odd(int x)
{
    //快速判断奇偶性... x &1 = 1时.. x 补码最后一位一定1..即 2^0 = 1...所以必为奇数
    if (x & 1) {
        return true;
    }
    else
    {
        return false;
    }
}

//主方法
void Solution::order_with_merge_sort(int*array, int head, int tail,int* tmp)
{
    if (head < tail) {
        int mid = (head + tail)/2;
        order_with_merge_sort(array, head, mid, tmp);
        order_with_merge_sort(array, mid+1, tail, tmp);
        //形参 mid 为第二个有序表的头 所以实参要先 +1
        merge_odd_even(array, head, mid+1, tail, tmp);
    }
}
