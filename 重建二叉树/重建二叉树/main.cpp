//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列 {1,2,4,7,3,5,6,8} 和中序遍历序列 {4,7,2,1,5,3,8,6}，则重建二叉树并返回。
#include <iostream>
#include "Solution.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    int length = 0;
    cout << "共有多少节点?  ";
    cin >> length;
    Solution slt;
    slt.init(length);
    node* builded = slt.re_build_tree(0,length-1,0,length-1);
    slt.print_tree(builded);
    return 0;
}
