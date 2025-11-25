---
status: Done
difficulty: Medium
algo: Permutations
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
[[PG_Permutations Problems]]

# Permutations
## Description 
Given an array `nums` of distinct integers, return all the possible. You can return the answer in **any order**.

**Example 1:**
```
**Input:** nums = [1,2,3]
**Output:** [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Example 2:**

```
**Input:** nums = [0,1]
**Output:** [[0,1],[1,0]]
```

**Example 3:**

```
**Input:** nums = [1]
**Output:** [[1]]
```

**Constraints:**

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- All the integers of `nums` are **unique**.
## Code 
```cpp
class Solution {
  public:
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void dfs(std::vector<std::vector<int>> &res, std::vector<int> &nums,
             int k) {
        if (k == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = k; i < nums.size(); ++i) {
            swap(nums[k], nums[i]);
            dfs(res, nums, k + 1);
            swap(nums[k], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        std::vector<std::vector<int>> res;
        dfs(res, nums, 0);
        return res;
    }
};

```