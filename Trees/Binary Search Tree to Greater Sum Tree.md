---
status: Done
difficulty: Medium
algo: DFS - Recursive
group:
  - Trees
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Depth First Search (DFS) - Recursive Problems]]

# Binary Search Tree to Greater Sum Tree
## Description 
Given the `root` of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a _binary search tree_ is a tree that satisfies these constraints:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/05/02/tree.png)
```
**Input:** root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
**Output:** [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

**Example 2:**

**Input:** root = [0,null,1]
**Output:** [1,null,1]

**Constraints:**

- The number of nodes in the tree is in the range `[1, 100]`.
- `0 <= Node.val <= 100``
```
## Code 
```cpp
class Solution {
  public:
    void dfs(TreeNode *root, std::vector<int> &val) {
        if (root == nullptr)
            return;

        val.push_back(root->val);
        dfs(root->left, val);
        dfs(root->right, val);
        return;
    }

    void modifyTree(TreeNode *root, const std::vector<int> &suffix) {
        if (root == nullptr)
            return;

        root->val += (suffix[root->val] - root->val);
        modifyTree(root->left, suffix);
        modifyTree(root->right, suffix);
        return;
    }

    TreeNode *bstToGst(TreeNode *root) {
        std::vector<int> vals;
        dfs(root, vals);

        std::sort(vals.begin(), vals.end());
        std::vector<int> suffix(102, 0);

        for (int i = vals.size() - 1; i >= 0; i--) {
            suffix[vals[i]] += vals[i];
        }

        for (int i = 100; i >= 0; i--) {
            suffix[i] += suffix[i + 1];
        }

        modifyTree(root, suffix);
        return root;
    }
};
```