---
status: Done
difficulty: Medium
algo: Backtracking
group:
  - Backtracking
  - Trees
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Backtracking Problems]]

# Path Sum II
## Description 
Given the `root` of a binary tree and an integer `targetSum`, return _all **root-to-leaf** paths where the sum of the node values in the path equals_ `targetSum`_. Each path should be returned as a list of the node **values**, not node references_.

A **root-to-leaf** path is a path starting from the root and ending at any leaf node. A **leaf** is a node with no children.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg)
```
**Input:** root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
**Output:** [[5,4,11,2],[5,8,4,5]]
```
**Explanation:** There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

```
**Input:** root = [1,2,3], targetSum = 5
**Output:** []
```

**Example 3:**

```
**Input:** root = [1,2], targetSum = 0
**Output:** []
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`
## Code 
```cpp
class Solution {
  public:
    void dfs(TreeNode *node, std::vector<int> &path,
             std::vector<std::vector<int>> &res, int currSum, int &targetSum) {
        if (!node) {
            return;
        }
        currSum += node->val;
        path.push_back(node->val);
        if (currSum == targetSum && node->left == nullptr &&
            node->right == nullptr) {
            res.push_back(path);
        }
        dfs(node->left, path, res, currSum, targetSum);
        dfs(node->right, path, res, currSum, targetSum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        std::vector<std::vector<int>> res;
        if (!root) {
            return res;
        }
        std::vector<int> path;
        int currSum{0};
        dfs(root, path, res, currSum, targetSum);
        return res;
    }
};

```