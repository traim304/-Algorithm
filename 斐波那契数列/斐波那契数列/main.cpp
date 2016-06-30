//斐波纳契数列（Fibonacci Sequence），又称黄金分割数列。
//在数学上，斐波纳契数列以如下被以递归的方法定义：
//F(0)=0，
//F(1)=1，
//F(n)=F(n-1)+F(n-2)
#include <iostream>
#include "Solution.hpp"
using std::cout;
using std::endl;
using std::cin;

int main(int argc, const char * argv[]) {
    Solution slt;
    int x,result;
    cout << "请输入 n 的值: ";
    cin >> x;
    result = slt.fibonacci(x);
    cout << "Result = " << result << endl;
    return 0;
}