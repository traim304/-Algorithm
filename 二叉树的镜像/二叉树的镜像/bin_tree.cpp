#include "bin_tree.hpp"
#include <iostream>
using namespace std;

bin_tree::bin_tree()
{
    root = nullptr;
    int c_empty,end;
    cout << "请输入空节点标志 和 结束节点标志 (int) : ";
    cin >> c_empty;
    end = c_empty;
    
    cout << "请按先序遍历顺序,输入二叉树: ";
    
    int data;
    cin >> data;
    
    if (data != c_empty && data != end) {
        root = new bin_tree_node;
        root->data = data;
        root->left_child = creat(root->left_child, c_empty, end);
        root->right_child = creat(root->right_child, c_empty, end);
    }
}

bin_tree_node* bin_tree::creat(bin_tree_node *root, char empty, char end){
    int tmp_data;
    cin >> tmp_data;
    if (tmp_data != empty && tmp_data != end) {
        bin_tree_node* tmp = new bin_tree_node;
        tmp->data = tmp_data;
        tmp->left_child = creat(tmp->left_child, empty, end);
        tmp->right_child = creat(tmp->right_child, empty, end);
        return tmp;
    }
    return nullptr;
}

void bin_tree::pre_order_print(bin_tree_node *root)
{
    if (root != nullptr) {
        cout << root->data << ' ';
        pre_order_print(root->left_child);
        pre_order_print(root->right_child);
    }
}

bin_tree_node* bin_tree::get_root()
{
    return root;
}



void bin_tree::mirror(bin_tree_node* root)
{
    if (root != nullptr) {
        bin_tree_node* tmp = root->left_child;
        root->left_child = root->right_child;
        root->right_child = tmp;
        
        mirror(root->left_child);
        mirror(root->right_child);
    }
}