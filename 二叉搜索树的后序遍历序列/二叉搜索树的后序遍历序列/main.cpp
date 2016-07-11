//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则输出Yes,否则输出No。
//假设输入的数组的任意两个数字都互不相同。
#include <iostream>
using namespace std;
bool is_squence_of_fBST(int* array, int start_flag, int end_flag);

int main(int argc, const char * argv[]) {
    cout <<"请输入待验证序列长度: " << endl;
    int array_length;
    cin >> array_length;
    cout <<"请输入待验证序列: " << endl;
    int* array = new int[array_length];
    for (int i = 0; i < array_length; i++) {
        cin >> array[i];
    }
    
    if (is_squence_of_fBST(array,0,array_length-1)) {
        cout << "该序列是一棵二叉搜索树的后序遍历的结果" << endl;
    }
    else
    {
        cout << "不是" << endl;
    }
    return 0;
}

bool is_squence_of_fBST(int* array, int start_flag, int end_flag)
{
    if (end_flag - start_flag <= 2) {
        if (array[start_flag] < array[end_flag] || start_flag > end_flag) {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        //先找到左右子树分隔区域
        bool flag = false;
        int target_flag = start_flag;
        while (array[target_flag] < array[end_flag] && start_flag < end_flag) {
            target_flag++;
        }
        //target_flag 指向的是右子树的 start_flag
        
        flag = is_squence_of_fBST(array,start_flag,target_flag-1);
        if (flag == true) {
            flag = flag = is_squence_of_fBST(array,target_flag,end_flag-1);
        }
        return flag;
    }
    
}