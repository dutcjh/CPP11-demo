// 10.1 ����
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int val = 42; // ���ǽ����ҵ�ֵ
    // �����vec���ҵ���Ҫ��Ԫ�أ��򷵻ؽ��ָ���������򷵻ؽ��Ϊvec.cend()
    vector<int> vec = {2,3,45,44,42,12,20,22,45,42,13};
    auto result = find(vec.cbegin(), vec.cend(), val);
    // ������
    cout << "The value " << val
        << (result == vec.cend()? " is not present" : " is present") << endl;
    return 0;
}
