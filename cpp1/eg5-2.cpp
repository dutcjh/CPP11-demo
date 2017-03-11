// ÷”±Ì¿‡
#include<iostream>
#include<iomanip>
using namespace std;

class Clock
{
public:
    Clock():hour(0),minute(0),second(0){};
    Clock(int newH, int newM, int newS):hour(newH),minute(newM),second(newS){};
    void setTime(int newH = 0, int newM = 0, int newS = 0);
    void showTime();
    friend ostream &operator<<(ostream &os, const Clock &c);
    friend istream &operator>>(istream &is, Clock &c);
private:
    int hour, minute, second;
};

void Clock::setTime(int newH, int newM, int newS)
{
    hour = newH;
    minute = newM;
    second = newS;
}

istream &operator>>(istream &is, Clock &c)
{
    char a;
    is >> c.hour >> a >> c.minute >> a >> c.second;
    return is;
}



/*
void Clock::showTime()
{
    cout << setw(2) << setfill('0') << hour << ":" \
    << setw(2) << setfill('0') << minute << ":" \
    << setw(2) << setfill('0') << second << endl;
}*/

ostream &operator<<(ostream &os, const Clock &c)
{
    os << setw(2) << setfill('0') << c.hour << ":" \
    << setw(2) << setfill('0') << c.minute << ":" \
    << setw(2) << setfill('0') << c.second;
    return os;
}


int main()
{
    Clock myClock;
    //cin >> myClock;
    cout << myClock << endl;
    myClock.setTime(8, 30, 30);
    cout << myClock << endl;
    myClock.setTime(15, 30, 0);
    cout << myClock << endl;
    return 0;
}
