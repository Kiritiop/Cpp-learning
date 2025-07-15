#include <iostream>
#include <vector>
using namespace std;

int main() {
    int first = 0;
    int second = 0;
    int third = 0;
    int score = 0;
    int counter = 0;
    int number;
    cin >> number;
    vector<int> nums;
    for (int i = 0; i < number; i++) {
        cin >> score;
        nums.push_back(score);

        if (score > first) {
            third = second;
            second = first;
            first = score;
        } else if (score > second && score < first) {
            third = second;
            second = score;
        } else if (score > third && score < second) {
            third = score;
        }
        
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums.at(i) == third) {
            counter++;
        }
    }
    cout << third << " " << counter << endl;
    return 0;
}