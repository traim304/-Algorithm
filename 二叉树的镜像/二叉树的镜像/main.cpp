//操作给定的二叉树，将其变换为源二叉树的镜像。
//              递归翻转
#include <iostream>
#include "bin_tree.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    bin_tree bt;
    bt.mirror(bt.get_root());
    bt.pre_order_print(bt.get_root());
    return 0;
}
