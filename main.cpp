#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    nums.push_back(6);
    nums.push_back(7);
    for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << "\n";
    }
    return 0;
}