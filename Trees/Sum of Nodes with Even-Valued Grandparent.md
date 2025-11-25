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

# Sum of Nodes with Even-Valued Grandparent
## Description 
Given the `root` of a binary tree, return _the sum of values of nodes with an **even-valued grandparent**_. If there are no nodes with an **even-valued grandparent**, return `0`.

A **grandparent** of a node is the parent of its parent if it exists.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/08/10/even1-tree.jpg)

**Input:** `root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]`
**Output:** `18`
**Explanation:** The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/08/10/even2-tree.jpg)

**Input:** `root = [1]`
**Output:** `0`

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `1 <= Node.val <= 100`
## Code 
```cpp
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            // Condition
            if (temp->val % 2 == 0) {
                if (temp->left != NULL) {
                    if (temp->left->left != nullptr) sum += temp->left->left->val;
                    if (temp->left->right != nullptr) sum += temp->left->right->val;
                }

                if(temp->right != nullptr){
                    if(temp->right->left != nullptr) sum += temp->right->left->val;
                    if(temp->right->right != nullptr) sum += temp->right->right->val;
                }
            }

            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);
        }

        return sum;
    }
};
```