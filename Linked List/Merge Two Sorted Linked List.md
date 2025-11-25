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

# Merge Two Sorted Linked List 
## Description 
You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one **sorted** linked list and return the head of the new sorted linked list.

The new list should be made up of nodes from `list1` and `list2`.

**Example 1:**

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/51adfea9-493a-4abb-ece7-fbb359d1c800/public)

```java
Input: list1 = [1,2,4], list2 = [1,3,5]

Output: [1,1,2,3,4,5]
```

**Example 2:**

```java
Input: list1 = [], list2 = [1,2]

Output: [1,2]
```

**Example 3:**

```java
Input: list1 = [], list2 = []

Output: []
```

**Constraints:**

- `0 <= The length of the each list <= 100`.
- `-100 <= Node.val <= 100`
## Code 
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2; 
        }
        if (list2 == nullptr) {
            return list1; 
        }

        ListNode dummy { 0 }; 
        ListNode* node = &dummy; 
        while (list1!= nullptr && list2!= nullptr) {
            
            if (list1->val <= list2->val) {
                node->next = list1; 
                list1 = list1->next; 
            } else {
                node->next = list2; 
                list2 = list2->next; 
            }
            node = node->next; 
        }

        if(list1) {
            node->next = list1; 
        }
        if(list2) {
            node->next = list2; 
        }
        return dummy.next;
    }
};
```
