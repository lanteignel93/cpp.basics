---
status: Done
difficulty: Medium
algo: DFS - Recursive
group:
  - Trees
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Depth First Search (DFS) - Recursive Problems]]

# Balance a Binary Search Tree
## Description 
Given the `root` of a binary search tree, return _a **balanced** binary search tree with the same node values_. If there is more than one answer, return **any of them**.

A binary search tree is **balanced** if the depth of the two subtrees of every node never differs by more than `1`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/08/10/balance1-tree.jpg)
```
**Input:** root = [1,null,2,null,3,null,4,null,null]
**Output:** [2,1,3,null,null,null,4]
**Explanation:** This is not the only correct answer, [3,1,4,null,2] is also correct.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/08/10/balanced2-tree.jpg)

```
**Input:** root = [2,1,3]
**Output:** [2,1,3]
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `1 <= Node.val <= 105`
## Code 
```cpp
class Solution {
  public:
    void inorder(TreeNode *root, std::vector<int> &nums) {
        if (root == nullptr)
            return;

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
        return;
    }

    TreeNode *build(int left, int right, std::vector<int> &nums) {
        if (left > right)
            return nullptr;

        if (left == right)
            return new TreeNode(nums[left]);

        int mid = left + (right - left) / 2;

        TreeNode *node = new TreeNode(nums[mid]);

        node->left = build(left, mid - 1, nums);
        node->right = build(mid + 1, right, nums);

        return node;
    }
    TreeNode *balanceBST(TreeNode *root) {
        std::vector<int> nums;

        inorder(root, nums);
        return build(0, nums.size() - 1, nums);
    }
};
```