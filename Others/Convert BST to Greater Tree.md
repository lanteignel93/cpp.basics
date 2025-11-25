---
status: Done
difficulty: Medium
algo: Binary Search
group:
  - Others
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Binary Search Problems]]

# Convert BST to Greater Tree
## Description 
Given the `root` of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a _binary search tree_ is a tree that satisfies these constraints:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/05/02/tree.png)

**Input:** `root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]`
**Output:** `[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]`

**Example 2:**

**Input:** `root = [0,null,1]`
**Output:** `[1,null,1]`

**Constraints:**

- The number of nodes in the tree is in the range `[0, 104]`.
- `-104 <= Node.val <= 104`
- All the values in the tree are **unique**.
- `root` is guaranteed to be a valid binary search tree.
## Code 
```cpp
class Solution {
private:
    int sum {0};
public:
    void dfs(TreeNode *node) {
        if (!node) return; 
        dfs(node->right);
        node->val += sum; 
        sum = node->val; 
        dfs(node->left); 
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};
```
