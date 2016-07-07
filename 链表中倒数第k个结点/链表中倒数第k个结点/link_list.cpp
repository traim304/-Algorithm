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


node* link_list::find_Kth_to_tail()
{
    
    //处理错误的输入
    cin.clear();
    while (cin.get() != '\n') {
           continue;
    }
    
    
    
    cout << "欲寻找倒数第几个节点? " << endl;
    int k;
    cin >> k;
    
    if (k > head->data) {
        cout << "K Too Large" << endl;
        return nullptr;
    }
    
    node* before = head->p_next;
    node* after = head->p_next;
    //让 after 先走 k 步
    for (int i = 0; i < k; i++) {
        after = after->p_next;
    }
    
    //两个指针同时前进
    
    while (nullptr != after) {
        after = after->p_next;
        before = before->p_next;
    }
    return before;
    
}