//
//  solution.hpp
//  包含min函数的栈
//
//  Created by JacobLan on 16/7/9.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp
#include "stack.hpp"
#include <stdio.h>

class solution {
    stack normal;
    stack min_stack;
public:
    bool get_min(int& e);
    bool in_stack(int data);
    bool out_stack(int& e);
};


#endif /* solution_hpp */
