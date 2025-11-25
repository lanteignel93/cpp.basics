---
status: Done
difficulty: Easy
algo: BFS
group:
  - Trees
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Breath First Search Problems]]

# Maximum Depth of a Binary Tree
## Description 
Given the `root` of a binary tree, return _its maximum depth_.

A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)
```
**Input:** root = [3,9,20,null,null,15,7]
**Output:** 3

**Example 2:**

**Input:** root = [1,null,2]
**Output:** 2
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 104]`.
- `-100 <= Node.val <= 100`
## Code 
```cpp
class Solution {
  public:
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 1;
        }

        std::queue<TreeNode *> q;
        q.push(root);
        int height = 1;
        while (!q.empty()) {
            height++;
            int length = static_cast<int>(q.size());
            for (int i = 1; i < length; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return height;
    }
};
```
