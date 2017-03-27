#include<iostream>
#include<stdexcept>
using namespace std;

class CRectangle
{
private:
    double length; // ��
    double width;  // ��
public:
    //���캯���Գ�����г�ʼ�������������ǵ�Ĭ��ֵ��1��
    CRectangle(const double a = 1, const double b = 1):
        length(a),width(b){}
    //�����䳤�Ϳ���ȷ�����Ϳ��ڣ�0��50����Χ֮�ڡ�
    void SetValue(const double &len, const double &wid);
    //�󳤷������
    double Area() const { return length*width; };
    //�󳤷����ܳ�
    double Perimeter() const { return 2*(length+width); };
};

void CRectangle::SetValue(const double &len, const double &wid)
{
    if ((len > 0) && (len < 50))
        length = len;
    else // �׳��쳣
        throw runtime_error("The length is error!");
    if ((wid > 0) && (wid < 50))
        width = wid;
    else // �׳��쳣
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
