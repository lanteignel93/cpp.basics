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

# Minimum Depth of a Binary Tree
## Description 
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

**Note:** A leaf is a node with no children.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/12/ex_depth.jpg)
```
**Input:** root = [3,9,20,null,null,15,7]
**Output:** 2

**Example 2:**

**Input:** root = [2,null,3,null,4,null,5,null,6]
**Output:** 5
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 105]`.
- `-1000 <= Node.val <= 1000`
## Code 
```cpp
class Solution {
  public:
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }

        std::queue<TreeNode *> q;
        q.push(root);

        int currHeight = 0;
        while (!q.empty()) {
            currHeight++;
            int length = q.size();
            for (int i = 0; i < length; i++) {
                TreeNode *currNode = q.front();
                q.pop();
                if (currNode->left == nullptr && currNode->right == nullptr) {
                    return currHeight;
                }
                if (currNode->left != nullptr) {
                    q.push(currNode->left);
                }
                if (currNode->right != nullptr) {
                    q.push(currNode->right);
                }
            }
        }
        return currHeight;
    }
};
```
