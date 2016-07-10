//
//  solution.hpp
//  栈的压入、弹出序列
//
//  Created by JacobLan on 16/7/9.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>
#include "stack.hpp"
class solution
{
    stack stk;
public:
    bool is_pop_order(int* push_sequence, int* will_prove, int array_length);
    
};

#endif /* solution_hpp */
