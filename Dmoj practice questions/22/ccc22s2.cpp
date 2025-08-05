#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::unordered_map<std::string, std::unordered_set<std::string>> friends, enemies;
    int F, E, G;

    std::cin >> F;
    for (int i = 0; i < F; ++i)
    {
        std::string a, b;
        std::cin >> a >> b;
        friends[a].insert(b);
        friends[b].insert(a);
    }

    std::cin >> E;
    for (int i = 0; i < E; ++i)
    {
        std::string a, b;
        std::cin >> a >> b;
        enemies[a].insert(b);
        enemies[b].insert(a);
    }

    std::cin >> G;
    std::unordered_set<std::pair<std::string, std::string>, pair_hash> violated_pairs;

    for (int i = 0; i < G; ++i)
    {
        std::string g[3];
        std::cin >> g[0] >> g[1] >> g[2];
        std::unordered_set<std::string> group_members(g, g + 3);

        for (int j = 0; j < 3; ++j)
        {
            if (friends.count(g[j]))
            {
                for (const auto &fr : friends.at(g[j]))
                {
                    if (group_members.find(fr) == group_members.end())
                    {
                        violated_pairs.insert({std::min(g[j], fr), std::max(g[j], fr)});
                    }
                }
            }
        }

        if (enemies.count(g[0]) && enemies.at(g[0]).count(g[1]))
        {
            violated_pairs.insert({std::min(g[0], g[1]), std::max(g[0], g[1])});
        }
        if (enemies.count(g[0]) && enemies.at(g[0]).count(g[2]))
        {
            violated_pairs.insert({std::min(g[0], g[2]), std::max(g[0], g[2])});
        }
        if (enemies.count(g[1]) && enemies.at(g[1]).count(g[2]))
        {
            violated_pairs.insert({std::min(g[1], g[2]), std::max(g[1], g[2])});
        }
    }

    std::cout << violated_pairs.size() << std::endl;

    return 0;
}