#include<iostream>
using namespace std;

#define N 10 // ���鳤��

void sel_sort(double *pst, double *pnd);

int main()
{
    cout << "Please enter " << N << " numbers: " << endl;
    double arr[N]{}; // �������鲢��ʼ��Ϊ0
    for(int i = 0; i < N; ++i)
        cin >> arr[i]; // ��������
    sel_sort(arr, arr+N); // ����
    for(int i = 0; i < N; ++i)
        cout << arr[i] << " "; // �������������
    cout << endl;
    return 0;
}

void sel_sort(double *pst, double *pnd) // ѡ������
{
    for(double *pi = pst; pi != (pnd-1); ++pi)
    {
        double *temp = pi; // �洢��Сֵ
        for(double *pj = (pi+1); pj != pnd; ++pj)
        {
            if(*pj < *temp) // �ҳ�ʣ�����ݵ���Сֵ
                temp = pj;
        }
        if(temp != pi) // ���*pi������Сֵ���򽻻�
        {
            double min = *temp;
            *temp = *pi;
            *pi = min;
        }
    }
}
