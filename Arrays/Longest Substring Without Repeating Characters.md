---
status: Done
difficulty: Medium
algo: Sliding Window
group:
  - Arrays
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Sliding_Window_Problems]]]

# Longest Substring Without Repeating Characters
## Description 
Given a string `s`, find the _length of the longest substring_ without duplicate characters.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**

```java
Input: s = "zxyzxyz"

Output: 3
```

Explanation: The string "xyz" is the longest without duplicate characters.

**Example 2:**

```java
Input: s = "xxxx"

Output: 1
```

**Constraints:**

- `0 <= s.length <= 1000`
- `s` may consist of printable ASCII characters.
## Code 
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        std::vector<int> last_seen(256, -1); 
        int res = 1;
        int left_ptr = 0; 

        for (int right_ptr = 0; right_ptr < static_cast<int>(s.length()); ++right_ptr) {
            char current_char = s[right_ptr];

            if (last_seen[current_char] >= left_ptr) {
                left_ptr = last_seen[current_char] + 1;
            }
            
            last_seen[current_char] = right_ptr;
            res = std::max(res, right_ptr - left_ptr + 1);
        }

        return res;
    }
};
```
