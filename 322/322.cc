// Saturday 20 Apr, 2019 09:15:39 PM

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  private:
    std::unordered_map<
        std::string, std::priority_queue<std::string, std::vector<std::string>,
                                         std::greater<std::string>>>
        graph;

  public:
    std::vector<std::string>
    findItinerary(std::vector<std::pair<std::string, std::string>> tickets) {
        if (tickets.empty())
            return {};

        for (const auto &[u, v] : tickets) {
            graph[u].push(v);
        }

        std::vector<std::string> res;
        dfs("JFK", res);
        std::reverse(std::begin(res), std::end(res));
        return res;
    }

    void dfs(const std::string &curr, std::vector<std::string> &res) {
        // if (graph[curr].empty())
        //     return;
        while (!graph[curr].empty()) {
            std::string ss = graph[curr].top();
            graph[curr].pop();
            dfs(ss, res);
        }
        res.push_back(curr);
    }
};
