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

# Container with Most Water
## Description 
You are given an integer array heights where heights[i] represents the height of the ithith bar.
![[public.avif]]
You may choose any two bars to form a container. Return the maximum amount of water a container can store.

Example 1:

Input: height = [1,7,2,5,4,7,3,6]

Output: 36

Example 2:

Input: height = [2,2,2]

Output: 4

Constraints:

    2 <= height.length <= 1000
    0 <= height[i] <= 1000


## Code 
```cpp
class Solution {
public:
    int calculateArea(const std::vector<int>& height, int left_index, int right_index) {
        int minHeight = std::min(height[left_index], height[right_index]); 
        return (minHeight * (right_index - left_index)); 
    }
    int maxArea(vector<int>& height) {
        int left = 0; 
        int right = height.size() - 1; 
        int res = -1; 
        while (left < right) {
            res = std::max(res, calculateArea(height, left, right)); 
            if (height[left] < height[right]) {
                left++; 
            } else {
                right--; 
            }
        }
        return res; 
    }
};
```
