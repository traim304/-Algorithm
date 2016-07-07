//输入一个链表，反转链表后，输出链表的所有元素。
#include <iostream>
#include "link_list.hpp"

int main(int argc, const char * argv[]) {
    link_list llt;
    llt.traversal_and_print();
    llt.reverse_list();
    llt.traversal_and_print();
    return 0;
}
