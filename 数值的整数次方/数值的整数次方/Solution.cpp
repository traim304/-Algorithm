#include "Solution.hpp"

//                      方案一
//  注意输入检查
//判断 double 相等只能用精度..(-0.0000001, 0.0000001)
bool Solution::is_equal(double a, double b)
{
    if (a - b < 0.0000001 && a - b > -0.0000001) {
        return true;
    }
    return false;
}

//double Solution::power(double base, int exponent)
//{
//    bool negative_flag = false;
//    double result = 1.0;
//    
//    
//    // 0 的 0 次在数学上没有意思,无论返回什么都可
//    if (is_equal(base, 0.0) && base == 0) {
//        return 0;
//    }
//    if (is_equal(base, 0.0)) {
//        return 1;
//    }
//    
//    if (exponent < 0) {
//        negative_flag = true;
//        exponent = -exponent;
//    }
//    
//    
//    for (int i = 1;  i <= exponent ; i++) {
//        result = result * base;
//    }
//    
//    if (negative_flag) {
//        result = 1.0 / result;
//    }
//    
//    return result;
//}









//                          方案二
//                  a^(n/2) * a^(n/2)       n 为偶数
//乘方公式 a^(n) =
//                  a^((n-1) / 2) * a^((n-1) / 2) * a     n 为奇数



double Solution::power(double base, int exponent)
{
    
    //错误判断
    int negative_flag = false;
    if (exponent < 0) {
        negative_flag = true;
        exponent = exponent * -1;
    }
    
    
    double result = 1.0;
    if (is_equal(exponent, 0.0)) {
        return 1;
    }
    if (exponent == 1.0) {
        return base;
    }
    
    //判断一个数是否为奇数,可以用这个数与 1, 当结果为1,为奇数
    //value & 1 is true when value is odd {1, 3, 5, 7, 9, 11, 13, 15}.
    
    //一个数除以 2,可以用 >>1(右移一位) 代替...提高效率
    
    result = power(base, exponent >> 1);
    result *= result;
    if (exponent & 1) {
        result *= base;
    }
    
    if (negative_flag) {
        result = 1.0 / result;
    }
    return result;
}
