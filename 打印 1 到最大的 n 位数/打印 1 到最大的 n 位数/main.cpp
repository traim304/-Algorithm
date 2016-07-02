//大数问题
//输入数字 n,按顺序打印出从 1 到最大的 n 为十进制数.
//比如输入2, 则打印1,2,3,到 999
#include <iostream>
#include "Solution.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Solution slt;
    int max_bit;
    cout << "最大的位数为: ";
    while (cin >> max_bit) {
        try {
            if (max_bit < 1) {
                throw  "Invalid Input";
            }
            
        } catch (const char *cerr) {
            cout << cerr << endl;
            cout << "Input Again:";
            continue;
        }
    
        slt.print_1_to_max(max_bit);
        break;
    }
    return 0;
}
