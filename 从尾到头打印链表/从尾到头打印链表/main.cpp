//输入一个链表，从尾到头打印链表每个节点的值。 
#include <iostream>
#include "Solution.hpp"
using std::endl;
using std::cout;

int main(int argc, const char * argv[]) {
    Solution slt;
    slt.init();
    
    slt.printListFromTailToHead();
    cout << endl;
    
    return 0;
}
