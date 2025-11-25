---
status: Done
difficulty: Medium
algo: Two-Pointers
group:
  - Arrays
isProblem: true
stars: 2
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Two-Pointers_Problems]]

# Rotate Array
## Description 
You are given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

**Example 1:**

```java
Input: nums = [1,2,3,4,5,6,7,8], k = 4

Output: [5,6,7,8,1,2,3,4]
```

Explanation:  
rotate 1 steps to the right: [8,1,2,3,4,5,6,7]  
rotate 2 steps to the right: [7,8,1,2,3,4,5,6]  
rotate 3 steps to the right: [6,7,8,1,2,3,4,5]  
rotate 4 steps to the right: [5,6,7,8,1,2,3,4]

**Example 2:**

```java
Input: nums = [1000,2,4,-3], k = 2

Output: [4,-3,1000,2]
```

Explanation:  
rotate 1 steps to the right: [-3,1000,2,4]  
rotate 2 steps to the right: [4,-3,1000,2]

**Constraints:**

- `1 <= nums.length <= 100,000`
- `-(2^31) <= nums[i] <= ((2^31)-1)`
- `0 <= k <= 100,000`

**Follow up:** Could you do it in-place with O(1) extra space?
## Code 
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int rotated = 0; 
        int idx = 0; 
        int size = static_cast<int>(nums.size());
        
        if (size == 0 || k % size == 0) return;
        k %= size;

        std::vector<int> seen(size, 0); 


        while (rotated < size) {
            while (seen[idx] == 1) {
                idx++;
            }
            int prev_number = nums[idx]; 
            int current_pos = idx; 
            
            do {
                seen[current_pos] = 1; 

                // Calculate the destination index
                int next = (current_pos + k) % size;
                int next_number = nums[next]; 
                nums[next] = prev_number; 
                
                prev_number = next_number; 
                current_pos = next;

                rotated++; 
                
            } while (current_pos != idx); 
            
        }
    }
};
```
