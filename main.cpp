#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int pt, foul;
    int star = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pt >> foul;
        if ((pt * 5 - foul * 3) > 40)
        {
            star++;
        }
    }
    if (star == n)
    {
        cout << star << "+" << endl;
    }
    else
    {
        cout << star << endl;
    }
    return 0;
}