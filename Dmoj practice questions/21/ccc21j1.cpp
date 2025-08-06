#include <iostream>

int main()
{
    int b = 0;
    std::cin >> b;
    int p = 5 * b - 400;
    std::cout << p << std::endl;
    if (p < 100)
    {
        std::cout << 1 << std::endl;
    }
    else if (p > 100)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }

    return 0;
}