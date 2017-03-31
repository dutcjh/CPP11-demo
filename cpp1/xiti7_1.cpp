#include<iostream>
using namespace std;

#define N 10 // 数组长度

void sel_sort(double *pst, double *pnd);

int main()
{
    cout << "Please enter " << N << " numbers: " << endl;
    double arr[N]{}; // 定义数组并初始化为0
    for(int i = 0; i < N; ++i)
        cin >> arr[i]; // 输入数据
    sel_sort(arr, arr+N); // 排序
    for(int i = 0; i < N; ++i)
        cout << arr[i] << " "; // 输出排序后的数据
    cout << endl;
    return 0;
}

void sel_sort(double *pst, double *pnd) // 选择排序法
{
    for(double *pi = pst; pi != (pnd-1); ++pi)
    {
        double *temp = pi; // 存储最小值
        for(double *pj = (pi+1); pj != pnd; ++pj)
        {
            if(*pj < *temp) // 找出剩余数据的最小值
                temp = pj;
        }
        if(temp != pi) // 如果*pi不是最小值，则交换
        {
            double min = *temp;
            *temp = *pi;
            *pi = min;
        }
    }
}
