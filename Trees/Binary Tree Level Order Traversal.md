---
status: Done
difficulty: Medium
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

# Binary Tree Level Traversala
## Description 
Given a binary tree `root`, return the level order traversal of it as a nested list, where each sublist contains the values of nodes at a particular level in the tree, from left to right.

**Example 1:**

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/a4639809-0754-4eda-221f-a4cd58bd9c00/public)

```java
Input: root = [1,2,3,4,5,6,7]

Output: [[1],[2,3],[4,5,6,7]]
```

**Example 2:**

```java
Input: root = [1]

Output: [[1]]
```

**Example 3:**

```java
Input: root = []

Output: []
```

**Constraints:**

- `0 <= The number of nodes in the tree <= 1000`.
- `-1000 <= Node.val <= 1000`
- 
## Code 
```cpp
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res; 
        if (!root) {
            return res; 
        }
        std::queue<TreeNode*> q; 
        q.push(root); 

        while (!q.empty()) {
            std::vector<int> level_arr;
            int size = static_cast<int>(q.size());  
            for (int i=0; i < size; ++i) {
                TreeNode *currNode = q.front(); q.pop(); 
                level_arr.push_back(currNode->val); 
                if (currNode->left){
                    q.push(currNode->left);
                }
                if (currNode->right) {
                    q.push(currNode->right); 
                }
            }
            res.push_back(level_arr);
        }
        return res; 
    }
};
```