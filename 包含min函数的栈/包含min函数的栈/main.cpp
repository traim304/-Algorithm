#include <iostream>
#include "solution.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    solution slt;
    
    cout << "           1.入栈" << endl
         << "           2.出栈" << endl
         << "           3.查看当前最小值" << endl
         << "           4.Quit" << endl
         << "请选择: " << endl;
    int key;
    
    
    while (cin >> key && key != 4) {
        switch (key) {
            case 1:
            {
                cout << "请输入入栈元素值: " << endl;
                int data;
                cin>>data;
                slt.in_stack(data);
                break;
            }
            case 2:
            {
                int data;
                if (slt.out_stack(data)) {
                    cout << "此次出栈的元素为: " << data << endl;
                }
                else
                {
                    cout << "栈为空" << endl;
                }
                
                break;
            }
            case 3:
            {
                int min;
                if (slt.get_min(min)) {
                    cout << "当前栈中的最小值为: " << min << endl;
                }
                else
                {
                    cout << "此栈为空" << endl;
                }
                break;
            }
            default:
                break;
        }
        cout << "           1.入栈" << endl
        << "           2.出栈" << endl
        << "           3.查看当前最小值" << endl
        << "           4.Quit" << endl
        << "请选择: " << endl;
    }
        return 0;
}
