//我们可以用 2*1 的小矩形横着或者竖着去覆盖更大的矩形。
//请问用 n 个 2*1 的小矩形无重叠地覆盖一个 2*n 的大矩形，总共有多少种方法？


#include "Solution.hpp"

int Solution::rectCover(int n)
{
    if (n == 1) {
        return 1;
    }
    
    if (n == 2) {
        return 2;
    }
    
    return rectCover(n - 1) + rectCover(n - 2);
}