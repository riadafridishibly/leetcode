// Sunday 14 Apr, 2019 12:34:40 PM


#include <vector> // vector
#include <utility> // pair
#include <cstdint> // uint8_t
#include <algorithm> // reverse

using namespace std;

class Solution {
  public:
    vector<int> findOrder(int numCourses,
                          vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<uint8_t> color(numCourses, 0);
        vector<int> res;

        for (auto [u, v] : prerequisites) {
            graph[v].push_back(u);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (color[i] == 0 and dfs2(i, graph, color, res))
                return {};
        }
        std::reverse(std::begin(res), std::end(res));
        return res;
    }

    bool dfs2(int v, vector<vector<int>> &g, vector<uint8_t> &color,
              vector<int> &res) {
        // returns true if cycle found
        // otherwise returns false
        color[v] = 1;
        for (int u : g[v]) {
            if (color[u] == 0) {
                if (dfs2(u, g, color, res))
                    return true;
            } else if (color[u] == 1) {
                return true;
            }
        }
        color[v] = 2;
        res.push_back(v);
        return false;
    }
};
