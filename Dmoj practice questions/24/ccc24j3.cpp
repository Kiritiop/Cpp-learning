#include <iostream>
#include <vector>
using namespace std;

int main() {
    int first, second, third, score, counter = 0;
    int number;
    cin >> number;
    vector<int> nums;
    for (int i = 0; i < number; i++) {
        cin >> score;
        if (score >= first) {
            first = score;
        } else if (score >= second) {
            second = score;
        } else if (score >= third) {
            third = score;
        }
        nums.push_back(score);
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == third) {
            counter++;
        }
    }
    cout << third << " " << counter << endl;
    return 0;
}