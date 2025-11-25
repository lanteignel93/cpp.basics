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

# Remove Node From End of Linked List 
## Description 
You are given the beginning of a linked list `head`, and an integer `n`.

Remove the `nth` node from the end of the list and return the beginning of the list.

**Example 1:**

```java
Input: head = [1,2,3,4], n = 2

Output: [1,2,4]
```

**Example 2:**

```java
Input: head = [5], n = 1

Output: []
```

**Example 3:**

```java
Input: head = [1,2], n = 2

Output: [2]
```

**Constraints:**

- The number of nodes in the list is `sz`.
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`
## Code 
```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(0, head);
        ListNode* dummy = res;

        for (int i = 0; i < n; i++) {
            head = head->next;
        }

        while (head != nullptr) {
            head = head->next;
            dummy = dummy->next;
        }

        dummy->next = dummy->next->next;

        ListNode* result = res->next;
        delete res;
        return result;        
    }
};
```

