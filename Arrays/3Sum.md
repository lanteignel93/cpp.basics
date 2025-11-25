---
status: Done
difficulty: Medium
algo: Two-Pointers
group:
  - Arrays
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Two-Pointers_Problems]]

# 3Sum
## Description 
Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` where `nums[i] + nums[j] + nums[k] == 0`, and the indices `i`, `j` and `k` are all distinct.

The output should _not_ contain any duplicate triplets. You may return the output and the triplets in **any order**.

**Example 1:**

```java
Input: nums = [-1,0,1,2,-1,-4]

Output: [[-1,-1,2],[-1,0,1]]
```

Explanation:  
`nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.`  
`nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.`  
`nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.`  
The distinct triplets are `[-1,0,1]` and `[-1,-1,2]`.

**Example 2:**

```java
Input: nums = [0,1,1]

Output: []
```

Explanation: The only possible triplet does not sum up to 0.

**Example 3:**

```java
Input: nums = [0,0,0]

Output: [[0,0,0]]
```

Explanation: The only possible triplet sums up to 0.

**Constraints:**

- `3 <= nums.length <= 1000`
- `-10^5 <= nums[i] <= 10^5`
## Code 
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> res; 
        std::sort(nums.begin(), nums.end());

        int n = static_cast<int>(nums.size()); 

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;
            int j = i + 1; 
            if (i > 0 && (nums[i] == nums[i-1])) {
                continue; 
            } else {
                int k = n - 1; 
                while (j < k) {
                    int total = nums[i] + nums[j] + nums[k]; 

                    if (total == 0) {
                        res.push_back({nums[i], nums[j], nums[k]}); 
                        j++;
                        k--;
                    } else if (total > 0) {
                        k--; 
                    } else if (total < 0) {
                        j++; 
                    }
                    while ((nums[j] == nums[j - 1]) && (j < k)) {
                        j++;
                    }
                }
            }
        }
        return res;
    }
};
```
