---
status: Done
difficulty: Medium
algo: Sliding Window
group:
  - Arrays
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Sliding_Window_Problems]]

# Find K Closest Elements
## Description 
You are given a sorted integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should also be sorted in ascending order.

An integer `a` is closer to `x` than an integer `b` if:

- `|a - x| < |b - x|`, or
- `|a - x| == |b - x|` and `a < b`

**Example 1:**

```java
Input: arr = [2,4,5,8], k = 2, x = 6

Output: [4,5]
```

**Example 2:**

```java
Input: arr = [2,3,4], k = 3, x = 1

Output: [2,3,4]
```

**Constraints:**

- `1 <= k <= arr.length <= 10,000`.
- `-10,000 <= arr[i], x <= 10,000`
- `arr` is sorted in **ascending** order.
## Code 
```cpp
class Solution {
public:

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1; 
        while (r - l >= k) {
            if (std::abs(x - arr[l]) <= abs(x - arr[r])) {
                r--;
            } else {
                l++; 
            }
        }
        return std::vector<int>(arr.begin() + l, arr.begin() + r + 1); 
    }
};
```
