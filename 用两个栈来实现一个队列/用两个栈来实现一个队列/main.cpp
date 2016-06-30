#include <iostream>
#include "Solution.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Solution slt;
    int key = 0;
    int value = 0;
    
    while (1) {
        cout << "Press 1: 入队列  "<< "Press 2: 出队列  "
            <<  "Press 3: 剩余全出" << endl;
        
        cin >> key;
        
        switch (key) {
            case 1:
                cout << "输入将要入栈的值: ";
                cin >> value;
                slt.in_queue(value);
                break;
            case 2:
                if (slt.out_queue(value)) {
                    cout << "此次出队列的值: " << value << endl;
                }
                else
                {
                    cout << "队列为空" << endl;
                }
                break;
            case 3:
                while (slt.out_queue(value)) {
                    cout << value << ' ';
                }
                break;
            default:
                cout << "Input Again !" << endl;
                break;
        }
    }
    return 0;
}
