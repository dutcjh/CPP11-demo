#include<iostream>
using namespace std;

#define N 6

int main()
{
    cout << "Please enter " << N << " numbers: " << endl;
    int arr[N]{}; // 定义数组并初始化为0
    for(int i = 0; i < N; ++i)
        cin >> arr[i]; // 输入数据
    cout << endl;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0, index = 0; j < N; ++j)
        {
            index = N-i+j; // 下标计算
            if(index >= N) index -= N; // 越界减N
            cout << arr[index] << " "; // 输出数据
        }
        cout << endl;
    }
    return 0;
}
