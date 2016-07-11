//
//  bin_tree.cpp
//  从上往下打印二叉树
//
//  Created by JacobLan on 16/7/10.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#include "bin_tree.hpp"
#include "bin_tree.hpp"
#include <iostream>
using namespace std;

bin_tree::bin_tree()
{
    cout << "请输入结束(空位)标志符 (int): " << endl;
    int empty_end;
    cin >> empty_end;
    cout << "按先序序列输入构建二叉树: ";
    int data;
    cin >> data;
    if (data != empty_end) {
        root = new bin_tree_node;
        root->data =data;
        root->left_child = creat(root->left_child, empty_end);
        root->right_child = creat(root->right_child, empty_end);
    }
    else
    {
        root = nullptr;
    }
}


bin_tree_node* bin_tree::creat(bin_tree_node *root, int empty_end)
{
    int data;
    cin >> data;
    
    if (data != empty_end) {
        root = new bin_tree_node;
        root->data = data;
        root->left_child = creat(root->left_child, empty_end);
        root->right_child = creat(root->right_child, empty_end);
    }
    else
    {
        root = nullptr;
    }
    return root;
}


void bin_tree::pre_print(bin_tree_node *root)
{
    if (root == nullptr) {
        return;
    }
    cout << root->data << ' ';
    pre_print(root->left_child);
    pre_print(root->right_child);
}

void bin_tree::pre_print_bin_tree()
{
    pre_print(root);
}

bin_tree_node* bin_tree::get_root()
{
    return root;
}