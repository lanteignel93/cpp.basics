---
status: Done
difficulty: Easy
algo: Fast and Slow Pointer
group:
  - Linked List
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Fast and Slow Pointers]]

# Linked List Cycle Detection
## Description 
Given the `head` of a singly linked list, return _the middle node of the linked list_.

If there are two middle nodes, return **the second middle** node.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist1.jpg)

**Input:** `head = [1,2,3,4,5]`
**Output:** `[3,4,5]`
**Explanation:** The middle node of the list is node 3.

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/07/23/lc-midlist2.jpg)

**Input:** head = `[1,2,3,4,5,6]`
**Output:** `[4,5,6]`
**Explanation:** Since the list has two middle nodes with values 3 and 4, we return the second one.

**Constraints:**

- The number of nodes in the list is in the range `[1, 100]`.
- `1 <= Node.val <= 100`
## Code 
```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slowPtr = head; 
        ListNode *fastPtr = head; 

        while (fastPtr && fastPtr->next != nullptr) {
            slowPtr = slowPtr->next; 
            fastPtr = fastPtr->next->next;
        }
        return slowPtr;
    }
};
```
