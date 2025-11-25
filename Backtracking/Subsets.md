---
status: Done
difficulty: Medium
algo: Backtracking
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
[[PG_Backtracking Problems]]

# Subsets
## Description 
Given an integer array `nums` of **unique** elements, return _all possible_ _subsets_ _(the power set)_.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

**Example 1:**

**Input:** `nums = [1,2,3]`
**Output:** `[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]`

**Example 2:**

**Input:** `nums = [0]`
**Output:** `[[],[0]]`

**Constraints:**

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`
- All the numbers of `nums` are **unique**.
## Code 
```cpp
class Solution {
public:
    void dfs(int k, std::vector<int> &path, std::vector<int> &nums, std::vector<std::vector<int>> &res) {
        if (k == nums.size()) {
            res.push_back(path); 
            return;
        }

        
        path.push_back(nums[k]); 
        dfs(k + 1, path, nums, res); 
        path.pop_back(); 
        dfs(k + 1, path, nums, res); 

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> res; 
        std::vector<int> path; 
        dfs(0, path, nums, res); 
        return res; 
    }
};
```