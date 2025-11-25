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

# Sum of Left Leaves 
## Description 
Given the `root` of a binary tree, return _the sum of all left leaves._

A **leaf** is a node with no children. A **left leaf** is a leaf that is the left child of another node.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg)

**Input:** `root = [3,9,20,null,null,15,7]`
**Output:** `24`
**Explanation:** There are two left leaves in the binary tree, with values 9 and 15 respectively.

**Example 2:**

**Input:** `root = [1]`
**Output:** `0`

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `-1000 <= Node.val <= 1000`

**Follow up:** Recursive solution is trivial, could you do it iteratively?
## Code 
```cpp
class Solution {
  private:
    int res{0};

  public:
    void dfs(TreeNode *node, bool left) {
        if (node == nullptr) {
            return;
        }
        dfs(node->left, true);
        if (left && node->left == nullptr && node->right == nullptr) {
            res += node->val;
            return;
        }
        dfs(node->right, false);
        return;
    }
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root, false);

        return res;
    }
};
```