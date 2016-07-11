//
//  queue.cpp
//  从上往下打印二叉树
//
//  Created by JacobLan on 16/7/10.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#include "queue.hpp"
#include <iostream>
using namespace std;


queue::queue()
{
    front = nullptr;
    tail = nullptr;
}

bool queue::is_empty()
{
    if (front == nullptr) {
        return true;
    }
    else
    {
        return false;
    }
}

bool queue::in_queue(bin_tree_node* data)
{
    
    if (data == nullptr) {
        return true;
    }
    if (is_empty()) {
        queue_node* tmp = new queue_node;
        tmp->p_queue_data = data;
        tmp->p_next = nullptr;
        front = tail = tmp;
        return true;
    }
    else
    {
        queue_node* tmp = new queue_node;
        tmp->p_queue_data = data;
        tmp->p_next = nullptr;
        tail->p_next = tmp;
        tail = tmp;
        return true;
    }
}


bin_tree_node* queue::out_queue()
{
    if (is_empty()) {
        return nullptr;
    }
    else
    {
        bin_tree_node* data = front->p_queue_data;
        queue_node* tmp = front;
        front = front->p_next;
        delete tmp;
        return data;
    }
}