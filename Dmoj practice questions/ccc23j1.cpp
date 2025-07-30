#include <iostream>
using namespace std;

int main() {
    int p = 0;
    int c = 0;
    int score = 0;
    cin >> p >> c;
    score += p*50;
    score -= c*10;
    if (p > c) {
        score += 500;
    }

    cout << score << endl;
    return 0;
}