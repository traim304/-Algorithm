//我们可以用 2*1 的小矩形横着或者竖着去覆盖更大的矩形。
//请问用 n 个 2*1 的小矩形无重叠地覆盖一个 2*n 的大矩形，总共有多少种方法？
#include <iostream>
#include "Solution.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Solution slt;
    int n;
    cout << "请输入 n 的数量: ";
    cin >> n;
    int ways = slt.rectCover(n);
    cout << "有" << ways << "种方案" << endl;
    return 0;
}
