//请实现一个函数，
//将一个字符串中的空格替换成 “%20”。
//例如，当字符串为 We Are Happy. 则经过替换之后的字符串为 We%20Are%20Happy。
#include "Solution.hpp"
#include <cstring>
#include <iostream>
using namespace std;


void Solution::replace_space(char *str)
{
    int length = (int)strlen(str);
    int space = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            ++space;
            ++i;
            continue;
        }
        ++i;
    }
    char *p_array = new char[length + space * 2];
    p_array[length + space * 2 - 1] = '\0';
    int str_rear = length;
    int p_rear = length + space * 2;
    
    while (str_rear+1) {
        if (str[str_rear] == ' ') {
            p_array[p_rear--] = '0';
            p_array[p_rear--] = '2';
            p_array[p_rear--] = '%';
            str_rear--;
        }
        else
        {
            p_array[p_rear] = str[str_rear];
            str_rear--;
            p_rear--;
        }
    }
    
    //show
    cout << endl << p_array << endl;
}

