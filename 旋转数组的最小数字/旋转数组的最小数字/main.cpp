//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组 {3,4,5,1,2} 为 {1,2,3,4,5} 的一个旋转，该数组的最小值为 1。
//NOTE：给出的所有元素都大于 0，若数组大小为 0，请返回 0。
#include <iostream>
#include "Solution.hpp"
using std::cout;
using std::endl;
int main(int argc, const char * argv[]) {
    Solution slt;
    int save_minimum;
    //注意数组越界
    save_minimum = slt.minimum(0,slt.get_length() - 1);
    cout << "Minimum = " << save_minimum << endl;
    return 0;
}

