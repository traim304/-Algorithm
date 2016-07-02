#include "Solution.hpp"

//                                  方案一
//最直观,但效率不好
//
//int Solution::fibonacci(int x)
//{
//    if (x == 0) {
//        return 0;
//    }
//    else if (x == 1)
//    {
//        return 1;
//    }
//    
//    return fibonacci(x - 1) + fibonacci(x - 2);
//}


//                                  方案二
//把递归算法用循环方法实现

int Solution::fibonacci(int x)
{
    int result = 0;
    if (x == 0) {
        result = 0;
    }
    
    if (x == 1) {
        result = 1;
    }
    int previous = 1;
    int pre_two = 0;
    for (int i = 2; i <= x; i++) {
        result = previous + pre_two;
        pre_two = previous;
        previous = result;
    }
    
    return result;
}