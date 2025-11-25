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

# Combination Sum II
## Description 
Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:** The solution set must not contain duplicate combinations.

**Example 1:**
```
**Input:** candidates = [10,1,2,7,6,1,5], target = 8
**Output:** 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

**Example 2:**

```
**Input:** candidates = [2,5,2,1,2], target = 5
**Output:** 
[
[1,2,2],
[5]
]
```

**Constraints:**

- `1 <= candidates.length <= 100`
- `1 <= candidates[i] <= 50`
- `1 <= target <= 30`

```cpp
class Solution {
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;

        vector<int> comb;
        dfs(candidates, target, 0, comb, res);
        return res;
    }

    void dfs(vector<int> &candidates, int target, int start, vector<int> &comb,
             vector<vector<int>> &res) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            res.push_back(comb);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break;
            }

            comb.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, comb, res);
            comb.pop_back();
        }
    }
};


```