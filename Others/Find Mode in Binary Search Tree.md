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

# Find Mode in Binary Search Tree
## Description 
Given the `root` of a binary search tree (BST) with duplicates, return _all the [mode(s)](https://en.wikipedia.org/wiki/Mode_\(statistics\)) (i.e., the most frequently occurred element) in it_.

If the tree has more than one mode, return them in **any order**.

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys **less than or equal to** the node's key.
- The right subtree of a node contains only nodes with keys **greater than or equal to** the node's key.
- Both the left and right subtrees must also be binary search trees.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/11/mode-tree.jpg)

**Input:** `root = [1,null,2,2]`
**Output:** `[2]`

**Example 2:**

**Input:** `root = [0]`
**Output:** `[0]`

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `-105 <= Node.val <= 105`

**Follow up:** Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
## Code 
```cpp
class Solution {
private:
    int currentVal = 0; 
    int currentCount = 0; 
    int maxCount = 0; 
    std::vector<int> res; 

    void inorder(TreeNode* node) {
        if (node == nullptr) {
            return ; 
        }

        inorder(node->left); 

        if (node->val == currentVal) {
            currentCount++; 
        } else {
            currentVal = node->val; 
            currentCount = 1; 
        }

        if (currentCount > maxCount) {
            maxCount = currentCount; 
            res = {currentVal}; 
        } else if (currentCount == maxCount) {
            res.push_back(currentVal); 
        }
        
        inorder(node->right); 
    }

public:
    std::vector<int> findMode(TreeNode *root) {
        if (root == nullptr) {
            return {}; 
        }
        currentVal = root->val; 
        currentCount = 0; 
        maxCount = 0; 
        res.clear(); 

        inorder(root);

        return res;  
    }
};
```
