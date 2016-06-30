#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
struct node
{
    int m_data;
    node* p_next;
};

class Stack
{
public:
    node* p_top;
    bool push(int);
    bool pop(int&);
    Stack();
    bool is_empty();
};

//模拟实现的内容
//class queue
//{
//    node* rear;
//    node* front;
//public:
//    bool in_queue();
//    bool out_queue();
//};

class Solution
{
    Stack first,second;
public:
    bool in_queue(int data);
    bool out_queue(int& data);
};

#endif /* Solution_hpp */
