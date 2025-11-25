---
status: Done
difficulty: Medium
algo: Binary Search
group:
  - Others
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Binary Search Problems]]

# Find First and Last Position of Element in Sorted Array
## Description 
Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

**Input:** `nums = [5,7,7,8,8,10], target = 8`
**Output:** `[3,4]`

**Example 2:**

**Input:** `nums = [6,7,7,8,8,10], target = 6`
**Output:** `[-1,-1]`

**Example 3:**

**Input:** `nums = [], target = 0`
**Output:** `[-1,-1]`

**Constraints:**

- `0 <= nums.length <= 105`
- `-109 <= nums[i] <= 109`
- `nums` is a non-decreasing array.
- `-109 <= target <= 109`
## Code 
```cpp
class Solution {
private:

    int findFirst(const std::vector<int>& nums, int target) {
        int index = -1;
        int start = 0;
        int end = static_cast<int>(nums.size()) - 1; 
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target) {
                    index = mid; 
                }
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return index;
    }

    int findLast(const std::vector<int>& nums, int target) {
        int index = -1;
        int start = 0;
        int end = static_cast<int>(nums.size()) - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] <= target) {
               
                if (nums[mid] == target) {
                    index = mid; 
                }
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return index;
    }

public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        int start_index = findFirst(nums, target);

        if (start_index == -1) {
            return {-1, -1};
        }

        int end_index = findLast(nums, target);

        return {start_index, end_index};
    }
};
```
