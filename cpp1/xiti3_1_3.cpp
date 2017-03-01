//输入一个0～6的整数，转换成星期输出。
#include <iostream>
#include <string>
using namespace std;

class Week
{
private:
    string day = "Sunday";
public:
    Week(unsigned num)
    {
        switch(num) // 转换
        {
        case 0: day = "Sunday"; break;
        case 1: day = "Monday"; break;
        case 2: day = "Tuesday"; break;
        case 3: day = "Wednesday"; break;
        case 4: day = "Thursday"; break;
        case 5: day = "Friday"; break;
        case 6: day = "Saturday"; break;
        default:day = "Error!!!"; break;
        }
    }
    string get_day()const {return day;}
};

ostream &operator<< (ostream &os, const Week &item)
{
    os << item.get_day();
    return os;
}

int main()
{
    unsigned num;
    do  // 输入检查
    {
        cout << "Please input a number(0~6): ";
        cin >> num;
        if (num > 6)
            cout << "Error input!" << endl;
        else
            break;
    }while(1);
    Week w(num);
    cout << w << endl;
    return 0;
}
