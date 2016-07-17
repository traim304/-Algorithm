//输入一个字符串,按字典序打印出该字符串中字符的所有排列。
//例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab
//和cba。 结果请按字母顺序输出。


//递归交换..字符看成两部分,第一个字符和后面的字符
//      注意操作的数组不应该是共用的
#include <iostream>
#include <cstring>
using namespace std;
void print_all_situation(char* array,int cur,int end);
void swap(char* array, int,int);

int main()
{
    char* array = new char[100];
    cout << "输入一个字符串: " << endl;
    cin.getline(array, 100);
    cout << endl;
    print_all_situation(array,0,(int)strlen(array)-1);
    return 0;
}

void print_all_situation(char* array,int cur, int end)
{
    char* tmp = new char[strlen(array)];
    strcpy(tmp, array);
    if (cur == end) {
        cout << array << endl;
        return;
    }

    for (int i = cur; i <= end; i++) {
        swap(tmp,cur,i);
        //cur+1 和 cur++ 还是不一样滴
        print_all_situation(tmp,cur+1,end);
    }
}

void swap(char* array, int x, int y)
{
    char ch = array[x];
    array[x] = array[y];
    array[y] = ch;
}