#include "Solution.hpp"
#include <iostream>
using namespace std;


//方案一:右移输入数字
//      输入负数会造成死循环,因为右移补符号位
//方案二:左移 1
//      移动的次数为:   sizeof(int) * 8
//方案三:减 1
//      原理:把一个整数减去 1,再和原整数做 与 运算,会把这个数的最右边一个 1 变成 0

int Solution::number_no_1(int n)
{
    int count = 0;
    while (n) {
        n = (n-1) & n;
        count++;
    }
    return count;
}