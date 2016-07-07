//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
#include <iostream>
#include "link_list.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    link_list ll_1;
    ll_1.traversal_and_print();
    
    cin.clear();
    while (cin.get() != '\n') {
        continue;
    }
    
    link_list ll_2;
    ll_2.traversal_and_print();
    
    
    //生成只含一个头结点的链表
    
    node* num_3_head = new node;
    num_3_head->data = 0;
    num_3_head->p_next = nullptr;
    link_list num_3(num_3_head);
    //作为第三条链表..传递给 合并 函数
    merge_order_link_list(ll_1,ll_2,num_3);
    
    num_3.traversal_and_print();
    return 0;
}
