## Problem statement
Write an algorithm to determine if a number `n` is "happy".

A happy number is a number defined by the following process: Starting with any
positive integer, replace the number by the sum of the squares of its digits,
and repeat the process until the number equals 1 (where it will stay), or it
*loops endlessly* in a cycle which does not include 1. Those numbers for which
this process *ends in 1* are happy numbers.

Return True if `n` is a happy number, and False if not.

### Example
```
Input: 19
Output: true

Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```
## Solution 1

Start simulation. If we see same number again, we're in a loop. It's good time to
return false. Otherwise we'll converge at some point.

```cpp
int sum_sqr_of_digits(int n) {
    if (n == 0) // special case
        return 0;

    int sum = 0;
    while (n) {
        auto u = n % 10;
        n /= 10;
        sum += u * u;
    }
    return sum;
}

class Solution {
public:
    bool isHappy(int n) {
        std::set<int> sums;
        while (true) {
            n = sum_sqr_of_digits(n);
            if (n == 1) return true;
            if (const auto it = sums.find(n); 
                    it != std::end(sums)) {
                return false;
            } else {
                sums.insert(n);
            }
        }
    }
};
```

## Solution 2

From simulation result we can see that at some point we'll hit the number `145`. If
we do get out of the loop. Otherwise we'll converge.

```cpp
class Solution {
public:
    bool isHappy(int n) {
        if (n == 0)
            return false;
        
        while (true) {
            int sum = 0;
            while (n) {
                auto u = n % 10;
                n /= 10;
                sum += u * u;
            }
            n = sum;
            if (sum == 145) {
                return false;
            } else if (sum == 1) {
                return true;
            }
        }
    }
};
```
