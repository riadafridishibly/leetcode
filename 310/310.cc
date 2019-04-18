// Thursday 18 Apr, 2019 02:20:01 PM

#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        std::vector<std::vector<int>> adj(n);

        // Create Graph
        for (auto [u, v] : edges) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return findTrees(adj);
    }

    vector<int> findTrees(vector<vector<int>> &g) {
        vector<int> leaves;
        if (g.size() == 1) leaves.push_back(0);
        vector<int> degrees(g.size());
        int totalNodes = g.size();
        for (int i = 0; i < (int) g.size(); ++i) {
            degrees[i] = g[i].size();
            if (g[i].size() == 1)
                leaves.push_back(i);
        }

        while (totalNodes > 2) {
            totalNodes -= leaves.size();
            
            // for (auto val : leaves) cout << val << ' '; cout << '\n';

            vector<int> newLeaves;
            for (int v : leaves) {
                degrees[v]--;
                
                for (auto vtx : g[v]) {
                    degrees[vtx]--;
                    if (degrees[vtx] == 1)
                        newLeaves.push_back(vtx);
                }
            }
            leaves = newLeaves;
        }

        return leaves;
    }
};
