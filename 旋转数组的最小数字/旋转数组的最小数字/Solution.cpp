#include "Solution.hpp"
#include <iostream>
using namespace std;

Solution::Solution()
{
    cout << "数组长度为: ";
    cin >> m_length;
    cout << "依次输入旋转数组的值: ";
    array = new int[m_length];
    
    for (int i = 0; i < m_length; i++) {
        cin >> array[i];
    }
    
}

int Solution::minimum(int min_flag, int max_flag)
{
    int return_minimum = -1;
    int mid_flag = (min_flag + max_flag) / 2;
    
    //最后一个递归时, mid_flag 和 min_flag 会在同一个位置, max_flag 会在后一个位置
    //最小值要么在该位置,要么在 max_flag ,
    if (min_flag == mid_flag) {
        array[min_flag] < array[max_flag] ?
        return_minimum = array[min_flag] :
        return_minimum =  array[max_flag];
    }
    
    if (array[min_flag] < array[mid_flag]
        && array[mid_flag] < array[max_flag])
    {
        return_minimum = minimum(min_flag, mid_flag);
    }
    else if(array[min_flag] < array[mid_flag]
            && array[mid_flag] > array[max_flag])
    {
        return_minimum = minimum(mid_flag, max_flag);
    }
    else if (array[min_flag] > array[mid_flag]
             && array[mid_flag] < array[max_flag])
    {
        return_minimum = minimum(min_flag, mid_flag);
    }
    
    return return_minimum;
}

int Solution::get_length()
{
    return m_length;
}