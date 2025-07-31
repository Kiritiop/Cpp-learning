#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int num_people;
    std::cin >> num_people;

    std::vector<int> availability_counts(5, 0);

    for (int i = 0; i < num_people; ++i) {
        std::string availability_string;
        std::cin >> availability_string;

        for (int j = 0; j < 5; ++j) {
            if (availability_string[j] == 'Y') {
                availability_counts[j]++;
            }
        }
    }

    int max_availability = 0;
    if (!availability_counts.empty()) {
        max_availability = *std::max_element(availability_counts.begin(), availability_counts.end());
    }

    std::vector<int> best_days;
    for (int i = 0; i < 5; ++i) {
        if (availability_counts[i] == max_availability) {
            best_days.push_back(i + 1);
        }
    }

    for (size_t i = 0; i < best_days.size(); ++i) {
        std::cout << best_days[i];
        if (i < best_days.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << std::endl;

    return 0;
}