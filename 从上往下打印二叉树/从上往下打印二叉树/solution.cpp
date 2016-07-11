//
//  solution.cpp
//  从上往下打印二叉树
//
//  Created by JacobLan on 16/7/10.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#include "solution.hpp"
#include <iostream>

using namespace std;

void solution::print_from_top_to_bottom(bin_tree_node* root)
{
    if (root == nullptr) {
        return;
    }
    
    qee.in_queue(root);
    
    while (!qee.is_empty()) {
        bin_tree_node* out_queue_adress;
        //出队列,并打印
        out_queue_adress = qee.out_queue();
        cout << out_queue_adress->data << ' ';
        //出队列的有效子节点入队列
        qee.in_queue(out_queue_adress->left_child);
        qee.in_queue(out_queue_adress->right_child);
        
    }
}


bin_tree_node* solution::get_root()
{
    return bt.get_root();
}