//
//  Solution.hpp
//  调整数组顺序使奇数位于偶数前面
//
//  Created by JacobLan on 16/7/2.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>

class Solution
{
    int* array;
    int* tmp;
public:
    void order_odd_even(int *array, int size,int* tmp);
    void order_with_merge_sort(int*array, int head, int tail,int* tmp);
    void merge_odd_even(int* array, int head, int mid, int tail, int* tmp);
    bool is_odd(int);
};

#endif /* Solution_hpp */
