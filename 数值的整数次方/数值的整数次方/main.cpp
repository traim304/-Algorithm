//不考虑大数问题
//给定一个 double 类型的浮点数 base 和 int 类型的整数 exponent。
//求 base 的 exponent 次方。
#include <iostream>
#include "Solution.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Solution slt;
    double base;
    int exponent;
    cout << "Double Base = ";
    cin >> base;
    cout << "int exponent = ";
    cin >> exponent;
    cout << "The result = " << slt.power(base, exponent) << endl;
    return 0;
}
