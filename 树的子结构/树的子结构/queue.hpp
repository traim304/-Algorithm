//
//  queue.hpp
//  树的子结构
//
//  Created by JacobLan on 16/7/8.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp
#include "bin_tree.hpp"

#include <stdio.h>

struct queue_node {
    bin_tree_node** p_p;
    queue_node* p_next;
};

class queue
{
public:
    queue_node* front;
    queue_node* tail;
    queue();
    bin_tree_node* out_queue();
    void in_queue(bin_tree_node** in_adress);
};

#endif /* queue_hpp */
