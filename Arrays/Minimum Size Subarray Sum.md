---
status: Done
difficulty: Medium
algo: Sliding Window
group:
  - Arrays
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Sliding_Window_Problems]]]

# Minimum Size Subarray Sum 
## Description 
You are given an array of positive integers `nums` and a positive integer `target`, return the **minimal length** of a subarray whose sum is greater than or equal to `target`. If there is no such subarray, return `0` instead.

A **subarray** is a contiguous non-empty sequence of elements within an array.

**Example 1:**

```java
Input: target = 10, nums = [2,1,5,1,5,3]

Output: 3
```

Explanation: The subarray `[5,1,5]` has the minimal length under the problem constraint.

**Example 2:**

```java
Input: target = 5, nums = [1,2,1]

Output: 0
```

**Constraints:**

- `1 <= nums.length <= 100,000`
- `1 <= nums[i] <= 10,000`
- `1 <= target <= 1,000,000,000`

**Follow up:** If you have figured out the `O(n)` solution, try coding another solution of which the time complexity is `O(n log(n))`.
## Code 
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = static_cast<int>(nums.size()); 
        int res = n + 1; 
        int left_ptr = 0; 
        int currSum = 0;

        for (int right_ptr = 0; right_ptr < n; ++right_ptr) {
            currSum += nums[right_ptr];
        
            while (currSum >= target) {
                res = std::min(res, right_ptr - left_ptr + 1);
                currSum -= nums[left_ptr]; 
                left_ptr++; 
            }
        } 
        
        return (res == n + 1) ? 0 : res;
    }
};
```
