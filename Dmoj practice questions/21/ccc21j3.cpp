#include <iostream>

int main()
{
    int code;
    int first;
    int second;
    int steps;
    std::string direction = "";
    std::cin >> code;
    while (code != 99999) {
        first = code / 10000;
        second = code /1000 %10;
        steps = code %1000;
        if ((first + second) % 2 == 1) {
            direction = "left";
        } else if ((first + second) % 2 == 0 && (first + second)!= 0) {
            direction = "right";
        }
        std::cout << direction << " " << steps << std::endl;
        std::cin >> code;
    }
    

    return 0;
}