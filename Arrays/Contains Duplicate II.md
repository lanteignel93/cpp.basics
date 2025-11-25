---
status: Done
difficulty: Easy
algo: Sliding Window
group:
  - Arrays
isProblem: true
stars: 2
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Sliding_Window_Problems]]]

# Contains Duplicate II
## Description 
You are given an integer array `nums` and an integer `k`, return `true` if there are **two distinct indices** `i` and `j` in the array such that `nums[i] == nums[j]` and `abs(i - j) <= k`, otherwise return `false`.

**Example 1:**

```java
Input: nums = [1,2,3,1], k = 3

Output: true
```

**Example 2:**

```java
Input: nums = [2,1,2], k = 1

Output: false
```

**Constraints:**

- `1 <= nums.length <= 100,000`
- `-1,000,000,000 <= nums[i] <= 1,000,000,000`
- `0 <= k <= 100,000`
## Code 
```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        std::unordered_map<int, int> seen; 

        for(int i = 0; i < nums.size(); i++){
            if(seen.contains(nums[i]) && std::abs(i - seen[nums[i]]) <= k){
                return true; 
            }
            seen[nums[i]] = i;
        }
        
        return false;
    }
};

```
