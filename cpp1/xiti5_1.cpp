#include <iostream> // 包含iostream库
using namespace std; // 使用标准命名空间std
class CTest // 定义类 CTest
{
private:  int x, y; // 定义私有数据
public: // 定义公有成员函数
    // 定义带参数的构造函数
    CTest(int p1 = 0, int p2 = 0)  {  x = p1;  y = p2;  }
    // 定义拷贝构造函数
    CTest(CTest &p)  {  x = p.x;  y = p.y;  }
    // 定义Show成员函数
    void Show( )  {  cout << x << ", " << y << endl;  }
};
int main( ) // 主函数
{
    CTest obj1; // 定义一个CTest对象obj1,使用默认参数0,0
    obj1.Show( );    // 调用成员函数Show( )
    CTest obj2(2, 5);// 定义一个CTest对象obj2,使用参数2,5
    obj2.Show( );    // 调用成员函数Show( )
    CTest obj3(obj2);// 定义一个CTest对象obj3,拷贝obj2的值2,5
    obj3.Show( );    // 调用成员函数Show( )
    return 0; //主函数返回值0，正常结束程序
}
