// 任意给定 n 个整数，求这 n 个整数序列的和、最小值、最大值
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    unsigned total_num = 0;
    vector<int> num = {};
    cout << "Please input the number of integer(n<=100): ";
    while(cin >> total_num) // 输入检查
    {
        if ((total_num > 100)||(total_num == 0))
            cout << "Error input!!!" << endl;
        else
            break;
        cout << "Please input the number of integer(n<=100): ";
    }
    // 初始化
    cout << "Please input " << total_num << " integers" << endl;
    for (int temp, i = 0; i < total_num; ++i)
    {
        cin >> temp;
        num.push_back(temp);
    }
    int sum = 0, Max = num[0], Min = num[0];
    for (auto n : num)
    {
        sum += n;
        Max = n > Max? n : Max;
        Min = n < Min? n : Min;
    }
    cout << "-------------------" << endl;
    cout << sum << " " << Min << " " << Max << " " << endl;
    return 0;
}
