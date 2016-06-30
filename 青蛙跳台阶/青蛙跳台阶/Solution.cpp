#include "Solution.hpp"


int  Solution::jump_floor(int floor)
//还是 fibonacci 问题
{
    if (floor == 1) {
        return 1;
    }
    
    if (floor == 2) {
        return 2;
    }
    
    
    return jump_floor(floor - 1) + jump_floor(floor - 2);
}