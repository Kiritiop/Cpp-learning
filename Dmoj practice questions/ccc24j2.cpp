#include <iostream>
using namespace std;

int main() {
    int dusa, yobi;
    cin >> dusa >> yobi;
    while (dusa > yobi) {
        dusa += yobi;
        cin >> yobi;
    }


    cout << dusa << endl;
    return 0;
}