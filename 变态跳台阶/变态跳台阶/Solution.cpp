#include "Solution.hpp"






//当 n > 3时,可以分解为先跳一步.然后跳 jump_floor(n-1) ,已知.
//和先跳 jump_floor(n-1)再跳最后一格
int Solution::jump_floor(int x)
{
    if (x == 1) {
        return 1;
    }
    if (x == 2) {
        return 2;
    }
    
    
    return 2 * jump_floor(x-1);
}