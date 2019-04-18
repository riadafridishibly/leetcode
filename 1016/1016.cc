// 6 Apr, 2019

#include <unordered_set>
#include <cmath>

using namespace std;


// Sliding Window

class Solution {
public:
    bool queryString(string S, int N) {
        std::unordered_set<int> allvals;

        int bitcount = (int) (log2(N) + 1);

        for (int i = 1; i <= bitcount; ++i) {
            int res = 0;
            for (int index = 0; index < (int) S.size(); ++index) {
                if (index - i >= 0) {
                    res -= (S[index - i] - '0') * (1 << i);
                }
                res += S[index] - '0';
                if (res > 0 and res <= N) {
                    allvals.insert(res);
                }
                res <<= 1;
            }
        }

        return (int)allvals.size() == N;
    }
};
