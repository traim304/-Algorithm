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
    link_list(node*);
    void traversal_and_print();
    friend void merge_order_link_list(link_list ll_1,link_list ll_2,link_list ll_3);
    void new_node_at_last(int x);
};

#endif /* link_list_hpp */
