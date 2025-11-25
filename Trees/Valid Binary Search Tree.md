---
status: Done
difficulty: Medium
algo: Binary Search Tree
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

# Valid Binary Search Tree
## Description 
Given the `root` of a binary tree, return `true` if it is a **valid binary search tree**, otherwise return `false`.

A **valid binary search tree** satisfies the following constraints:

- The left subtree of every node contains only nodes with keys **less than** the node's key.
- The right subtree of every node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees are also binary search trees.

**Example 1:**

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/18f9a316-8dc2-4e11-d304-51204454ac00/public)

```java
Input: root = [2,1,3]

Output: true
```

**Example 2:**

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/6f14cb8d-efad-4221-2beb-fba2b19c8a00/public)

```java
Input: root = [1,2,3]

Output: false
```

Explanation: The root node's value is 1 but its left child's value is 2 which is greater than 1.

**Constraints:**

- `1 <= The number of nodes in the tree <= 1000`.
- `-1000 <= Node.val <= 1000``
## Code 
```cpp
class Solution {
  private:
    // Pass the range (min_bound and max_bound) that the current node's value
    // must respect.
    bool dfs(TreeNode *node, long long min_bound, long long max_bound) {
        if (node == nullptr) {
            return true;
        }

        // Check if the current node's value violates the global bounds
        if (node->val <= min_bound || node->val >= max_bound) {
            return false;
        }

        // Recursively check the left subtree:
        // The max_bound becomes the current node's value. The min_bound remains
        // the same.
        bool is_left_valid = dfs(node->left, min_bound, node->val);

        // Recursively check the right subtree:
        // The min_bound becomes the current node's value. The max_bound remains
        // the same.
        bool is_right_valid = dfs(node->right, node->val, max_bound);

        return is_left_valid && is_right_valid;
    }

  public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        // Initial call uses the widest possible range (long long MIN/MAX)
        return dfs(root, std::numeric_limits<long long>::min(),
                   std::numeric_limits<long long>::max());
    }
};

```

### BFS Solution 
```cpp
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0; 
        }
        int res = 0; 
        std::queue<std::pair<TreeNode*, bool>> q; 
        q.push({root, false}); 

        while(!q.empty()) {
            auto curr = q.front(); q.pop(); 
            TreeNode *currNode = curr.first; 
            bool isleft = curr.second; 

            if(!currNode->left && !currNode->right && isleft) {
                res += currNode->val; 
            }
            if (currNode->left) {
                q.push({currNode->left, true}); 
            }
            if (currNode->right) {
                q.push({currNode->right, false}); 
            }
        }
        return res; 
    }

};
```