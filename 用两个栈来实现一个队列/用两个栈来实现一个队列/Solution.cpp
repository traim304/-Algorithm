#include "Solution.hpp"
#include <iostream>
using std::cout;
using std::endl;

bool Solution::in_queue(int data)
{
    first.push(data);
    return true;
}

bool Solution::out_queue(int& data)
{
    //栈 2 为空时,栈 1 全部出来,进入栈 2
    if (second.is_empty()) {
        while (!first.is_empty()) {
            first.pop(data);
            second.push(data);
        }
    }
    
    if (second.is_empty() && first.is_empty()) {
        return false;
    }
    
    second.pop(data);
    return true;
}

Stack::Stack()
{
    p_top = nullptr;
}

bool Stack::is_empty()
{
    //空 1 不空 0
    return !p_top;
}


bool Stack::push(int data)
{
    node* p_tmp = new node;
    if (!p_tmp) {
        return false;
    }
    p_tmp->m_data = data;
    p_tmp->p_next = p_top;
    
    p_top = p_tmp;
    return true;
}

bool Stack::pop(int& tmp_save_data)
{
    if (!p_top) {
        return false;
    }
    node* p_tmp = p_top;
    p_top = p_top->p_next;
    tmp_save_data = p_tmp->m_data;
    delete p_tmp;
    return true;
}