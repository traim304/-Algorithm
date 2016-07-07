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
    node* find_Kth_to_tail();
    void traversal_and_print();
};

#endif /* link_list_hpp */
