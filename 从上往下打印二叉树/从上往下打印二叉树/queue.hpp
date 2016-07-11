//
//  queue.hpp
//  从上往下打印二叉树
//
//  Created by JacobLan on 16/7/10.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>
#include "bin_tree.hpp"

struct queue_node {
    bin_tree_node* p_queue_data;
    queue_node* p_next;
};

class queue
{
    queue_node* front;
    queue_node* tail;
public:
    queue();
    bool is_empty();
    bool in_queue(bin_tree_node* data);
    bin_tree_node* out_queue();
};

#endif /* queue_hpp */
