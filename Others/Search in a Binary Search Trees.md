---
status: Done
difficulty: Easy
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

# Search in a Binary Search Tree 
## Description 
You are given the `root` of a binary search tree (BST) and an integer `val`.

Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg)

**Input:** `root = [4,2,7,1,3], val = 2`
**Output:** `[2,1,3]`

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg)

**Input:** `root = [4,2,7,1,3], val = 5`
**Output:** `[]`

**Constraints:**

- The number of nodes in the tree is in the range `[1, 5000]`.
- `1 <= Node.val <= 107`
- `root` is a binary search tree.
- `1 <= val <= 107``
## Code 
```cpp
class Solution {
private:
    TreeNode* res = nullptr; 
public:
    void dfs(TreeNode *node, int val) {
        if (node == nullptr) {
            return; 
        }

        if (node->val == val) {
            res = node; 
        }
        dfs(node->left, val); 
        dfs(node->right, val); 

        return;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        dfs(root, val); 
        return res; 
    }
};
```
