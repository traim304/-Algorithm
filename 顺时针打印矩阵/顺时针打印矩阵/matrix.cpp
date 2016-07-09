#include "matrix.hpp"
#include <iostream>
using namespace std;

matrix::matrix()
{
    cout << "初始化数组" << endl;
    cout << "行:  ";
    int rows;
    int columns;
    cin >> rows;
    cout<< "列:  ";
    cin >> columns;
    m_rows = rows;
    m_columns = columns;
    cout << "按顺序输入数组的值: ";
    p_array = new int*[rows];
    
    for (int i = 0; i < rows; i++) {
        p_array[i] = new int[columns];
    }

    for (int i = 0; i < rows; i++) {
        int data;
        for (int j = 0; j < columns; j++) {
            cin >> data;
            p_array[i][j] = data;
        }
    }

}


void matrix::print_clockwise_matrix()
{
    int start_x = 0;
    int start_y = 0;
    int end_x = m_rows-1;
    int end_y = m_columns - 1;
    int cur_a = 0,cur_b = 0;
    
    while (m_rows > start_x * 2 && m_columns > start_y * 2) {
        //打印上行
        while (cur_b <= end_y) {
            cout << p_array[cur_a][cur_b] << ' ';
            cur_b++;
        }
        
        //打印右列
        cur_b--;
        cur_a++;
        while (cur_a <= end_x) {
            cout << p_array[cur_a][cur_b] << ' ';
            cur_a++;
        }
        
        //如果只剩一行或一列时
        //在此已经完全打印..为避免重复..应该退出
        if (end_x == start_x || end_y == start_y) {
            return;
        }
        
        //打印下行
        cur_a--;
        cur_b--;
        while (cur_b >= start_x) {
            cout << p_array[cur_a][cur_b] << ' ';
            cur_b--;
        }
        
        //打印左行
        cur_b++;
        cur_a--;
        while (cur_a > start_y) {
            cout << p_array[cur_a][cur_b] << ' ';
            cur_a--;
        }
        
        start_x++;
        start_y++;
        end_x--;
        end_y--;
        cur_a = start_x;
        cur_b = start_y;
}
}