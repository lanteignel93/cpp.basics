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

# Find the Duplicate Number
## Description 
You are given an array of integers `nums` containing `n + 1` integers. Each integer in `nums` is in the range `[1, n]` inclusive.

Every integer appears **exactly once**, except for one integer which appears **two or more times**. Return the integer that appears more than once.

**Example 1:**

```java
Input: nums = [1,2,3,2,2]

Output: 2
```

**Example 2:**

```java
Input: nums = [1,2,3,4,4]

Output: 4
```

Follow-up: Can you solve the problem **without** modifying the array `nums` and using O(1)O(1) extra space?

**Constraints:**

- `1 <= n <= 10000`
- `nums.length == n + 1`
- `1 <= nums[i] <= n`
## Code 
```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0]; 
        int fast = nums[0]; 

        while (true) {
            slow = nums[slow]; 
            fast = nums[nums[fast]]; 

            if(slow == fast) {
                break; 
            }
        }
        int slow2 = nums[0]; 

        while (slow != slow2) {
            slow = nums[slow]; 
            slow2 = nums[slow2]; 
        }
        return slow; 
    }
};
```
