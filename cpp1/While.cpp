#include <iostream>
int main()
{
    int sum = 0, sta_val = 0, end_val = 0;
    //ֻҪval��ֵС�ڵ���10��whileѭ���ͻ����ִ��
    std::cout << "Please input two numbers: " << std::endl;
    std::cin >> sta_val >> end_val;
    if (sta_val > end_val)
    {
        int temp = sta_val;
        sta_val = end_val;
        end_val = temp;
    }
    int val = sta_val;
    while (val <= end_val)
    {
        sum += val;
        ++val;
    }
    std::cout << "Sum of " << sta_val << " to " << end_val
              << " inclusive is " << sum << std::endl;
    return 0;
}
