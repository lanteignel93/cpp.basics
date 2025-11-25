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

# Two Sum II
## Description 
Given an array of integers `numbers` that is sorted in **non-decreasing order**.

Return the indices (**1-indexed**) of two numbers, `[index1, index2]`, such that they add up to a given target number `target` and `index1 < index2`. Note that `index1` and `index2` cannot be equal, therefore you may not use the same element twice.

There will always be **exactly one valid solution**.

Your solution must use O(1)O(1) additional space.

**Example 1:**

```java
Input: numbers = [1,2,3,4], target = 3

Output: [1,2]
```

Explanation:  
The sum of 1 and 2 is 3. Since we are assuming a 1-indexed array, `index1` = 1, `index2` = 2. We return `[1, 2]`.

**Constraints:**

- `2 <= numbers.length <= 1000`
- `-1000 <= numbers[i] <= 1000`
- `-1000 <= target <= 1000`
## Code 
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::unordered_map<int, int> d; 

        for (int i = 0; i < numbers.size(); i++) {
            int complement = target - numbers[i]; 
            if (d.find(complement) != d.end()) {
                return {d[complement], i + 1}; 
            } 
            d[numbers[i]] = i + 1; 
        }
        return {0 , 0}; 
    }
};
```
