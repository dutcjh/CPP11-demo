#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int val = 42; // ���ǽ����ҵ�ֵ
    // �����vec���ҵ���Ҫ��Ԫ�أ��򷵻ؽ��ָ���������򷵻ؽ��Ϊvec.cend()
    vector<int> vec = {2,3,45,44,45,12,20,22,45,42,13};
    auto ia = vec.cbegin();
    auto result = find(ia+1, ia+5, val);
    // ������
    cout << "The value " << val
        << (result == ia+5? " is not present" : " is present") << endl;
    return 0;
}
