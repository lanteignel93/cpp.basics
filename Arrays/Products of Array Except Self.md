---
status: Done
difficulty: Medium
algo: Prefix Sums
group:
  - Arrays
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Two-Pointers_Problems]]

# Product of Array Except Self
## Description 
Given an integer array `nums`, return an array `output` where `output[i]` is the product of all the elements of `nums` except `nums[i]`.

Each product is **guaranteed** to fit in a **32-bit** integer.

Follow-up: Could you solve it in `O(n)` time without using the division operation?

**Example 1:**

```java
Input: nums = [1,2,4,6]

Output: [48,24,12,8]
```

**Example 2:**

```java
Input: nums = [-1,0,1,2,3]

Output: [0,-6,0,0,0]
```

**Constraints:**

- `2 <= nums.length <= 1000`
- `-20 <= nums[i] <= 20`
## Code 
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_count = 0; 
        int zero_idx = nums.size() + 1; 
        int total = 1; 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_count++; 
                zero_idx = i;  
            } else {
                total *= nums[i]; 
            }

        }

        if (zero_count > 1) {
            return std::vector<int>(nums.size(), 0); 
        }
        std::vector<int> res(nums.size(), 0); 
        if (zero_count == 1) {
            res[zero_idx] = total; 
        } else {
            for (int i = 0; i < nums.size(); i++) {
                res[i] = total / nums[i]; 
            }
        }
        return res; 
    }
};
```

Another solution using prefix and suffix
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pref(n);
        vector<int> suff(n);
        pref[0] = 1; 
        suff[n - 1] = 1; 

        for (int i = 1; i < n; i++) {
            int j = n - 1 - i; 
            pref[i] = pref[i-1] * nums[i-1];
            suff[j] = suff[j+1] * nums[j+1];
        }

        for (int i = 0; i < n; i++) {
            res[i] = pref[i] * suff[i]; 
        }
        return res; 
    }
};


```