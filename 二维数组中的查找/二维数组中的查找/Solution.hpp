#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>

class Solution
{
    int **array;
    int m_hang;
    int m_lie;
public:
    bool locate_value();
    void init();
    void print_array();
};

#endif /* Solution_hpp */
