---
status: Done
difficulty: Easy
algo: Prefix Sums
group:
  - Arrays
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Two-Pointers_Problems]]

# Find Pivot Index
## Description 
You are given an array of integers `nums`, calculate the **pivot index** of this array.

The **pivot index** is the index where the sum of all the numbers **strictly** to the left of the index is equal to the sum of all the numbers **strictly** to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the **leftmost pivot index**. If no such index exists, return `-1`.

**Example 1:**

```java
Input: nums = [1,7,3,6,5,6]

Output: 3
```

Explanation: Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11  
Right sum = nums[4] + nums[5] = 5 + 6 = 11

**Example 2:**

```java
Input: nums = [3,2,1]

Output: -1
```

**Example 3:**

```java
Input: nums = [2,1,-1]

Output: 0
```

Explanation: The pivot index is 0.  
Left sum = 0 (no elements to the left of index 0)  
`Right sum = nums[1] + nums[2] = 1 + -1 = 0`
## Code 
```cpp
class Solution {
  public:
    int pivotIndex(std::vector<int> &nums) {
        std::vector<int> prefix{0};
        int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; i++) {
            prefix.push_back(nums[i] + prefix[i]);
        }

        for (int i = 0; i < n; i++) {
            int leftSum = prefix[i];
            int rightSum = prefix[n] - prefix[i + 1];
            if (leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
};
```
