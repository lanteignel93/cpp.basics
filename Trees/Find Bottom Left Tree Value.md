---
status: Done
difficulty: Medium
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

# Find Bottom Left Tree Value
## Description 
Given the `root` of a binary tree, return the leftmost value in the last row of the tree.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/12/14/tree1.jpg)

**Input:** `root = [2,1,3]`
**Output:** `1`

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/12/14/tree2.jpg)

**Input:** `root = [1,2,3,4,null,5,6,null,null,7]`
**Output:** `7`

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `-231 <= Node.val <= 231 - 1`
## Code 
```cpp
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode*> q; 
        q.push(root); 
        int res = 0; 
        while(!q.empty()) {
            int qz = static_cast<int>(q.size()); 
            for (int i = 0; i < qz; ++i) {
                TreeNode *node = q.front(); q.pop(); 

                if (i == 0){
                    res = node->val;
                }
                if (node->left) q.push(node->left); 
                if (node->right) q.push(node->right); 
            }
        }
        return res; 
    }
};
```