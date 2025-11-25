---
status: Done
difficulty: Medium
algo: Sliding Window
group:
  - Arrays
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Sliding_Window_Problems]]]

# Longest Repeating Character Replacement
## Description 
You are given a string `s` consisting of only uppercase English characters and an integer `k`. You can choose up to `k` characters of the string and replace them with any other uppercase English character.

After performing at most `k` replacements, return the length of the longest substring which contains only one distinct character.

**Example 1:**

```java
Input: s = "XYYX", k = 2

Output: 4
```

Explanation: Either replace the 'X's with 'Y's, or replace the 'Y's with 'X's.

**Example 2:**

```java
Input: s = "AAABABB", k = 1

Output: 5
```

**Constraints:**

- `1 <= s.length <= 1000`
- `0 <= k <= s.length`
## Code 
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0; 
        int left_ptr = 0; 

        for (int right_ptr = 0; right_ptr < static_cast<int>(s.length()); right_ptr++) {

            char target_char = s[left_ptr]; 
            int replacements_needed = 0;
      
            for (int i = left_ptr; i <= right_ptr; ++i) {
                 if (s[i] != target_char) {
                     replacements_needed++;
                 }
            }
            while (replacements_needed > k) {
                
                left_ptr++; 
                replacements_needed = 0;

                for (int i = left_ptr; i <= right_ptr; ++i) {
                     if (s[i] != target_char) {
                         replacements_needed++;
                     }
                }
            }

            res = std::max(res, right_ptr - left_ptr + 1); 
            
        }
        return res; 
    }
};
```
