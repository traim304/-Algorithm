//输入两颗二叉树A，B，判断B是不是A的子结构。
#include <iostream>
#include "bin_tree.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "初始化树 A: " << endl;
    bin_tree a;
    
    cin.clear();
    while (cin.get() != '\n') {
        continue;
    }
    cout << "初始化树 B: " << endl;
    bin_tree b;
    
    cin.clear();
    while (cin.get() != '\n') {
        continue;
    }
    
    
    //核心函数 is_b_in_a()
    if (is_b_in_a(a, b)) {
        cout << " 树 B 是 树 A 的子结构 " << endl;
    }
    else
    {
        cout << " 树 B 不是 树 A 的子结构 " << endl;
    }
    
    return 0;
}