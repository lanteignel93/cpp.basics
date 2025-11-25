---
status: Done
difficulty: Medium
algo: Binary Search
group:
  - Others
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Binary Search Problems]]

# Unique Binary Search Trees
## Description 
Given an integer `n`, return _the number of structurally unique **BST'**s (binary search trees) which has exactly_ `n` _nodes of unique values from_ `1` _to_ `n`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

**Input:** n = 3
**Output:** 5

**Example 2:**

**Input:** n = 1
**Output:** 1

**Constraints:**

- `1 <= n <= 19`
## Code 
```cpp
class Solution {
public:
    int numTrees(int n) {
        std::vector<int> uniqTree(n + 1, 1);

        for (int nodes = 2; nodes <= n; nodes++) {
            int total = 0;
            for (int root = 1; root <= nodes; root++) {
                total += uniqTree[root - 1] * uniqTree[nodes - root];
            }
            uniqTree[nodes] = total;
        }

        return uniqTree[n];        
    }
};
```
