#include "bin_tree.hpp"
#include <iostream>
using namespace std;


bin_tree::bin_tree()
{
    int empty_end;
    cout << "请输入空位和结束符号: ";
    cin >>empty_end;
    cout << "按照先序序列构造二叉树,请输入构造顺序: ";
    int data;
    cin >> data;
    if (data != empty_end) {
        root = new bin_tree_node;
        root->data = data;
        root->left_child = creat(root->left_child,empty_end);
        root->right_child = creat(root->right_child,empty_end);
    }
    else
    {
        root = nullptr;
    }
}

bin_tree_node* bin_tree::creat(bin_tree_node *root, int& empty_end)
{
    int data;
    cin >> data;
    if (data == empty_end) {
        root = nullptr;
    }
    else
    {
        bin_tree_node* tmp = new bin_tree_node;
        root = tmp;
        tmp->data = data;
        tmp->left_child = creat(root->left_child, empty_end);
        tmp->right_child = creat(root->right_child, empty_end);
    }
    
    return root;
}

void bin_tree::pre_print(bin_tree_node *root)
{
    if (root == nullptr) {
        return;
    }
    else
    {
        cout << root->data << ' ';
        pre_print(root->left_child);
        pre_print(root->right_child);
    }
}