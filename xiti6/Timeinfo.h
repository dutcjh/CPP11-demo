// Timeinfo.h
#ifndef __TIMEINFO_H__
#define __TIMEINFO_H__
using namespace std;

class CTimeInfo
{
private:
    int hour, minute;
public:
    CTimeInfo(): hour(0), minute(0){ } //�޲����Ĺ��캯��
    CTimeInfo(const int &h, const int &m); //�������Ĺ��캯��
    void SetTime(const int &h, const int &m); //ʱ�������
    friend void GetTime12(const CTimeInfo &tm);//12Сʱ�ķ�ʽ���ʱ��
    friend void GetTime24(const CTimeInfo &tm);//24Сʱ�ķ�ʽ���ʱ��
};

#endif // __TIMEINFO_H__
