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

link_list::link_list(node* p_node)
{
    head = p_node;
    tail = head;
}

//为了不破坏原来的链表..我用的是直接生成第三条链表..
void merge_order_link_list(link_list ll_1,link_list ll_2,link_list num_3)
{
    node* num_1 = ll_1.head->p_next;
    node* num_2 = ll_2.head->p_next;
    while (num_1 != nullptr && num_2 != nullptr) {
        if (num_1->data < num_2->data) {
            num_3.new_node_at_last(num_1->data);
            num_1 = num_1->p_next;
        }
        else
        {
            num_3.new_node_at_last(num_2->data);
            num_2 = num_2->p_next;
        }
    }
    
    //第二条到头 而 第一条未到..COPY
    while (num_2 == nullptr && num_1 != nullptr) {
        num_3.new_node_at_last(num_1->data);
        num_1 = num_1->p_next;
    }
    
    //第一条到头 而 第二条未到..COPY
    while (num_1 == nullptr && num_2 != nullptr) {
        num_3.new_node_at_last(num_2->data);
        num_2 = num_2->p_next;
    }
    
}


// tail 后插入节点
//尾插法
void link_list::new_node_at_last(int x)
{
    node* p_tmp = new node;
    p_tmp->data = x;
    p_tmp->p_next = nullptr;
    tail->p_next = p_tmp;
    tail = tail->p_next;
}
