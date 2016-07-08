#include "bin_tree.hpp"
#include <iostream>
#include "queue.hpp"
using namespace std;

bin_tree::bin_tree()
{

    size = 0;
//    cout << "请输入空节点的标志符: " << endl;
    char c_empty = '^';
//    cin >> c_empty;
//    cout << "请输入结束的标志符: " << endl;
   char c_end = '#';
//    cin >> c_end;
    
    cout << "默认用 ^ 代表空格标志符, 用 # 代表结束符号" << endl;
    
    
    //先生成树的 root 节点再递归创建左右子树
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

//主要函数
bool is_clone(bin_tree_node *a, bin_tree_node *b)
{
    bool flag = false;
    
    //一方到头..而另一方未到
    if (a == nullptr && b != nullptr) {
        return false;
    }
    if (b == nullptr && a != nullptr) {
        return false;
    }
    //同时为空
    if (a == nullptr && b == nullptr) {
        return true;
    }
    if (a->data != b->data) {
        return false;
    }
    
    
    flag = is_clone(a->left_child, b->left_child);
    
    if (flag == true) {
        flag = is_clone(b->right_child, b->right_child);
    }
    
    if (flag == true) {
        return true;
    }
    
    return flag;
    
}

bool is_b_in_a(bin_tree& a, bin_tree& b)
{
    queue qee;
    bin_tree_node* p_a = a.get_root();
    bin_tree_node* p_b = b.get_root();
    
    if (p_a != nullptr) {
        qee.in_queue(&p_a);
    }
    while (qee.tail != nullptr && qee.front != nullptr) {
        bin_tree_node* p_bin_tmp = qee.out_queue();
        //先验证队头元素是否为 B 的 root->data
        
        if (p_bin_tmp->data == p_b->data) {
            //看是否完全相同
            if (is_clone(p_b, p_bin_tmp)) {
                return true;
            }
        }
        
        
        qee.in_queue(&p_bin_tmp->left_child);
        qee.in_queue(&p_bin_tmp->right_child);
        
    }
    return false;
}


//aab^^cd^^e^^e^^#
//ff^^d^^#
//^#AB^^C^^#