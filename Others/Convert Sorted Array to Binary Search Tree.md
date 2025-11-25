---
status: Done
difficulty: Easy
algo: Binary Search
group:
  - Others
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Binary Search Problems]]

# Convert Sorted Array to Binary Search Tree]
## Description 
Given an integer array `nums` where the elements are sorted in **ascending order**, convert _it to a_

_binary search tree_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg)

**Input:** `nums = [-10,-3,0,5,9]`
**Output:** `[0,-3,9,-10,null,5]`
**Explanation:** `[0,-10,5,null,-3,null,9]` is also accepted:
![](https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg)

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/02/18/btree.jpg)

**Input:** `nums = [1,3]`
**Output:** `[3,1]`
**Explanation:** `[1,null,3] and [3,1] are both height-balanced BSTs.`

**Constraints:**

- `1 <= nums.length <= 104`
- `-104 <= nums[i] <= 104`
- `nums` is sorted in a **strictly increasing** order.
## Code 
```cpp
class Solution {
public:
    TreeNode* buildTree(std::vector<int> &nums, int start, int end) {
        if (start > end) {
            return nullptr; 
        }

        int mid = start + (end - start) / 2; 

        TreeNode *root = new TreeNode(nums[mid]); 
        root->left = buildTree(nums, start, mid - 1); 
        root->right = buildTree(nums, mid + 1, end); 

        return root; 
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr; 
        }
        int n = static_cast<int>(nums.size()); 
        return buildTree(nums, 0, n-1); 
    }
};
```
