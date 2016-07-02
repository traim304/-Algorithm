#include "Solution.hpp"
#include <iostream>
using namespace std;

//用 char 数组实现大数字的加法运算
//num_array[0] 为最高位
void Solution::print_1_to_max(int max)
{
    num_array = new char[max + 1];
    num_array[max] = '\0';
    int jin_wei = 0;
    m_max = max;
    
    //init num_array
    
    for (int i = 0; i < max; i++) {
        num_array[i] = '0';
    }
    
    int sum = 0;        //记录每一位的和
    bool is_over = false;       //是否到 99~99
    //模拟加法
    //是否为 99~99 的时间复杂度为 O(1)
    
    while(!is_over){
    for (int i = m_max-1; i >= 0; i--) {
        sum = num_array[i] + jin_wei - '0';     //要减去 0 的 ASCII
        
        if (i == m_max-1) {
            ++sum;
        }
        if (sum > 9) {
            if (i == 0) {
                is_over = true;
                break;
            }
            
            jin_wei = 1;
            sum %=10;
            num_array[i] = sum + '0';
            
        }
        else
        {
            num_array[i] = sum + '0';       //加回去
            jin_wei = 0;
        }
    }

       if (!is_over) {
            normal_print();
       }
}
}

void Solution::normal_print()
{
    bool is_first = true;
    for (int i = 0; i < m_max; i++) {
        if (num_array[i] == '0' && is_first) {
            continue;
        }
        else
        {
            is_first = false;
        }
        
        cout  << num_array[i];
    }
    cout << endl;
}