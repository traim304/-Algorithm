#ifndef link_list_hpp
#define link_list_hpp

#include <stdio.h>

struct node {
    int data;
    node* p_next;
};

class link_list
{
    // head->data 存放的是 length
    node* head;
    node* tail;
public:
    link_list();
    void traversal_and_print();
    void reverse_list();
};

#endif /* link_list_hpp */
