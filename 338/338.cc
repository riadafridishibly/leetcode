// Thursday 18 Apr, 2019 02:22:48 PM

#include <vector>
using namespace std;


class Solution {
public:
    // brian kernighan algorithm
    int count(int val) {
        int c = 0;
        for (; val; ++c) {
            val = val & (val - 1);
        }
        return c;
    }
    vector<int> countBits(int num) {
        vector<int> v(num + 1);
        for (int i = 0; i <= num; ++i) {
            v[i] = count(i);
        }
        return v;
    }
};
