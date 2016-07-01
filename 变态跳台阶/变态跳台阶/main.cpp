//一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级…… 它也可以跳上 n 级。
//求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
#include <iostream>
#include "Solution.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Solution slt;
    int floors;
    cout << "floors = ";
    cin >> floors;
    floors = slt.jump_floor(floors);
    cout << "有 " << floors << " 种方式 " << endl;
    return 0;
}
