#include<iostream>
#include<stdexcept>
using namespace std;

class CRectangle
{
private:
    double length; // 长
    double width;  // 宽
public:
    //构造函数对长宽进行初始化，且设置它们的默认值是1。
    CRectangle(const double a = 1, const double b = 1):
        length(a),width(b){}
    //设置其长和宽，并确保长和宽都在（0，50）范围之内。
    void SetValue(const double &len, const double &wid);
    //求长方形面积
    double Area() const { return length*width; };
    //求长方形周长
    double Perimeter() const { return 2*(length+width); };
};

void CRectangle::SetValue(const double &len, const double &wid)
{
    if ((len > 0) && (len < 50))
        length = len;
    else // 抛出异常
        throw runtime_error("The length is error!");
    if ((wid > 0) && (wid < 50))
        width = wid;
    else // 抛出异常
        throw runtime_error("The width is error!");
}

int main()
{
    CRectangle obj(2,3);
    cout << "Length = 2  Width = 3" << endl;
    cout << "Area = " << obj.Area() << endl;
    cout << "Perimeter = " << obj.Perimeter() << endl;
    obj.SetValue(30,25);
    cout << "Length = 30  Width = 25" << endl;
    cout << "Area = " << obj.Area() << endl;
    cout << "Perimeter = " << obj.Perimeter() << endl;
    return 0;
}
