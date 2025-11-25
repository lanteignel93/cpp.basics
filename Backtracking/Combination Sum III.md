---
status: Done
difficulty: Medium
algo: Combinations
group:
  - Backtracking
  - Trees
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Combinations Problems]]

# Combination Sum III
## Description 
Find all valid combinations of `k` numbers that sum up to `n` such that the following conditions are true:

- Only numbers `1` through `9` are used.
- Each number is used **at most once**.

Return _a list of all possible valid combinations_. The list must not contain the same combination twice, and the combinations may be returned in any order.

**Example 1:**
```
**Input:** k = 3, n = 7
**Output:** [[1,2,4]]
**Explanation:**
1 + 2 + 4 = 7
```
There are no other valid combinations.

**Example 2:**

```
**Input:** k = 3, n = 9
**Output:** [[1,2,6],[1,3,5],[2,3,4]]
```
**Explanation:**
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

**Example 3:**

```
**Input:** k = 4, n = 1
**Output:** []
```
**Explanation:** There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

**Constraints:**

- `2 <= k <= 9`
- `1 <= n <= 60`

```cpp
class Solution {
  public:
    void dfs(int k, int n, int idx, std::vector<int> &path,
             std::vector<std::vector<int>> &res) {
        if (n < 0) {
            return;
        }
        if (path.size() == k && n == 0) {
            res.push_back(path);
            return;
        }
        for (int i = idx; i <= 9; ++i) {
            path.push_back(i);
            dfs(k, n - i, i + 1, path, res);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<int> path;
        std::vector<std::vector<int>> res;
        int idx = 1;
        dfs(k, n, idx, path, res);
        return res;
    }
};
```