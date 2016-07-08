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
    int size;
public:
    bin_tree();
    bin_tree_node* get_root();
    bin_tree_node* creat(bin_tree_node* r, char& empty,char& end);
    //遍历
    void pre_order_traversal(bin_tree_node*);
    void in_order_traversal(bin_tree_node*);
    void post_order_traversal(bin_tree_node*);
    
    friend bool is_b_in_a(bin_tree& a, bin_tree& b);
    bin_tree_node* locate_by_value(char root_data);
};


bool is_b_in_a(bin_tree& a, bin_tree& b);


#endif /* bin_tree_hpp */
