---
status: Done
difficulty: Easy
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

# Palindrome Linked List
## Description 
Given the `head` of a singly linked list, return `true` _if it is a_

_or_ `false` _otherwise_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)

**Input:** `head = [1,2,2,1]`
**Output:** `true`

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg)

**Input:** `head = [1,2]`
**Output:** `false`

**Constraints:**

- The number of nodes in the list is in the range `[1, 105]`.
- `0 <= Node.val <= 9`

**Follow up:** Could you do it in `O(n)` time and `O(1)` space?
## Code 
```cpp
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr; 
        ListNode *curr = head; 
        while (curr){
            ListNode *tmp = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = tmp; 
        }
        return prev; 
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next){
            return true;
        }
        
        // Find middle 
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next){
            slow = slow->next; 
            fast = fast->next->next;
        }

        // Reverse the second half
        slow->next = reverseList(slow->next); 
        // Compare first half with reversed second_half
        ListNode *first_half = head; 
        ListNode *second_half = slow->next; 
        while (second_half) {
            if (first_half->val != second_half->val){
                return false;
            }
            first_half = first_half->next; 
            second_half = second_half->next;
        }
        return true;


    }
};
```
