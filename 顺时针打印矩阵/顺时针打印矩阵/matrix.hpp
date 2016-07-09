#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>

class matrix
{
    int** p_array;
    int m_rows;
    int m_columns;
public:
    matrix();
    void print_clockwise_matrix();
    void print_matrix();
};


#endif /* matrix_hpp */
