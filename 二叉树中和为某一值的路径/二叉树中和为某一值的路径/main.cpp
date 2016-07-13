//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
#include <iostream>
#include "bin_tree.hpp"
#include "solution.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    solution slt;
    cout << "要查找的路径长度: ";
    int length = 0;
    cin >> length;
    slt.find_path_pub(length);
    return 0;
}
