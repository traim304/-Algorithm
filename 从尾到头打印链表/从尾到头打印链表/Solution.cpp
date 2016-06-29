#include "Solution.hpp"
#include <cstring>
#include <iostream>
using namespace std;

void Solution::printListFromTailToHead()
{
    Stack sk;
    node* tmp;
    tmp = p_head;
    while (nullptr != tmp) {
        sk.push(tmp->data);
        tmp = tmp->p_next;
    }
    
    while (sk.pop()) {
        cout << ' ';
    }
}

Stack::Stack()
{
    p_top = nullptr;
}

void Solution::init()
{
    p_head = new node;
    p_tail = p_head;
    int input_value;
    cout << "依次输入链表中的值<'0'结束>: ";
    cin >> input_value;
    
    while (input_value != 0) {
        //创建待加入的节点并初始化
        node* tmp = new node;
        tmp->data = input_value;
        tmp->p_next = nullptr;
        //p_tail后移
        p_tail->p_next = tmp;
        p_tail = tmp;
        cin >> input_value;
    }
    
}

bool Stack::pop()
{
    if (p_top->p_next == nullptr) {
        return false;
    }
    cout << p_top->data;
    node* tmp;
    tmp = p_top;
    p_top = p_top->p_next;
    delete tmp;
    return true;
}

bool Stack::push(int pa_data)
{
    node* tmp = new node;
    tmp->data = pa_data;
    tmp->p_next = p_top;
    p_top = tmp;
    
    return true;
}



void Solution::show()
{
    node* tmp = p_head->p_next;
    while (nullptr != tmp) {
        cout << tmp->data << ' ';
        tmp = tmp->p_next;
    }
}