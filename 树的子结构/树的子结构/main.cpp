//输入两颗二叉树A，B，判断B是不是A的子结构。
#include <iostream>
#include "bin_tree.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    bin_tree bt;
    cout << "前序遍历: ";
    bt.pre_order_traversal(bt.get_root());
    cout << "中序遍历: ";
    bt.in_order_traversal(bt.get_root());
    cout << "中序遍历: ";
    bt.post_order_traversal(bt.get_root());
    return 0;
}
