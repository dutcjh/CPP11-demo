// Timeinfo.h
#ifndef __TIMEINFO_H__
#define __TIMEINFO_H__
using namespace std;

class CTimeInfo
{
private:
    int hour, minute;
public:
    CTimeInfo(): hour(0), minute(0){ } //无参数的构造函数
    CTimeInfo(const int &h, const int &m); //带参数的构造函数
    void SetTime(const int &h, const int &m); //时间的设置
    friend void GetTime12(const CTimeInfo &tm);//12小时的方式输出时间
    friend void GetTime24(const CTimeInfo &tm);//24小时的方式输出时间
};

#endif // __TIMEINFO_H__
