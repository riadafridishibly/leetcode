## Problem statement
Given a non-empty array of integers, every element appears twice except for one.
Find that single one.

### Example 1
```
Input: [2,2,1]
Output: 1
```

### Example 2
```
Input: [4,1,2,1,2]
Output: 4
```

## Solution 1
By using extra space.

Algorithm:
- Count the frequency of the numbers
- Return the number with the frequency one

### Python Implementation:

```python
from typing import List
from collections import Counter

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        count = Counter(nums)
        ret = list(filter(lambda x: x[1] == 1, count.items()))
        if not ret:
            return -1
        return ret[0][0]
```

### C++ Implementation

```cpp
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;

        for (const auto num : nums) {
            freq[num]++;
        }

        auto ret = std::find_if(std::begin(freq), std::end(freq),
                [](auto &elm) {
                    return elm.second == 1;
                });

        if (ret == std::end(freq)) {
            return -1;
        }
        return ret->first;
    }
};
```

## Solution 2
Using constant space.

`xor` has a special property. If we `xor` a number even number of times with
zero then it clears the bits. But if we apply odd number of times then it keeps
the bit signature.

### Python Implementation

```python
from operator import xor
from functools import reduce

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(xor, nums, 0)
```

### C++ Implementation

```cpp
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        // From C++17 std::reduce can be used
        return std::accumulate(std::begin(nums), std::end(nums), 
                0, // initial value
                std::bit_xor<int>() // operation to perform
            );
    }
};
```

### Verbose version

```cpp
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        auto res = 0;
        for (const auto val : nums) {
            res ^= val;
        }
        return res;
    }
};
```
