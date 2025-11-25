---
status: Done
difficulty: Easy
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

#  Binary Tree Paths
## Description 
Given the `root` of a binary tree, return _all root-to-leaf paths in **any order**_.

A **leaf** is a node with no children.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/12/paths-tree.jpg)

**Input:** `root = [1,2,3,null,5]`
**Output:** `["1->2->5","1->3"]`

**Example 2:**

**Input:** `root = [1]`
**Output:** `["1"]`

**Constraints:**

- The number of nodes in the tree is in the range `[1, 100]`.
- `-100 <= Node.val <= 100`
## Code 
```cpp
class Solution {
  public:
    void dfs(TreeNode *node, std::string path, std::vector<std::string> &res) {
        if (!node) {
            return;
        }
        if (path == "") {
            path = std::to_string(node->val);
        } else {
            path = path + "->" + std::to_string(node->val);
        }
        if (node->left == nullptr && node->right == nullptr) {
            res.push_back(path);
            return;
        }
        dfs(node->left, path, res);
        dfs(node->right, path, res);
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        std::vector<std::string> res;
        if (!root) {
            return res;
        }
        dfs(root, "", res);
        return res;
    }
};

```