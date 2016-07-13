#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include "bin_tree.hpp"

struct stack_node {
    bin_tree_node* p_bin_tree_address;
    stack_node* p_next;
};

class stack
{
public:
    stack_node* top;
    stack();
    void in_stack(bin_tree_node* data);
    bin_tree_node* out_stack();
    bool is_empty();
};
#endif /* stack_hpp */
