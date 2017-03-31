#include<iostream>
using namespace std;

void swap2(int *p1, int *p2) // 交换两个数
{
    int t = *p1;
    *p1 = *p2;
    *p2 = t;
}

void sort3(int *pst) // 排序三个数
{
    if(*pst > *(pst+1)) swap2(pst, pst+1);
    if(*(pst+1) > *(pst+2)) swap2(pst+1, pst+2);
    if(*pst > *(pst+1)) swap2(pst, pst+1);
}

int main()
{
    cout << "Please enter 3 numbers: " << endl;
    int arr[3]{}; // 定义数组并初始化为0
    for(int i = 0; i < 3; ++i)
        cin >> arr[i]; // 输入数据
    sort3(arr); // 排序
    for(int i = 0; i < 3; ++i)
        cout << arr[i] << " "; // 输出排序后的数据
    cout << endl;
    return 0;
}

