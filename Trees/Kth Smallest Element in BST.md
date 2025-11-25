---
status: Done
difficulty: Medium
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
[[PG_Depth First Search (DFS) - Recursive Problems]]]

# Kth Smallest Element in BST
## Description 
- The left subtree of every node contains only nodes with keys **less than** the node's key.
- The right subtree of every node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees are also binary search trees.

**Example 1:**

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/02eca3db-f72f-4277-7134-faec4f02e500/public)

```java
Input: root = [2,1,3], k = 1

Output: 1
```

**Example 2:**

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/dca6c42d-2327-4036-f7f2-3e99d8203100/public)

```java
Input: root = [4,3,5,2,null], k = 4

Output: 5
```

**Constraints:**

- `1 <= k <= The number of nodes in the tree <= 1000`.
- `0 <= Node.val <= 1000`
## Code 
```cpp
class Solution {
  private:
    std::priority_queue<int> maxHeap;

  public:
    void dfs(TreeNode *root, int k) {
        if (root == nullptr) {
            return;
        }

        dfs(root->left, k);
        dfs(root->right, k);
        maxHeap.push(root->val);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
        return;
    }
    int kthSmallest(TreeNode *root, int k) {
        if (root == nullptr) {
            return 0;
        }

        dfs(root, k);
        return maxHeap.top();
    }
};

```