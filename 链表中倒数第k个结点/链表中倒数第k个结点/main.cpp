//输入一个链表，输出该链表中倒数第k个结点。
//约定最后一个节点为倒数第一个节点
                    //双指针.简单.
#include <iostream>
#include "link_list.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    link_list llt;
    llt.traversal_and_print();
    node* p_aim = llt.find_Kth_to_tail();
    
    if (nullptr != p_aim) {
        cout << "该节点的地址:" << p_aim << "   对应的值: " << p_aim->data << endl;
    }
    
    return 0;
}
