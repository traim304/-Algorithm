//
//  stack.cpp
//  包含min函数的栈
//
//  Created by JacobLan on 16/7/9.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#include "stack.hpp"

stack::stack()
{
    top = NULL;
}



void stack::push(int data)
{
    stack_node* tmp =  new stack_node;
    tmp->data = data;
    tmp->p_next = NULL;
    if (top == NULL) {
        top = tmp;
        return;
    }
    
    tmp->p_next = top;
    top = tmp;
}

bool stack::pop(int& e)
{
    if (top == NULL) {
        return false;
    }
    
    e = top->data;
    top = top->p_next;
    return true;
}

bool stack::is_empty()
{
    if (top == NULL) {
        return true;
    }
    return false;
}

bool stack::get_top_value(int &e)
{
    if (is_empty()) {
        e = -10086;
        return false;
    }
    
    e = top->data;
    return true;
}

