//从上往下打印出二叉树的每个节点，同层节点从左至右打印。de
#include <iostream>
#include "solution.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    solution slt;
    slt.print_from_top_to_bottom(slt.get_root());
    return 0;
}
