---
status: Done
difficulty: Medium
algo: Queues
group:
  - Stacks & Queues
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Queues_Problems]]]

# Continuous Subarrays
## Description 
You are given a **0-indexed** integer array `nums`. A subarray of `nums` is called **continuous** if:

- Let `i`, `i + 1`, ..., `j` be the indices in the subarray. Then, for each pair of indices `i <= i1, i2 <= j`, `0 <= |nums[i1] - nums[i2]| <= 2`.

Return _the total number of **continuous** subarrays._

A subarray is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**
```
**Input:** nums = [5,4,2,4]
**Output:** 8
**Explanation:** 
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
There are no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.
```

**Example 2:**
```

**Input:** nums = [1,2,3]
**Output:** 6
**Explanation:** 
Continuous subarray of size 1: [1], [2], [3].
Continuous subarray of size 2: [1,2], [2,3].
Continuous subarray of size 3: [1,2,3].
Total continuous subarrays = 3 + 2 + 1 = 6.
```

**Constraints:**

- `1 <= nums.length <= 105`
- `1 <= nums[i] <= 109`
## Code 
```cpp
class Solution {
  public:
    long long continuousSubarrays(std::vector<int> &nums) {
        int left = 0;
        long long res = 0;
        // Deques store INDICES
        std::deque<int> minD, maxD;

        for (int right = 0; right < nums.size(); right++) {

            // 1. Maintain Monotonic Deques (add current index 'right')
            while (!minD.empty() && nums[minD.back()] >= nums[right]) {
                minD.pop_back();
            }
            minD.push_back(right);

            while (!maxD.empty() && nums[maxD.back()] <= nums[right]) {
                maxD.pop_back();
            }
            maxD.push_back(right);

            // 2. Shrink Window Condition Check
            while (nums[maxD.front()] - nums[minD.front()] > 2) {

                // CRITICAL CORRECTION: Pop the head only if it matches the
                // 'left' index that is about to move out of the window.

                if (minD.front() == left) {
                    minD.pop_front();
                }
                if (maxD.front() == left) {
                    maxD.pop_front();
                }

                // Move the left boundary to shrink the window
                left++;
            }

            // 3. Update Result: Count all valid subarrays ending at 'right'
            // The number of valid subarrays ending at 'right' is (right - left
            // + 1)
            res += right - left + 1;
        }
        return res;
    }
};

```
