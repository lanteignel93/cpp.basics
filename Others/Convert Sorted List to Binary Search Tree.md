---
status: Done
difficulty: Medium
algo: Binary Search
group:
  - Others
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Binary Search Problems]]

# Convert Sorted List to Binary Search Tree
## Description 
Given the `head` of a singly linked list where elements are sorted in **ascending order**, convert _it to a_

_binary search tree_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/08/17/linked.jpg)

**Input:** `head = [-10,-3,0,5,9]`
**Output:** `[0,-3,9,-10,null,5]`
**Explanation:** One possible answer is `[0,-3,9,-10,null,5]`, which represents the shown height balanced BST.

**Example 2:**

**Input:** `head = []`
**Output:** `[]`

**Constraints:**

- The number of nodes in `head` is in the range `[0, 2 * 104]`.
- `-105 <= Node.val <= 105`
## Code 
```cpp
class Solution {
public:
    TreeNode* convertToBST(ListNode* start, ListNode* end){
            if(start == end) return nullptr;
            ListNode* slow = start;
            ListNode* fast = start;

            while(fast!=end && fast->next!=end){
                slow = slow->next;
                fast = fast->next->next;
            }

            TreeNode* head = new TreeNode(slow->val);
            head->left = convertToBST(start, slow);
            head->right = convertToBST(slow->next, end);
            return head;
        }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) {
            return nullptr; 
        }
        return convertToBST(head, nullptr);
    }
};
```
