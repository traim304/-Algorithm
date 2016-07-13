#include "stack.hpp"

stack::stack()
{
    top = nullptr;
}

void stack::in_stack(bin_tree_node* data)
{
    if (data == nullptr) {
        return;
    }
    stack_node* tmp = new stack_node;
    tmp->p_bin_tree_address = data;
    tmp->p_next = nullptr;
    
    if (top == nullptr) {
        top = tmp;
    }
    else
    {
        tmp->p_next = top;
        top = tmp;
    }
}

bin_tree_node* stack::out_stack()
{
    if (top == nullptr) {
        return nullptr;
    }
    else
    {
        stack_node* tmp = top;
        top = top->p_next;
        
        return tmp->p_bin_tree_address;
    }
}


bool stack::is_empty()
{
    if (top == nullptr) {
        return true;
    }
    else
    {
        return false;
    }
}