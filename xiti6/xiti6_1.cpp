// xiti6_1.cpp
#include <iostream>
#include "Timeinfo.h"
using namespace std;

#define Test 0  // ���Ա�־

int main()
{
    CTimeInfo a; //�����޲ζ���a
    a.SetTime(20,30); //��SetTime��a����ʱ��Ϊ20:30
    GetTime12(a); //����GetTime12��ʾʱ��
    GetTime24(a); //����GetTime24��ʾʱ��

    CTimeInfo b(22,15); //������ζ���b��22,15��
    GetTime12(b); //����GetTime12��ʾʱ��
    GetTime24(b); //����GetTime24��ʾʱ��

    #if(Test == 1)// ���Դ���
    CTimeInfo c(12,5); //������ζ���c��12,5��
    GetTime12(c); //����GetTime12��ʾʱ��
    GetTime24(c); //����GetTime24��ʾʱ��
    c.SetTime(23,59);
    GetTime12(c); //����GetTime12��ʾʱ��
    GetTime24(c); //����GetTime24��ʾʱ��
    c.SetTime(24,10);
    GetTime12(c); //����GetTime12��ʾʱ��
    GetTime24(c); //����GetTime24��ʾʱ��
    #endif
    return 0;
}
