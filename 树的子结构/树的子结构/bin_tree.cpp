#include "bin_tree.hpp"
#include <iostream>
using namespace std;

bin_tree::bin_tree()
{

    size = 0;
    cout << "请输入空节点的标志符: " << endl;
    char c_empty;
    cin >> c_empty;
    cout << "请输入结束的标志符: " << endl;
    char c_end;
    cin >> c_end;
    
    
    cout << "请按先序序列输入一棵二叉树:";
    char ch;
    cin >> ch;
    if (ch != c_empty && ch != c_end) {
        root = new bin_tree_node;
        root->data = ch;
        root->left_child = creat(root->left_child, c_empty,c_end);
        root->right_child =  creat(root->right_child, c_empty, c_end);
    }
}


bin_tree_node* bin_tree::creat(bin_tree_node* root, char& empty,char& end)
{
    char ch;
    cin >> ch;
    if (ch != empty && ch != end) {
        bin_tree_node* tmp = new bin_tree_node;
        tmp->data = ch;
        tmp->left_child = creat(tmp->left_child, empty,end);
        tmp->right_child =  creat(tmp->right_child, empty, end);
        return tmp;
    }
    return nullptr;
}

void bin_tree::pre_order_traversal(bin_tree_node* root)
{
    if (root == nullptr) {
        cout << " 空🌲 " << endl;
        return;
    }
    
    cout << (char)root->data << ' ';
    
    pre_order_traversal(root->left_child);
    pre_order_traversal(root->right_child);
}


void bin_tree::in_order_traversal(bin_tree_node* root)
{
    if (root == nullptr) {
        cout << " 空🌲 " << endl;
        return;
    }
    
    in_order_traversal(root->left_child);
    cout << (char)root->data << ' ';
    in_order_traversal(root->right_child);
    
}

void bin_tree::post_order_traversal(bin_tree_node * root)
{
    if (root == nullptr) {
        cout << " 空🌲 " << endl;
        return;
    }
    
    post_order_traversal(root->left_child);
    post_order_traversal(root->right_child);
    cout << (char)root->data << ' ';
}

bin_tree_node* bin_tree::get_root()
{
    return root;
}
