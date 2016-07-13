//
//  solution.hpp
//  二叉树中和为某一值的路径
//
//  Created by JacobLan on 16/7/12.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>


#include "bin_tree.hpp"
#include "stack.hpp"


class solution {
    void find_path(bin_tree_node* root, int expext_num);
public:
    bin_tree bt;
    stack stk;
    void find_path_pub(int sum);
    void print_cur_stack();
};

#endif /* solution_hpp */
