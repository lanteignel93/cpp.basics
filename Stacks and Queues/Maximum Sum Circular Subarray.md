---
status: Done
difficulty: Medium
algo: Queues
group:
  - Stacks & Queues
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Queues_Problems]]

# Maximum Sum Circular Subarray
## Description 
Given a **circular integer array** `nums` of length `n`, return _the maximum possible sum of a non-empty **subarray** of_ `nums`.

A **circular array** means the end of the array connects to the beginning of the array. Formally, the next element of `nums[i]` is `nums[(i + 1) % n]` and the previous element of `nums[i]` is `nums[(i - 1 + n) % n]`.

A **subarray** may only include each element of the fixed buffer `nums` at most once. Formally, for a subarray `nums[i], nums[i + 1], ..., nums[j]`, there does not exist `i <= k1`, `k2 <= j` with `k1 % n == k2 % n`.

**Example 1:**

**Input:** nums = [1,-2,3,-2]
**Output:** 3
**Explanation:** Subarray [3] has maximum sum 3.

**Example 2:**

**Input:** nums = [5,-3,5]
**Output:** 10
**Explanation:** Subarray [5,5] has maximum sum 5 + 5 = 10.

**Example 3:**

**Input:** nums = [-3,-2,-3]
**Output:** -2
**Explanation:** Subarray [-2] has maximum sum -2.

**Constraints:**

- `n == nums.length`
- `1 <= n <= 3 * 104`
- `-3 * 104 <= nums[i] <= 3 * 104`
## Code 
```cpp
class Solution {
  public:
    int maxSubarraySumCircular(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int total_sum = 0;

        int max_so_far = nums[0];
        int current_max = nums[0];

        int min_so_far = nums[0];
        int current_min = nums[0];

        total_sum = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            int num = nums[i];

            // MAX Subarray Sum (Standard Kadane's)
            current_max = std::max(num, num + current_max);
            max_so_far = std::max(max_so_far, current_max);

            // MIN Subarray Sum (Inverse Kadane's)
            current_min = std::min(num, num + current_min);
            min_so_far = std::min(min_so_far, current_min);

            total_sum += num;
        }

        int max_non_wrap_sum = max_so_far;

        int max_wrap_sum = static_cast<int>((total_sum - min_so_far));

        if (total_sum == min_so_far) {
            return max_non_wrap_sum;
        }

        return std::max(max_non_wrap_sum, max_wrap_sum);
    }
};

```
