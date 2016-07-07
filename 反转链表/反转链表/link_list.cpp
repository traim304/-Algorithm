#include "link_list.hpp"
#include <iostream>
using namespace std;

link_list::link_list()
{
    int p_tmp_save_data = 0;
    node* p_tmp = nullptr;
    //创建头结点
    head = new node;
    tail = head;
    head->data = 0;
    head->p_next = nullptr;
    
    //先进行输入判断
    cout << "请输入第 " << head->data +1 << " 个元素< #为结束符 >: ";
    while (cin >> p_tmp_save_data && p_tmp_save_data != (int)'#') {
        //放到临时节点中,并赋值
        p_tmp = new node;
        p_tmp->data = p_tmp_save_data;
        p_tmp->p_next = nullptr;
        //挂到尾部
        tail->p_next = p_tmp;
        //更新节点总数
        head->data = head->data +1;
        //尾指针后移
        tail = p_tmp;
        
        p_tmp = nullptr;
        cout << "请输入第 " << head->data +1 << " 个元素< #为结束符 >: ";
    }
}

void link_list::traversal_and_print()
{
    cout << "该链表为: ";
    node* p_tmp = head->p_next;
    while (nullptr != p_tmp) {
        cout << p_tmp->data << ' ';
        // tmp 后移
        p_tmp = p_tmp->p_next;
    }
    cout << endl;
}


//进行翻转操作前 before 指向前一节点..
void link_list::reverse_list()
{
    
    node* before = head->p_next;
    //处理链表没有节点的情况,,翻转后仍为该链表
    if (before == nullptr) {
        return;
    }
    node* cur = before->p_next;
    //处理链表只有一个节点的情况,,翻转后仍为该链表..可与没有节点情况合并
    if (cur == nullptr) {
        return;
    }
    //处理链表只有两个节点的情况,进行一次翻转
    node* after =  cur->p_next;
    if (after == nullptr) {
        cur->p_next = before;
        before->p_next = nullptr;
        head->p_next = cur;
        return;
    }
    
    //  又是个坑...这里的 before->p_next 要置于空,否则就成环了;
    //  before 指向的是翻转后的尾节点
    before->p_next = nullptr;
    
    
    while (after != nullptr) {
        cur->p_next = before;
        before = cur;
        cur = after;
        after = after->p_next;
    }
    
    //此时 after 为 nullptr, cur 指向的是最后一个节点.
    cur->p_next = before;
    head->p_next = cur;
    return;
}







