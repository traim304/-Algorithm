#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>

class Solution
{
    int *array;
    int m_length;
public:
    Solution();
    int minimum(int min_flag,int max_flag);
    int get_length();
};

#endif /* Solution_hpp */
