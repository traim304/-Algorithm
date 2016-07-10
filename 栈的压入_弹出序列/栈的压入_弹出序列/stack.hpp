//
//  stack.hpp
//  包含min函数的栈
//
//  Created by JacobLan on 16/7/9.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>

struct stack_node {
    int data;
    stack_node* p_next;
};

class stack
{
    stack_node* top;
public:
    void push(int data);
    bool pop(int& e);
    stack();
    bool is_empty();
    bool get_top_value(int& e);
};



#endif /* stack_hpp */
