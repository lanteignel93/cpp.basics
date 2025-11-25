---
status: Done
difficulty: Medium
algo: Singly Linked List
group:
  - Linked List
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Singly Linked List]]

# Swap Nodes in Pairs
## Description 
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

**Example 1:**

**Input:** head = [1,2,3,4]

**Output:** [2,1,4,3]

**Explanation:**

![](https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg)

**Example 2:**

**Input:** `head = []`

**Output:** `[]`

**Example 3:**

**Input:** `head = [1]`

**Output:** `[1]`

**Example 4:**

**Input:** `head = [1,2,3]`

**Output:** `[2,1,3]`

**Constraints:**

- The number of nodes in the list is in the range `[0, 100]`.
- `0 <= Node.val <= 100`
## Code 
```cpp
class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode dummy{0};
        dummy.next = head;
        ListNode *prev = &dummy;

        while (head && head->next) {
            ListNode *next = head->next->next;

            ListNode *swap = head->next;
            swap->next = head;
            prev->next = swap;
            head->next = next;

            prev = head;
            head = next;
        }
        return dummy.next;
    }
};

```
