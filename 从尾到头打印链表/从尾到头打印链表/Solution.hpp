#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>

struct node {
    int data;
    node* p_next;
};

class Solution
{
public:
    node* p_head;
    node* p_tail;
    void init();
    void show();
    void printListFromTailToHead();
};


class Stack
{
    node* p_top;
public:
    Stack();
    bool push(int);
    bool pop();
};
#endif /* Solution_hpp */
