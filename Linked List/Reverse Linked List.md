---
status: Done
difficulty: Easy
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

# Reverse Linked List
## Description 
Given the beginning of a singly linked list `head`, reverse the list, and return the new beginning of the list.

**Example 1:**

```java
Input: head = [0,1,2,3]

Output: [3,2,1,0]
```

**Example 2:**

```java
Input: head = []

Output: []
```

**Constraints:**

- `0 <= The length of the list <= 1000`.
- `-1000 <= Node.val <= 1000`
## Code 
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;  
        while (head != nullptr) {
            ListNode* next = head->next; 
            head->next = prev; 
            prev = head; 
            head = next; 
        }
        return prev;
    }
};
```
