//输入一个整数，输出该数二进制表示中 1 的个数。其中负数用补码表示。
#include <iostream>
#include "Solution.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Solution slt;
    int n;
    cout << "输入 n 的值: ";
    cin >> n;
    cout << slt.number_no_1(n);
    return 0;
}
