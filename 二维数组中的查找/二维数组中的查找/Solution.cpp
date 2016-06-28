#include "Solution.hpp"
#include <iostream>
using namespace std;

bool Solution::locate_value()
//在 a 二维数组中找 x
{
    int x;
    cout << "输入要查找的数: ";
    cin >> x;
    bool flag = false;
    //每次和最右上角比较,缩小范围
    
    //tmp_lie 这里要减 1
    int tmp_hang = 0,tmp_lie = m_lie-1;
    
    
    //核心代码块
    //每次和最右上角比较,缩小范围
    //当 tmp 的行列号有一个比 0 小则找不到
    while (array[tmp_hang][tmp_lie] != x && tmp_hang >= 0 && tmp_lie >= 0)
        //循环条件里的 tmp 行号和列号是可以等于 0 的
    {
        if (array[tmp_hang][tmp_lie] > x) {
            --tmp_lie;
        }
        else
        {
            tmp_hang++;
        }
        
    }
    
    if (array[tmp_hang][tmp_lie] == x) {
        flag = true;
    }
    
    return flag;
}




void Solution::init()
{
    int hang,lie;
    cout << "输入矩阵大小:" << endl;
    cout << "   行: ";
    cin >> hang;
    cout << "   列: ";
    cin >> lie;
    m_hang = hang;
    m_lie = lie;
    
    cout << "依次输入二维数组中的值: " ;
    
    //二维数组的创建和操作
    array = new int*[hang];
    
    for (int i = 0; i < hang; i++) {
        array[i] = new int(lie);
    }
    
    for (int i = 0; i < hang ; i++) {
        for (int j = 0; j < lie; j++) {
            cin >> array[i][j];
        }
    }
}

void Solution::print_array()
{
    for (int i = 0; i < m_hang ; i++) {
        for (int j = 0; j < m_lie; j++) {
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }

}