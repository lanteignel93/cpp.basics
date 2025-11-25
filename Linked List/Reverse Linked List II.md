---
status: Done
difficulty: Medium
algo: Singly Linked List
group:
  - Linked List
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Singly Linked List]]

# Reverse Linked List II
## Description 
Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return _the reversed list_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg)

**Input:** `head = [1,2,3,4,5], left = 2, right = 4`
**Output:** `[1,4,3,2,5]`

**Example 2:**

**Input:** `head = [5], left = 1, right = 1`
**Output:** `[5]`

**Constraints:**

- The number of nodes in the list is `n`.
- `1 <= n <= 500`
- `-500 <= Node.val <= 500`
- `1 <= left <= right <= n`

**Follow up:** Could you do it in one pass?
## Code 
```cpp
class Solution {
  public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (head->next == nullptr || left == right) {
            return head;
        }

        ListNode dummy{0};
        dummy.next = head;
        ListNode *prev = &dummy;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode *start_reversal = prev->next;
        ListNode *curr = start_reversal;
        ListNode *next = nullptr;

        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};
```
