#include <iostream>
using namespace std;

int main() {
    int first, second, third, score = 0;
    int number;
    cin >> number;
    int num[] = {};
    for (int i = 0; i < number; i++) {
        cin >> score;
        if (score >= first) {
            first = score;
        } else if (score >= second) {
            second = score;
        } else if (score >= third) {
            third = score;
        }

    }
    return 0;
}