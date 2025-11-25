---
status: Done
difficulty: Easy
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

# Path Sum
## Description 
Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

A **leaf** is a node with no children.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg)
```
**Input:** root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
**Output:** true
**Explanation:** The root-to-leaf path with the target sum is shown.

```
**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

```
**Input:** root = [1,2,3], targetSum = 5
**Output:** false
**Explanation:** There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

```
**Example 3:**

```
**Input:** root = [], targetSum = 0
**Output:** false
**Explanation:** Since the tree is empty, there are no root-to-leaf paths.
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`
## Code 
```cpp
class Solution {
  public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }
        std::queue<std::pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto val = q.front();
            q.pop();
            TreeNode *currNode = val.first;
            int currSum = val.second;
            currSum += currNode->val;
            if (currSum == targetSum && currNode->left == nullptr &&
                currNode->right == nullptr) {
                return true;
            }
            if (currNode->left != nullptr) {
                q.push({currNode->left, currSum});
            }
            if (currNode->right != nullptr) {
                q.push({currNode->right, currSum});
            }
        }
        return false;
    }
};
```

### DFS
```cpp
class Solution {
  private:
    bool res = false;

  public:
    void dfs(TreeNode *node, int currSum, int targetSum) {
        if (!node) {
            return;
        }
        currSum += node->val;
        if (currSum == targetSum && node->left == nullptr &&
            node->right == nullptr) {
            res = true;
        }
        dfs(node->left, currSum, targetSum);
        dfs(node->right, currSum, targetSum);
    }
    bool hasPathSum(TreeNode *root, int targetSum) {
        int currSum = 0;
        dfs(root, currSum, targetSum);
        return res;
    }
};
```