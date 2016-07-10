//
//  solution.cpp
//  栈的压入、弹出序列
//
//  Created by JacobLan on 16/7/9.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#include "solution.hpp"

bool solution::is_pop_order(int* push_sequence, int* will_prove, int array_length)
{
    int locate_p_s = 0;
    int locate_w_p = 0;
    if (stk.is_empty()) {
        stk.push(push_sequence[locate_p_s++]);
    }
    
    int cur_top_value = 0;
    int pop_value = 0;
    
    while (locate_p_s <= array_length && locate_w_p < array_length) {
        stk.get_top_value(cur_top_value);
        //当此时的栈顶元素与待对比序列值相同,则出栈,对比序列后移
        while (cur_top_value == will_prove[locate_w_p] && locate_w_p < array_length) {
            stk.pop(pop_value);
            locate_w_p++;
            stk.get_top_value(cur_top_value);
        }
        //当此时的栈顶元素与待对比序列值不同,则入栈,直到相同,若到入栈序列尾部..
        while (cur_top_value != will_prove[locate_w_p] && locate_p_s <= array_length) {
            stk.push(push_sequence[locate_p_s++]);
            stk.get_top_value(cur_top_value);
        }
        
    }
    
    if (locate_w_p == array_length) {
        return true;
    }

    
    return false;
}