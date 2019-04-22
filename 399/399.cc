// Monday 22 Apr, 2019 07:26:59 PM
// Maybe there's a better way to do this. But this works for now. So, upgrading
// this code will be an exercise for me.

#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>
        graph;

  public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double> &values,
                                vector<pair<string, string>> queries) {
        for (int i = 0; i < (int)equations.size(); ++i) {
            const auto &pr = equations[i];
            const auto &val = values[i];
            graph[pr.first].push_back({pr.second, 1.0 / val});
            graph[pr.second].push_back({pr.first, val});
        }

        vector<double> res;

        for (auto &pr : queries) {
            if (graph.find(pr.first) == graph.end() ||
                graph.find(pr.second) == graph.end()) {
                res.push_back(-1.0);
            } else if (pr.first == pr.second) {
                res.push_back(1.0);
            } else {
                string st = pr.first;
                string en = pr.second;
                unordered_map<string, string> pmap;
                unordered_set<string> visited;

                dfs(pr.first, pr.second, pmap, visited);

                double r = 1;
                bool invalid = false;

                while (st != en) {

                    const auto &v = pmap[en];

                    auto it = std::find_if(
                        graph[en].begin(), graph[en].end(),
                        [&v](auto &elm) { return elm.first == v; });

                    auto val = 0.0;

                    if (it == graph[en].end()) {
                        invalid = true;
                        break;
                    } else {
                        val = it->second;
                    }

                    r *= val;
                    en = pmap[en];
                }

                if (invalid)
                    res.push_back(-1.0);
                else
                    res.push_back(r);
            }
        }
        return res;
    }

    void dfs(string u, string &search, unordered_map<string, string> &pmap,
             unordered_set<string> &visited) {
        visited.insert(u);
        for (auto &adjPr : graph[u]) {
            auto &curr = adjPr.first;
            if (visited.find(curr) == visited.end()) {
                visited.insert(curr);
                pmap[curr] = u;

                dfs(curr, search, pmap, visited);

                if (curr == search)
                    return;
            }
        }
    }
};
