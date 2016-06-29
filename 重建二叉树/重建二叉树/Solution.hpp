//
//  Solution.hpp
//  重建二叉树
//
//  Created by JacobLan on 16/6/29.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>

struct node{
    int data;
    node* left_node;
    node* right_node;
};

class Solution
{
    int *pre_order;
    int *in_order;
    int m_length;
public:
    void init(int length);
    node* re_build_tree(int start_pre_order, int end_pre_order,
                       int start_in_order, int end_in_order);   //return root
    
    void print_tree(node*);
    
    
};

#endif /* Solution_hpp */
