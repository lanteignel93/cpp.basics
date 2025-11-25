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

# Minimum Distance Between BST Nodes
## Description 
Given the `root` of a Binary Search Tree (BST), return _the minimum difference between the values of any two different nodes in the tree_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg)

**Input:** `root = [4,2,6,1,3]`
**Output:** `1`

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg)

**Input:** `root = [1,0,48,null,null,12,49]`
**Output:** `1`

**Constraints:**

- The number of nodes in the tree is in the range `[2, 100]`.
- `0 <= Node.val <= 105`
## Code 
```cpp
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        std::priority_queue<int> heap; 
        std::queue<TreeNode *> q; 
        q.push(root);

        while(!q.empty()) {
            TreeNode * currNode = q.front(); q.pop();
            if (currNode) {
                heap.push(currNode->val); 
                q.push(currNode->left); 
                q.push(currNode->right);
            } 
        }
        int res = INT_MAX; 
        int prev = heap.top(); 
        heap.pop();
        while (!heap.empty()) {
            int curr = heap.top(); heap.pop(); 
            res = std::min(res, prev - curr); 
            prev = curr; 
         }
         return res; 
    }
};
```
