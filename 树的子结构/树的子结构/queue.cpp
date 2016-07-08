//
//  queue.cpp
//  树的子结构
//
//  Created by JacobLan on 16/7/8.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#include "queue.hpp"
#include "bin_tree.hpp"


queue::queue()
{
    front = tail = nullptr;
}

//返回指向 树节点的指针
bin_tree_node* queue::out_queue()
{
    if (front == nullptr) {
        return nullptr;
    }
    queue_node* tmp = front;
    front = front->p_next;
    return *tmp->p_p;
}

void queue::in_queue(bin_tree_node** in_adress)
{
    //空队列
    if (front == nullptr && tail == nullptr) {
        queue_node* tmp = new queue_node;
        tmp->p_p = in_adress;
        tmp->p_next = nullptr;
        front = tail = tmp;
    }
    
    //非空
    if (*in_adress == nullptr) {
        return;
    }
 
    queue_node* tmp = new queue_node;
    tmp->p_p = in_adress;
    tmp->p_next =nullptr;
    tail->p_next = tmp;
    tail = tmp;
    
}