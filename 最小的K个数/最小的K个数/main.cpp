//输入n个整数，找出其中最小的K个数。
//例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
#include <iostream>
using namespace std;

//两种方法.
//快排找出前 4 个位置....即将快排范围缩至 0~3
//定义一个数组.放最小的四个数

void find_smaller_quick(int* array,int size,int all_number);    //size 最小 N 个数,size = N
int* find_smaller_itrator(int*array,int size,int all_number,int* size_array);
int quick_sort(int* array, int head, int tail);

int main(int argc, const char * argv[]) {
    cout << "包含几个数: ";
    int all_number;
    cin >> all_number;
    cout << "求前几个数: ";
    int size;
    cin >> size;
    cout << "按顺序输入完成初始化: ";
    int *array = new int[all_number];
    
    for (int i = 0; i < all_number; i++) {
        cin >> array[i];
    }
    
//    //调用方法一函数
//    find_smaller_quick(array, size, all_number);
//    
//    for (int i = 0; i < size; i++) {
//        cout << array[i] << ' ';
//    }
    
     int* size_array = new int[size];
    find_smaller_itrator(array, size, all_number,size_array);
   
    for (int i = 0; i < size; i++) {
        cout << size_array[i] << ' ';
    }
    
    
    
    delete[] array;
    return 0;
}

void find_smaller_quick(int* array,int size,int all_number)
{
    int index = all_number-1;
    int end = all_number - 1;
    int front = 0;
    
    while (end != size-1) {
        if (index < size) {
            
            
            //当index 小于 size 则 index 前面的都已经有序了,此时直接把 index 赋值为 all_number-1;
            index = quick_sort(array,size-1,all_number-1);
            //如果仍为 all_number...则已经排好序了
            if (index == size-1) {
                break;
            }
        }
        else
        {
            index = quick_sort(array, front++, index);
            // end 往前走一步
            if(index < size)
            {
                end = index;
                continue;
            }
            index = end = index-1;
        }
    }
}



int quick_sort(int* array, int head, int tail)
{
    int base = array[head];
    while (head != tail) {
        //从后往前找小于 base 的数
        while (array[tail] > base) {
            tail--;
        }
        
        //交换
        int tmp = array[head];
        array[head] = array[tail];
        array[tail] = tmp;
        
        while (array[head] < base) {
            head++;
        }
        
        tmp = array[head];
        array[head] = array[tail];
        array[tail] = tmp;
    }
    
    return head;
}

//定义一个大小为 size 的数组.遍历一次数组,size数组存放的是最小的 n 个数
int* find_smaller_itrator(int*array,int size,int all_number,int* size_array)
{
    //先进行初始化

    for (int  i= 0; i < size; i++) {
        size_array[i] = array[i];
    }
    
    //对数组进行从小到大排序,因为 size 较小..这里直接冒泡
    for (int i = 0; i < size-1; i++) {
        for (int j =0; j < size-i-1; j++) {
            if (size_array[j] > size_array[j+1]) {
                size_array[j] = size_array[j] ^ size_array[j+1];
                size_array[j+1] = size_array[j] ^ size_array[j+1];
                size_array[j] = size_array[j] ^ size_array[j+1];
            }
        }
        
    }
    
    cout << "mao pao pai xu hou : " ;
    
    for (int i = 0; i < size; i++) {
        cout << size_array[i] << ' ';
    }
    cout << endl;
    
    for (int i = size; i < all_number; i++) {
    int tmp_size_flag = size -2;
    if (size_array[size-1] > array[i]) {
            while (tmp_size_flag >= 0 && size_array[tmp_size_flag] > array[i]) {
                size_array[tmp_size_flag+1] = size_array[tmp_size_flag];
                tmp_size_flag--;
            }
        size_array[tmp_size_flag +1] = array[i];

    }
}
    
    return nullptr;
}