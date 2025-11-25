---
status: Done
difficulty: Easy
algo: DFS - Recursive
group:
  - Trees
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Depth First Search (DFS) - Recursive Problems]]]

# Binary Tree Postorder Traversal
## Description 
Given the `root` of a binary tree, return _the postorder traversal of its nodes' values_.

**Example 1:**

**Input:** `root = [1,null,2,3]`

**Output:** `[3,2,1]`

**Explanation:**

![](https://assets.leetcode.com/uploads/2024/08/29/screenshot-2024-08-29-202743.png)

**Example 2:**

**Input:** `root = [1,2,3,4,5,null,8,null,null,6,7,9]`

**Output:** `[4,6,7,5,2,9,8,3,1]`

**Explanation:**

![](https://assets.leetcode.com/uploads/2024/08/29/tree_2.png)

**Example 3:**

**Input:** `root = []`

**Output:** `[]`

**Example 4:**

**Input:** `root = [1]`

**Output:** `[1]`

**Constraints:**

- The number of the nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`
## Code 
```cpp
class Solution {
  private:
    std::vector<int> res;

  public:
    void dfs(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        res.push_back(node->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        dfs(root);
        return res;
    }
};


```