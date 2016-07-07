//输入一个整数数组，
//实现一个函数来调整该数组中数字的顺序，
//使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
//并保证奇数和奇数，偶数和偶数之间的相对位置不变。

//很明显是排序的变种...考虑到相对位置不变.选择使用稳定算法  如 冒泡,归并,基数
            //我写的选择用 归并
#include <iostream>
#include "Solution.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Solution slt;
    
    cout << "将对几个数据进行奇偶重排操作?" << endl;
    int size;
    cin >> size;
    int* array = new int[size];
    int* tmp = new int[size];
    for (int i = 0 ; i < size; i++) {
        cout << "请输入第 " << i+1 << " 个数字:";
        cin >> array[i];
    }
    //开始排序
    
    slt.order_odd_even(array, size, tmp);
    
    for (int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
    delete [] tmp;
    delete [] array;
    
    return 0;
}


