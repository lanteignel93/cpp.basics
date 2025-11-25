---
status: Done
difficulty: Hard
algo: Merge Sort
group:
  - Sorting
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Merge Sort Problems]]

# Merge K Sorted List
## Description 
You are given an array of `k` linked lists `lists`, where each list is sorted in ascending order.

Return the **sorted** linked list that is the result of merging all of the individual linked lists.

**Example 1:**

```java
Input: lists = [[1,2,4],[1,3,5],[3,6]]

Output: [1,1,2,3,3,4,5,6]
```

**Example 2:**

```java
Input: lists = []

Output: []
```

**Example 3:**

```java
Input: lists = [[]]

Output: []
```

**Constraints:**

- `0 <= lists.length <= 1000`
- `0 <= lists[i].length <= 100`
- `-1000 <= lists[i][j] <= 1000`
## Code 
```cpp
class Solution {
private: 
    ListNode* divide(std::vector<ListNode*> &list, int left, int right) {
        if (left > right) {
            return nullptr; 
        }
        if (left == right) {
            return list[left];
        }

        int mid = left + (right - left) / 2; 

        ListNode* l = divide(list, left, mid); 
        ListNode* r = divide(list, mid + 1, right); 

        return conquer(l, r); 
    }

    ListNode* conquer(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); 
        ListNode *currNode = &dummy; 

        while (l1 && l2) {
            if (l1->val <= l2->val){
                currNode->next = l1; 
                l1 = l1->next; 
            } else {
                currNode->next = l2; 
                l2 = l2->next;
            }
            currNode = currNode->next;
        }

        while (l1 != nullptr) {
            currNode->next = l1; 
            l1 = l1->next; 
            currNode = currNode->next; 
        }

        while (l2 != nullptr) {
            currNode->next = l2; 
            l2 = l2->next; 
            currNode = currNode->next; 
        }

        return dummy.next; 
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr; 
        }
        return divide(lists, 0, lists.size() - 1); 
    }

};
```
