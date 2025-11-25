---
status: Done
difficulty: Medium
algo: Prefix Sums
group:
  - Arrays
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Two-Pointers_Problems]]

# Subarray Sum Equals K
## Description 
You are given an array of integers `nums` and an integer `k`, return the total number of subarrays whose sum equals to `k`.

A **subarray** is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**

```java
Input: nums = [2,-1,1,2], k = 2

Output: 4
```

Explanation: `[2]`, `[2,-1,1]`, `[-1,1,2]`, `[2]` are the subarrays whose sum is equals to `k`.

**Example 2:**

```java
Input: nums = [4,4,4,4,4,4], k = 4

Output: 6
```

**Constraints:**

- `1 <= nums.length <= 20,000`
- `-1,000 <= nums[i] <= 1,000`
- `-10,000,000 <= k <= 10,000,000`
## Code 
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, curSum = 0;
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;

        for (int num : nums) {
            curSum += num;
            int diff = curSum - k;
            res += prefixSums[diff];
            prefixSums[curSum]++;
        }

        return res;
    }
};
```

