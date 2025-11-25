---
status: Done
difficulty: Easy
algo: Binary Search
group:
  - Others
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Binary Search Problems]]

# Minimum Absolute Difference in BST
## Description 
Given the `root` of a Binary Search Tree (BST), return _the minimum absolute difference between the values of any two different nodes in the tree_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg)

**Input:** `root = [4,2,6,1,3]`
**Output:** 1

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg)

**Input:** `root = [1,0,48,null,null,12,49]`
**Output:** 1

**Constraints:**

- The number of nodes in the tree is in the range `[2, 104]`.
- `0 <= Node.val <= 105`
## Code 
```cpp
class Solution {
private:
    std::priority_queue<int> heap; 
public:
    void dfs(TreeNode *node) {
        if (node == nullptr) {
            return ; 
        }
        heap.push(node->val); 
        dfs(node->left); 
        dfs(node->right); 
        return; 
    }

    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {
            return 0;  
        }    

        dfs(root); 

        int res = INT_MAX; 
        int prev = heap.top(); 
        heap.pop(); 

        while (!heap.empty()) {
            int top = heap.top(); 
            heap.pop(); 
            int diff = prev - top; 
            res = std::min(res, diff);
            prev = top; 
        }

        return res; 
    }
};
```
