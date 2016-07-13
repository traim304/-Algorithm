//
//  solution.cpp
//  二叉树中和为某一值的路径
//
//  Created by JacobLan on 16/7/12.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#include "solution.hpp"
#include <iostream>
using namespace std;

void solution::print_cur_stack()
{
    stack print_stk;
    stack_node* tmp = stk.top;
    while (tmp != nullptr) {
        print_stk.in_stack(tmp->p_bin_tree_address);
        tmp = tmp->p_next;
    }
    
    while (!print_stk.is_empty()) {
        bin_tree_node tmp;
        tmp = *print_stk.out_stack();
        cout << tmp.data << ' ';
    }
}

void solution::find_path_pub(int sum)
{
    find_path(bt.root, sum);
}

void solution::find_path(bin_tree_node* root, int expext_num)
{
    if (expext_num == 0) {
        print_cur_stack();
        // 小 bug ,当左侧为叶子节点时, root->left_child为空..但 传入的 expect_num 为 0
        //所以会打印一次,,然而 root->right_child 传入时..情况相同.,又会打印一次,,,日后修复..这里先用换行区分下,以便测试
        cout << endl;
    }
    
    if (root == nullptr) {
        return;
    }
    
    //节点有效,入栈,将当前节点地址保存
    stk.in_stack(root);
    //递归到左子树去寻找 expext_num
    find_path(root->left_child, expext_num - root->data);
    //递归到右子树去寻找 expext_num
    find_path(root->right_child, expext_num - root->data);
    //左右子树都找过了  当前栈顶元素 出栈   返回上一层
    stk.out_stack();
}
