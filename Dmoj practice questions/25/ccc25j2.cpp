#include <iostream>
using namespace std;

int main() {
    int d, e;
    cin >> d;
    cin >> e;
    for (int i = 0; i < e; i++) {
        char sign;
        int q;
        cin >> sign;
        cin >> q;
        if (sign == '+') {
            d += q;
        } else {
            d -= q;
        }
    }

    cout << d;
}