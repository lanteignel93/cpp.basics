---
status: Done
difficulty: Easy
algo: BFS
group:
  - Trees
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Breath First Search Problems]]

# Invert Binary Tree
## Description 
Given the `root` of a binary tree, invert the tree, and return _its root_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)
```
**Input:** root = [4,2,7,1,3,6,9]
**Output:** [4,7,2,9,6,3,1]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg)

```
**Input:** root = [2,1,3]
**Output:** [2,3,1]
```

**Example 3:**
```

**Input:** root = []
**Output:** []

```
**Constraints:**

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`
## Code 
```cpp
class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root) {
            return nullptr;
        }
        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *currNode = q.front();
            q.pop();
            TreeNode *tmp = currNode->left;
            currNode->left = currNode->right;
            currNode->right = tmp;
            if (currNode->left) {
                q.push(currNode->left);
            }
            if (currNode->right) {
                q.push(currNode->right);
            }
        }
        return root;
    }
};
```