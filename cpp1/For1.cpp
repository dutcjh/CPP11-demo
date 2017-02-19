#include <iostream>

int main()
{
    int sum = 0, value = 0;
    // read data until file end, calculate the sum of all value
    while (std::cin >> value)
        sum += value;
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}
