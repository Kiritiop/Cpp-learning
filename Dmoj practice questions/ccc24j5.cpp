#include <iostream>
#include <vector>
using namespace std;

vector<string> grid;
int r, c;

int solve(int x, int y);

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        string s;
        cin >> s;
        grid.push_back(s);
    }
    cin >> x >> y;
    cout << solve(x, y) << '\n';
    return 0;
}

int solve(int x, int y) {
    int res;
    if (x < 0 || y < 0 || x >= r || y >= c) {
        return 0;
    }
    if (grid[x][y] == '*') {
        return 0;
    }
    res = 0;
    if (grid[x][y] == 'L') {
        res = 10;
    } else if (grid[x][y] == 'M') {
        res = 5;
    } else {
        res = 1;
    }
    grid[x][y] = '*';
    res += solve(x - 1, y);
    res += solve(x + 1, y);
    res += solve(x, y - 1);
    res += solve(x, y + 1);
    return res;
}