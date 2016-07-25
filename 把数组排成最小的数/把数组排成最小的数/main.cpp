//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
#include <iostream>
#include <string>
using namespace std;

//自定义一个比较大小的算法.
//当 ab < ba 时,返回 1
bool is_large(string a, string b)
{
    string ab = a + b;
    string ba = b + a;
    if (ab > ba) {
        return true;
    }
    else
    {
        return false;
    }
}

void str_array_sort(string* array, int length)
{
    for (int i = 0 ; i < length-1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (is_large(array[j], array[j+1])) {
                string tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int length = 0;
    cout << "输入数组的长度: " << endl;
    cin >> length;
    
    string *array = new string[length];
    for (int i = 0; i < length; i++) {
        cout << "第 " << i+1 << "个数: ";
        cin >> array[i];
    }
    
    str_array_sort(array, length);
    
    for (int i =0 ; i < length; i++) {
        cout << array[i];
    }
    return 0;
}
