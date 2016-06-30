//一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级。
//求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
#include <iostream>
#include "Solution.hpp"
using namespace std;

int main(int argc, const char * argv[])
{
    int floors,result;
    Solution slt;
    cout << "floors = ";
    cin >> floors;
    if (floors == 1) {
        cout << "Result = " << 1;
        return 0;
    }
    if (floors == 2) {
        cout << "Result = " << 2;
        return 0;
    }
    
    result = slt.jump_floor(floors);
    cout << "Result = " << result;
    
    return 0;
}
