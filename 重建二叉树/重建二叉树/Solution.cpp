#include "Solution.hpp"
#include <iostream>
using namespace std;

//后序遍历,用于验证结果
void Solution::print_tree(node * root)
{
    if (nullptr == root) {
        return;
    }
    
    print_tree(root->left_node);
    print_tree(root->right_node);
    cout << root->data;
    cout << ' ';
}

void Solution::init(int length)
{
    m_length = length;
    pre_order = new int[length];
    in_order = new int[length];
    cout << "依次输入前序遍历的值: ";
    for (int i = 0; i < length; i++) {
        cin >> pre_order[i];
    }
    
    cout << "依次输入中序遍历的值: ";
    for (int i = 0; i < length; i++) {
        cin >> in_order[i];
    }
}

node*  Solution::re_build_tree(int start_pre_order, int end_pre_order,
                   int start_in_order, int end_in_order)
{
    node* root = new node;
    root->data = pre_order[start_pre_order];
    root->left_node = nullptr;
    root->right_node = nullptr;
    
    //结束递归
    if (start_pre_order == end_pre_order) {
        if (pre_order[start_pre_order] == in_order[start_in_order]) {
            return root;
        }
        else
        {
            cout << "Input Error !!" <<endl;
            exit(88);
        }
        
    }
    //找到root在中序序列中的位置
    int root_in_order = start_in_order;
    while (root_in_order <= end_in_order && pre_order[start_pre_order] != in_order[root_in_order]) {
        ++root_in_order;
    }
    //求出左子树所具有的节点数
    int left_tree = root_in_order - start_in_order;
    //生成左子树
    if (left_tree > 0)
    {
        root->left_node = re_build_tree(start_pre_order + 1,
                      start_pre_order + left_tree,
                      start_in_order,
                      root_in_order -1);
    }
    //生成右子树
    if (end_in_order - root_in_order > 0)
    {
        root->right_node = re_build_tree(start_pre_order + left_tree + 1,
                      end_pre_order,
                      root_in_order + 1,
                      end_in_order);
    }
    return root;
    
}