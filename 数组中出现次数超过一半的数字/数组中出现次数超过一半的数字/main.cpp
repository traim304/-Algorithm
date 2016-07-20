//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
#include <iostream>
using namespace std;

//两种算法
//一种是分治的思想
//一种是利用数组特点,定义计数变量

int find_partition(int array[], int all_number);
int find_character(int array[], int all_number);
int quick_sort(int*array, int head, int tail);      //返回的是基准数字的数组下标


int main(int argc, const char * argv[]) {
    cout << "总个数为: ";
    int all_num;
    cin >> all_num;
    
    //初始化数组
    int* array = new int[all_num];
    cout << "Now,Input: ";
    for (int i = 0 ; i < all_num; i++) {
        cin >> array[i];
    }
    
    int lots_of = find_partition(array, all_num);
    
    int times = 0;
    for (int i = 0; i < all_num; i++) {
        if (array[i] == array[lots_of]) {
            times++;
        }
    }
    if (times > all_num/2) {
        cout << "超过数组长度一般的数字为: " << array[lots_of] << endl;
    }
    else
    {
        cout << "呵呵!! 并没有这个数."  << endl;
    }
    
    //调用方法二
    times = 0;
    int value = find_character(array, 5);
    for (int i = 0; i < all_num; i++) {
        if (array[i] == array[lots_of]) {
            times++;
        }
    }
    
    if (times > all_num/2) {
        cout << "超过数组长度一般的数字为: " << value << endl;
    }
    else
    {
        cout << "呵呵!! 并没有这个数."  << endl;
    }
    
    return 0;
}

//当一个数超过数组的一般,,那么他的中位数必为该数...快排一次是基准数字对号入座.
int find_partition(int array[], int all_number)
{
    int index = -1;
    while (index != all_number/2) {
        if (index < all_number/2) {
            //最大下标 all_number-1
            index = quick_sort(array,index+1,all_number-1);
        }
        else
        {
            index = quick_sort(array, 0, index-1);
        }
    }
    return index;
}

//半成品的递归..只需要将基准元素最后的下标返回即可
int quick_sort(int* array, int head, int tail)
{
    int flag = -1;
    int base = array[head];
    
    while(head != tail)
    {
        //从后往前找一个比基准小的数
        while (array[tail] >= base && head < tail) {
            tail--;
        }
        
        //交换
        int tmp = array[head];
        array[head] = array[tail];
        array[tail] = tmp;
        
        //从前往后找一个比基准大的数
        while (array[head] < base && head < tail) {
            head++;
        }
        
        //交换
        tmp = array[head];
        array[head] = array[tail];
        array[tail] = tmp;
    }
    
    flag = head;
    return flag;
}

//利用数组性质..
//                      书上原话
/*遍历一次数组,保存两个值,一个是数组中的一个数字,一个是次数,当我们遍历到下一个数字的时候,如果下一个数字和我们之前保存的数字相同,则次数加1;如果下一个数字个 我们之前保存的数字不同,则次数减1,如果次数为零,我们需要保存下一数字,并把次数设为1.由于我们要找的数字出现的数字比其他所有数字出现的次数之和还要多,那么要找的数字坑定是最后一次吧次数设为1是对应的数字*/
int find_character(int array[], int all_number)
{
    int times = 1;
    int times_of_value = array[0];
    for (int i = 1; i < all_number-1; i++) {
        if (times_of_value == array[i]) {
            times++;
        }
        else
        {
            times--;
            //当减到 0 时
            if (times == 0) {
                times_of_value = array[i];
                times = 1;
            }
        }
    }
    return times_of_value;
}