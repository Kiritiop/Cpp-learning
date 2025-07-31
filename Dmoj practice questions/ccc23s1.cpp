#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int c_cols;
    std::cin >> c_cols;

    std::vector<std::vector<int>> tiles(2, std::vector<int>(c_cols));
    
    long long black_tile_count = 0;

    for (int r = 0; r < 2; ++r) {
        for (int col = 0; col < c_cols; ++col) {
            std::cin >> tiles[r][col];
            if (tiles[r][col] == 1) {
                black_tile_count++;
            }
        }
    }

    long long shared_sides = 0;

    for (int r = 0; r < 2; ++r) {
        for (int col = 0; col < c_cols - 1; ++col) {
            if (tiles[r][col] == 1 && tiles[r][col + 1] == 1) {
                shared_sides++;
            }
        }
    }

    for (int col = 0; col < c_cols; ++col) {
        if ((col % 2) == 0) {
            if (tiles[0][col] == 1 && tiles[1][col] == 1) {
                shared_sides++;
            }
        }
    }

    long long total_tape = black_tile_count * 3 - shared_sides * 2;
    
    std::cout << total_tape << std::endl;

    return 0;
}