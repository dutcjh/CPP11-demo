// xiti6_1.cpp
#include <iostream>
#include "Timeinfo.h"
using namespace std;

#define Test 0  // 测试标志

int main()
{
    CTimeInfo a; //定义无参对象a
    a.SetTime(20,30); //用SetTime对a设置时间为20:30
    GetTime12(a); //调用GetTime12显示时间
    GetTime24(a); //调用GetTime24显示时间

    CTimeInfo b(22,15); //定义带参对象b（22,15）
    GetTime12(b); //调用GetTime12显示时间
    GetTime24(b); //调用GetTime24显示时间

    #if(Test == 1)// 测试代码
    CTimeInfo c(12,5); //定义带参对象c（12,5）
    GetTime12(c); //调用GetTime12显示时间
    GetTime24(c); //调用GetTime24显示时间
    c.SetTime(23,59);
    GetTime12(c); //调用GetTime12显示时间
    GetTime24(c); //调用GetTime24显示时间
    c.SetTime(24,10);
    GetTime12(c); //调用GetTime12显示时间
    GetTime24(c); //调用GetTime24显示时间
    #endif
    return 0;
}
