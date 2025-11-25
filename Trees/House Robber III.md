---
status: Done
difficulty: Medium
algo: DFS - Recursive
group:
  - Trees
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Depth First Search (DFS) - Recursive Problems]]

# House Robber III
## Description 
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called `root`.

Besides the `root`, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if **two directly-linked houses were broken into on the same night**.

Given the `root` of the binary tree, return _the maximum amount of money the thief can rob **without alerting the police**_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/10/rob1-tree.jpg)
```
**Input:** root = [3,2,3,null,3,null,1]
**Output:** 7
**Explanation:** Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/10/rob2-tree.jpg)

```
**Input:** root = [3,4,5,1,3,null,1]
**Output:** 9
**Explanation:** Maximum amount of money the thief can rob = 4 + 5 = 9.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `0 <= Node.val <= 104`
## Code 
```cpp
class Solution {
  private:
    unordered_map<TreeNode *, int> dp;

  public:
    int rob(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        if (dp.count(root)) {
            return dp[root];
        }
        int ans = 0;

        if (root->left) {
            ans += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            ans += rob(root->right->left) + rob(root->right->right);
        };
        dp[root] = max(ans + root->val, rob(root->left) + rob(root->right));

        return dp[root];
    }
};

```