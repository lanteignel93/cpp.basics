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

# Partition List 
## Description 
Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.

You should **preserve** the original relative order of the nodes in each of the two partitions.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/04/partition.jpg)

**Input:** `head = [1,4,3,2,5,2], x = 3`
**Output:** `[1,2,2,4,3,5]`

**Example 2:**

**Input:** `head = [2,1], x = 2`
**Output:** `[1,2]`


**Constraints:**

- `1 <= Length of the list <= 1000`.
- `-1000 <= Node.val <= 1000`
- `index` is `-1` or a valid index in the linked list.
## Code 
```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode smallList { 0 }; 
        ListNode* smallPtr = &smallList; 

        ListNode bigList { 0 }; 
        ListNode* bigPtr = &bigList; 

        ListNode *currNode = head; 
        while (currNode != nullptr) {
            ListNode* nextNode = currNode->next; 
        
            if (currNode->val < x) {
                smallPtr->next = currNode; 
                smallPtr = smallPtr->next; 
            } else {
                bigPtr->next = currNode; 
                bigPtr = bigPtr->next; 
            }
            currNode->next = nullptr; 
            
            currNode = nextNode; 
        }
        smallPtr->next = bigList.next;
        return smallList.next; 
    }
};
```
