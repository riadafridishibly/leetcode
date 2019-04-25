// Thursday 25 Apr, 2019 11:24:56 PM

#include <cstdint>
#include <numeric>
#include <vector>
using namespace std;

class Solution {

    struct UF {
        vector<uint8_t> rank;
        vector<int> parent;
        explicit UF(int size) {
            parent.resize(size);
            rank.assign(size, 0);
            iota(parent.begin(), parent.end(), 0);
        }
        int Find(int p) {
            while (p != parent[p])
                p = parent[p];
            return p;
        }
        void Union(int p, int q) {
            p = Find(p);
            q = Find(q);

            if (rank[p] > rank[q])
                parent[q] = p;
            else if (rank[p] < rank[q])
                parent[p] = q;
            else {
                parent[q] = p;
                rank[p]++;
            }
        }
    };

  public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        UF uf(edges.size() + 1);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int rootU = uf.Find(u);
            int rootV = uf.Find(v);

            if (rootV == rootU)
                return {u, v};

            uf.Union(rootU, rootV);
        }
        return {};
    }
};

