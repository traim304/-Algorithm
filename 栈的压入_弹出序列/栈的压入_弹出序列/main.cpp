//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。
//例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
//但4,3,5,1,2就不可能是该压栈序列的弹出序列。
//（注意：这两个序列的长度是相等的）
#include <iostream>
#include "solution.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    solution slt;
    int* in_stack_seq,n;
    int* wait_prove;
    cout << "元素个数: " << endl;
    cin >> n;
    if (n < 1) {
        return -1;
    }
    
    in_stack_seq = new int[n];
    
    cout << "请输入入栈序列: ";
    for (int i = 0 ; i < n; i++) {
        cin >> in_stack_seq[i];
    }
    
    cout << "请输入待验证的出栈序列: ";
    for (int i = 0 ; i < n; i++) {
        cin >> wait_prove[i];
    }
    
    if (slt.is_pop_order(in_stack_seq, wait_prove,n)) {
        cout << "符合出入栈顺序";
    }
    else
    {
         cout << "ERROR";
    }
    cout << endl;
    
    return 0;
}
