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
[[PG_Depth First Search (DFS) - Recursive Problems]]

# Sum Root to Leaf Numbers 
## Description 
Return _the total sum of all root-to-leaf numbers_. Test cases are generated so that the answer will fit in a **32-bit** integer.

A **leaf** node is a node with no children.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/num1tree.jpg)
```
**Input:** root = [1,2,3]
**Output:** 25
```
**Explanation:**
The root-to-leaf path `1->2` represents the number `12`.
The root-to-leaf path `1->3` represents the number `13`.
Therefore, sum = 12 + 13 = `25`.

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/02/19/num2tree.jpg)

```
**Input:** root = [4,9,0,5,1]
**Output:** 1026
```
**Explanation:**
The root-to-leaf path `4->9->5` represents the number 495.
The root-to-leaf path `4->9->1` represents the number 491.
The root-to-leaf path `4->0` represents the number 40.
Therefore, sum = 495 + 491 + 40 = `1026`.

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `0 <= Node.val <= 9`
- The depth of the tree will not exceed `10`.
## Code 
```cpp
class Solution {
  private:
    int res;

  public:
    void rootToLeafSum(std::vector<int> &currPath) {
        int n = currPath.size();
        int sum = 0;
        std::vector<int> copy(currPath.begin(), currPath.end());
        for (int i = 0; i < n; i++) {
            int val = copy.back();
            copy.pop_back();
            sum += val * std::pow(10, i);
        }
        res += sum;
    }
    void backtrack(TreeNode *node, std::vector<int> &currPath) {
        if (node == nullptr) {
            return;
        }
        currPath.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            rootToLeafSum(currPath);
        }
        if (node->left != nullptr) {
            backtrack(node->left, currPath);
        }
        if (node->right != nullptr) {
            backtrack(node->right, currPath);
        }
        currPath.pop_back();
    }

    int sumNumbers(TreeNode *root) {
        std::vector<int> currPath;
        backtrack(root, currPath);
        return res;
    }
};
```