---
status: Done
difficulty: Medium
algo: Fast and Slow Pointer
group:
  - Linked List
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Fast and Slow Pointers]]

# Maximum Twin Sum of a Linked List

## Description 
In a linked list of size `n`, where `n` is **even**, the `ith` node (**0-indexed**) of the linked list is known as the **twin** of the `(n-1-i)th` node, if `0 <= i <= (n / 2) - 1`.

- For example, if `n = 4`, then node `0` is the twin of node `3`, and node `1` is the twin of node `2`. These are the only nodes with twins for `n = 4`.

The **twin sum** is defined as the sum of a node and its twin.

Given the `head` of a linked list with even length, return _the **maximum twin sum** of the linked list_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/12/03/eg1drawio.png)

**Input:** `head = [5,4,2,1]`
**Output:** `6`
**Explanation:**
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/12/03/eg2drawio.png)

**Input:** `head = [4,2,2,3]`
**Output:** `7`
**Explanation:**
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 

**Example 3:**

![](https://assets.leetcode.com/uploads/2021/12/03/eg3drawio.png)

**Input:** `head = [1,100000]`
**Output:** `100001`
**Explanation:**
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.

**Constraints:**

- The number of nodes in the list is an **even** integer in the range `[2, 105]`.
- `1 <= Node.val <= 105`
## Code 
```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = nullptr; 
        ListNode* currNode = head; 

        while (currNode) {
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode; 
            currNode = nextNode;
        }

        return prevNode; 
    }

    int pairSum(ListNode* head) {
        ListNode *slowPtr = head; 
        ListNode *fastPtr = head; 

        while (fastPtr != nullptr && fastPtr->next != nullptr){
            slowPtr = slowPtr->next; 
            fastPtr = fastPtr->next->next; 
        }

        ListNode *rightNode = reverseList(slowPtr); 
        ListNode *leftNode = head; 

        int res = 0; 

        while (leftNode && rightNode) {
            res = std::max(res, rightNode->val + leftNode->val); 
            leftNode = leftNode->next; 
            rightNode = rightNode->next;
        }

        return res;
    }
};
```
