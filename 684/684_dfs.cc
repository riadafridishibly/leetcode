// Thursday 25 Apr, 2019 07:34:03 PM

#include <cstdint>
#include <unordered_set>
#include <vector>

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

class Solution {
    using Graph = vector<vector<int>>;
    using Color = vector<uint8_t>;

  public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        if (edges.empty())
            return {};

        int size = edges.size();

        Graph g(size);

        for (auto &row : edges) {
            int u = row[0] - 1;
            int v = row[1] - 1;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        Color visited(size, WHITE);
        vector<int> parent(size);
        int start, end;

        dfs(0, g, visited, start, end, parent, -1);

        unordered_set<int> cycle;

        cycle.insert(start);

        for (int u = end; u != start; u = parent[u])
            cycle.insert(u);

        for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
            auto u = it->at(0) - 1;
            auto v = it->at(1) - 1;

            if (cycle.find(u) != cycle.end() and cycle.find(v) != cycle.end()) {
                return {u + 1, v + 1};
            }
        }

        return {};
    }

    bool dfs(int u, Graph &g, Color &visited, int &start, int &end,
             vector<int> &parent, int prnt) {
        visited[u] = GRAY;
        for (auto adj : g[u]) {
            if (adj == prnt)
                continue;
            if (visited[adj] == WHITE) {
                parent[adj] = u;
                if (dfs(adj, g, visited, start, end, parent, u))
                    return true;
            } else if (visited[adj] == GRAY) {
                end = u;
                start = adj;
                return true;
            }
        }
        visited[u] = BLACK;
        return false;
    }
};
