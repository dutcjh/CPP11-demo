// Timeinfo.cpp
#include <iostream>
#include <iomanip>
#include "Timeinfo.h"

//�����Ĺ��캯��
CTimeInfo::CTimeInfo(const int &h, const int &m)
{
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m <= 60) ? m : 0;
}
//��24Сʱʱ���������
void CTimeInfo::SetTime(const int &h, const int &m)
{
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m <= 60) ? m : 0;
}

//12Сʱ�ķ�ʽ���ʱ��
void GetTime12(const CTimeInfo &tm)
{
    int hr = (tm.hour > 12) ? (tm.hour - 12) : tm.hour;
    cout << setw(2) << setfill(' ') << hr << ":"
        << setw(2) << setfill('0') << tm.minute
        << ((tm.hour >= 12) ? " pm" : " am") << endl;
}

//24Сʱ�ķ�ʽ���ʱ��
void GetTime24(const CTimeInfo &tm)
{
    cout << setw(2) << setfill(' ') << tm.hour << ":"
        << setw(2) << setfill('0') << tm.minute << endl;
}
