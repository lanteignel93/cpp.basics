---
status: Done
difficulty: Easy
algo: BFS
group:
  - Trees
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Breath First Search Problems]]

# Average of Levels in Binary Tree
## Description 
Given the `root` of a binary tree, return _the average value of the nodes on each level in the form of an array_. Answers within `10-5` of the actual answer will be accepted.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/09/avg1-tree.jpg)
```
**Input:** root = [3,9,20,null,null,15,7]
**Output:** [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/09/avg2-tree.jpg)

```
**Input:** root = [3,9,20,15,7]
**Output:** [3.00000,14.50000,11.00000]
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `-231 <= Node.val <= 231 - 1`
## Code 
```cpp
class Solution {
  public:
    vector<double> averageOfLevels(TreeNode *root) {
        std::vector<double> res;
        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int length = q.size();
            double levelSum{0.0};

            for (int i = 0; i < length; ++i) {
                TreeNode *currNode = q.front();
                q.pop();
                levelSum += static_cast<double>(currNode->val);
                if (currNode->left) {
                    q.push(currNode->left);
                }
                if (currNode->right) {
                    q.push(currNode->right);
                }
            }
            res.push_back(levelSum / static_cast<double>(length));
        }
        return res;
    }
};
```