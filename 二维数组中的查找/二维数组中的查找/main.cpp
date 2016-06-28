//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include "Solution.hpp"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution slt;
    slt.init();
    slt.print_array();
    
    if (slt.locate_value()) {
        cout << "存在";
    }
    else
    {
        cout << "不存在";
    }
    return 0;
}
