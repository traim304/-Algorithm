//
//  solution.hpp
//  从上往下打印二叉树
//
//  Created by JacobLan on 16/7/10.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>
#include "bin_tree.hpp"
#include "queue.hpp"

class solution
{
    bin_tree bt;
    queue qee;
public:
    void print_from_top_to_bottom(bin_tree_node* root);
    bin_tree_node* get_root();
};
#endif /* solution_hpp */
