---
status: Done
difficulty: Easy
algo: DFS - Recursive
group:
  - Trees
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Depth First Search (DFS) - Recursive Problems]]

# Subtree of Another Tree
## Description 
Given the roots of two binary trees `root` and `subRoot`, return `true` if there is a subtree of `root` with the same structure and node values of `subRoot` and `false` otherwise.

A subtree of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree `tree` could also be considered as a subtree of itself.

**Example 1:**

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/2991a77a-9664-46ed-528d-019e392f7400/public)

```java
Input: root = [1,2,3,4,5], subRoot = [2,4,5]

Output: true
```

**Example 2:**

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/ae6114cb-23a0-457f-c441-0a82b7a58500/public)

```java
Input: root = [1,2,3,4,5,null,null,6], subRoot = [2,4,5]

Output: false
```

**Constraints:**

- `1 <= The number of nodes in both trees <= 100`.
- `-100 <= root.val, subRoot.val <= 100`
## Code 
```cpp
class Solution {
  public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr) {
            return false;
        }
        if (subRoot == nullptr) {
            return true;
        }
        if (isSameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
```