//
//  bin_tree.hpp
//  从上往下打印二叉树
//
//  Created by JacobLan on 16/7/10.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef bin_tree_hpp
#define bin_tree_hpp

#include <stdio.h>

struct bin_tree_node {
    int data;
    bin_tree_node* left_child;
    bin_tree_node* right_child;
};

class bin_tree
{
    bin_tree_node* root;
    void pre_print(bin_tree_node* root);
public:
    bin_tree();
    bin_tree_node* creat(bin_tree_node* root, int empty_end);
    void pre_print_bin_tree();
    bin_tree_node* get_root();
};

#endif /* bin_tree_hpp */
