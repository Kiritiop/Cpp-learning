#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    int price = 0;
    std::string winner = "";
    std::string person = "";
    int bid = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> person >> bid;
        if (bid > price)
        {
            price = bid;
            winner = person;
        }
    }
    std::cout << winner << std::endl;
}