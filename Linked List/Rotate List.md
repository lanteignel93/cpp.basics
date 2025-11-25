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

# Rotate List
## Description 
Given the `head` of a linked list, rotate the list to the right by `k` places.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg)

**Input:** `head = [1,2,3,4,5], k = 2`
**Output:** `[4,5,1,2,3]`

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg)

**Input:** `head = [0,1,2], k = 4`
**Output:** `[2,0,1]`

**Constraints:**

- The number of nodes in the list is in the range `[0, 500]`.
- `-100 <= Node.val <= 100`
- `0 <= k <= 2 * 109`
## Code 
```cpp
class Solution {
  public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || head->next == nullptr) {
            return head;
        }
        int length{1};
        ListNode *dummy = head;
        while (head->next != nullptr) {
            length++;
            head = head->next;
        }
        head->next = dummy;
        head = dummy;

        int moveLeft = length - (k % length);

        while (moveLeft > 0) {
            head = head->next;
            moveLeft--;
        }
        ListNode *res = head;
        for (int i = 0; i < (length - 1); i++) {
            head = head->next;
        }
        head->next = nullptr;
        return res;
    }
};
```
