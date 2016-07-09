#ifndef bin_tree_hpp
#define bin_tree_hpp

#include <stdio.h>

struct bin_tree_node {
    int data;
    bin_tree_node* left_child;
    bin_tree_node* right_child;
};


class bin_tree
{
    bin_tree_node* root;
public:
    bin_tree();
    bin_tree_node* creat(bin_tree_node* root,char empty, char end);
    void pre_order_print(bin_tree_node* root);
    bin_tree_node* get_root();
    void mirror(bin_tree_node* root);
};

#endif /* bin_tree_hpp */
