#include<iostream>
using namespace std;

void swap2(int *p1, int *p2) // ����������
{
    int t = *p1;
    *p1 = *p2;
    *p2 = t;
}

void sort3(int *pst) // ����������
{
    if(*pst > *(pst+1)) swap2(pst, pst+1);
    if(*(pst+1) > *(pst+2)) swap2(pst+1, pst+2);
    if(*pst > *(pst+1)) swap2(pst, pst+1);
}

int main()
{
    cout << "Please enter 3 numbers: " << endl;
    int arr[3]{}; // �������鲢��ʼ��Ϊ0
    for(int i = 0; i < 3; ++i)
        cin >> arr[i]; // ��������
    sort3(arr); // ����
    for(int i = 0; i < 3; ++i)
        cout << arr[i] << " "; // �������������
    cout << endl;
    return 0;
}

