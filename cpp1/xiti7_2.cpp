#include<iostream>
using namespace std;

#define N 6

int main()
{
    cout << "Please enter " << N << " numbers: " << endl;
    int arr[N]{}; // �������鲢��ʼ��Ϊ0
    for(int i = 0; i < N; ++i)
        cin >> arr[i]; // ��������
    cout << endl;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0, index = 0; j < N; ++j)
        {
            index = N-i+j; // �±����
            if(index >= N) index -= N; // Խ���N
            cout << arr[index] << " "; // �������
        }
        cout << endl;
    }
    return 0;
}
