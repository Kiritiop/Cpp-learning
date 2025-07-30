#include <iostream>
#include <string>

using namespace std;

int main() {
    int n = 0;
    int t = 0;
    cin >> n;
    string chilli;
    for (int i = 0; i < n; i++) {
        cin >> chilli;
        if (chilli == "Poblano") {
            t += 1500;
        } else if (chilli == "Mirasol") {
            t += 6000;
        } else if (chilli == "Serrano") {
            t += 15500;
        } else if (chilli == "Cayenne") {
            t += 40000;
        } else if (chilli == "Thai") {
            t += 75000;
        } else if (chilli == "Habanero") {
            t += 125000;
        }
    }
    cout << t << endl;
    return 0;
}