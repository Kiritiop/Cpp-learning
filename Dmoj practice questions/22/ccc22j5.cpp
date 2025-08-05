#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

struct Point
{
    int x, y;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, t;
    std::cin >> n >> t;

    std::vector<Point> points(t);
    std::set<int> x_coords_set;
    x_coords_set.insert(0);
    for (int i = 0; i < t; i++)
    {
        std::cin >> points[i].x >> points[i].y;
        x_coords_set.insert(points[i].x);
    }

    std::vector<int> x_coords(x_coords_set.begin(), x_coords_set.end());

    int max_side = 0;

    if (t == 0)
    {
        std::cout << n << "\n";
        return 0;
    }

    for (size_t i = 0; i < x_coords.size(); ++i)
    {
        int x_left = x_coords[i];

        std::vector<int> y_obstacles;
        y_obstacles.push_back(0);
        y_obstacles.push_back(n);

        for (const auto &p : points)
        {
            if (p.x >= x_left)
            {
                y_obstacles.push_back(p.y);
            }
        }
        std::sort(y_obstacles.begin(), y_obstacles.end());
        y_obstacles.erase(std::unique(y_obstacles.begin(), y_obstacles.end()), y_obstacles.end());

        int max_h = 0;
        for (size_t k = 0; k < y_obstacles.size() - 1; ++k)
        {
            max_h = std::max(max_h, y_obstacles[k + 1] - y_obstacles[k]);
        }

        int width = n - x_left;
        max_side = std::max(max_side, std::min(width, max_h));
    }

    for (size_t i = 0; i < x_coords.size(); ++i)
    {
        int x_left = x_coords[i];

        std::vector<int> y_in_strip;
        y_in_strip.push_back(0);
        y_in_strip.push_back(n);

        for (size_t j = i + 1; j < x_coords.size(); ++j)
        {
            int x_right = x_coords[j];
            int width = x_right - x_left;

            for (const auto &p : points)
            {
                if (p.x == x_coords[j - 1])
                {
                    y_in_strip.push_back(p.y);
                }
            }
            std::sort(y_in_strip.begin(), y_in_strip.end());

            int max_h = 0;
            for (size_t k = 0; k < y_in_strip.size() - 1; ++k)
            {
                max_h = std::max(max_h, y_in_strip[k + 1] - y_in_strip[k]);
            }

            max_side = std::max(max_side, std::min(width, max_h));
        }
    }

    std::cout << max_side << "\n";
    return 0;
}