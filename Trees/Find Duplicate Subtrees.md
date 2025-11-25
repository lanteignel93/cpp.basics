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

# Find Duplicate Subtrees
## Description 
Given the `root` node of a binary tree, your task is to create a string representation of the tree following a specific set of formatting rules. The representation should be based on a preorder traversal of the binary tree and must adhere to the following guidelines:

- **Node Representation**: Each node in the tree should be represented by its integer value.
    
- **Parentheses for Children**: If a node has at least one child (either left or right), its children should be represented inside parentheses. Specifically:
    
    - If a node has a left child, the value of the left child should be enclosed in parentheses immediately following the node's value.
    - If a node has a right chiGiven the `root` of a binary tree, return all **duplicate subtrees**.

For each kind of duplicate subtrees, you only need to return the root node of any **one** of them.

Two trees are **duplicate** if they have the **same structure** with the **same node values**.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/08/16/e1.jpg)
```
**Input:** root = [1,2,3,4,null,2,4,null,null,4]
**Output:** [[2,4],[4]]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/08/16/e2.jpg)

```
**Input:** root = [2,1,1]
**Output:** [[1]]
```

**Example 3:**

![](https://assets.leetcode.com/uploads/2020/08/16/e33.jpg)

```
**Input:** root = [2,2,2,3,null,3,null]
**Output:** [[2,3],[3]]
```

**Constraints:**

- The number of the nodes in the tree will be in the range `[1, 5000]`
- `-200 <= Node.val <= 200`
## Code 
```cpp
class Solution {

  public:
    std::string encode(TreeNode *root, unordered_map<std::string, int> &count,
                       std::vector<TreeNode *> &res) {
        if (root == nullptr) {
            return "";
        }

        const std::string encoded = std::to_string(root->val) + "#" +
                                    encode(root->left, count, res) + "#" +
                                    encode(root->right, count, res);
        count[encoded]++;
        if (count[encoded] == 2) {
            res.push_back(root);
        }
        return encoded;
    }

    std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        std::vector<TreeNode *> res;
        unordered_map<std::string, int> count;
        encode(root, count, res);
        return res;
    }
};

```