//
//  solution.cpp
//  包含min函数的栈
//
//  Created by JacobLan on 16/7/9.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#include "solution.hpp"
#include "stack.hpp"
#include <iostream>
using namespace std;

bool solution::in_stack(int data)
{
    if (normal.is_empty()) {
        normal.push(data);
        min_stack.push(data);
        return false;
    }
    
    int nor_top_data;
    min_stack.get_top_value(nor_top_data);
    
    //比较小的入 min_stack
    if (nor_top_data < data) {
        normal.push(data);
        min_stack.push(nor_top_data);
    }
    else
    {
        normal.push(data);
        min_stack.push(data);
    }
    return true;
}

bool solution::get_min(int &e)
{
    if (normal.is_empty()) {
        return false;
    }
    
    min_stack.get_top_value(e);
    return true;
}

bool solution::out_stack(int &e)
{
    if (normal.is_empty()) {
        e = -10086;     //错误标记
        return false;
    }
    int pop_value;
    normal.pop(e);
    min_stack.pop(pop_value);
    return true;
}