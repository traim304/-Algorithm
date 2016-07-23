//HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
//今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
//但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
//你会不会被他忽悠住？

//时间复杂度为 O(N*logn)
#include <iostream>
using namespace std;
int find_greatest_sum_of_array(int*, int max_array);


int main(int argc, const char * argv[]) {
    //数组初始化
    cout << "数组的大小: ";
    int max_array;
    cin >> max_array;
    int* array = new int[max_array];
    cout <<"按顺序初始化数组: ";
    for (int i = 0; i < max_array; i++) {
        cin >> array[i];
    }
    
    int max_sum = find_greatest_sum_of_array(array,max_array);
    cout << "连续子序列的最大和为: " << max_sum << endl;
    
    return 0;
}

int find_greatest_sum_of_array(int* array,int max_array)
{
    int cur_max_sum = array[0];
    int cur_sum = array[0];
    
    for (int i = 1; i < max_array; i++) {
        cur_sum += array[i];
        //当前和大于之前最大和,,更新最大值
        if (cur_sum > cur_max_sum) {
            cur_max_sum = cur_sum;
        }
        //如果和变小小于当前元素值...丢弃之前的并更新为当前值
        if (cur_sum < array[i]) {
            cur_sum = array[i];
        }
    }
    
    return cur_max_sum;
}
