#include <iostream> // ����iostream��
using namespace std; // ʹ�ñ�׼�����ռ�std
class CTest // ������ CTest
{
private:  int x, y; // ����˽������
public: // ���幫�г�Ա����
    // ����������Ĺ��캯��
    CTest(int p1 = 0, int p2 = 0)  {  x = p1;  y = p2;  }
    // ���忽�����캯��
    CTest(CTest &p)  {  x = p.x;  y = p.y;  }
    // ����Show��Ա����
    void Show( )  {  cout << x << ", " << y << endl;  }
};
int main( ) // ������
{
    CTest obj1; // ����һ��CTest����obj1,ʹ��Ĭ�ϲ���0,0
    obj1.Show( );    // ���ó�Ա����Show( )
    CTest obj2(2, 5);// ����һ��CTest����obj2,ʹ�ò���2,5
    obj2.Show( );    // ���ó�Ա����Show( )
    CTest obj3(obj2);// ����һ��CTest����obj3,����obj2��ֵ2,5
    obj3.Show( );    // ���ó�Ա����Show( )
    return 0; //����������ֵ0��������������
}
